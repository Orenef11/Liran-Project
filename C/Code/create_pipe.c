//
// Created by ubuntu on 12/02/18.
//
#include "../Headers/create_pipe.h"

bool pipeLoopFlag = true;

void getQuestionFromString(SharedMemory* sharedMemoryObj, const char *questionString){
    double num = -1, num2 = -1;
    int op = -1;
    char *pEndFirstNum, *pEndSecondNum;

    num = strtof(questionString, &pEndFirstNum);
    num2 = strtof(pEndFirstNum, &pEndSecondNum);
    op = atoi(pEndSecondNum);
    if(op == NULL)
        op = -1;
    do{
        pthread_mutex_lock(&sharedMemoryObj->mutex);
        if(sharedMemoryObj->questionArr[sharedMemoryObj->producerIdx].isFull){
            pthread_mutex_unlock(&sharedMemoryObj->mutex);
            sleep(3);
        }
        else{
            createQuestion(&(sharedMemoryObj->questionArr[sharedMemoryObj->producerIdx++]), 0);
            printf("Create question from Python\n");
            if(num == -1 || num2 == -1 || op == -1 || op < 0 || op > sizeof(enum oper)){
                createQuestion(&(sharedMemoryObj->questionArr[sharedMemoryObj->producerIdx++]), 3, 0, 0, 0);
            }
            else{
                createQuestion(&(sharedMemoryObj->questionArr[sharedMemoryObj->producerIdx++]), 3, num, num2, op);
            }
            sharedMemoryObj->producerIdx %= sharedMemoryObj->questionArrSize;
            pthread_mutex_unlock(&sharedMemoryObj->mutex);
            break;
        }

    }while(sharedMemoryObj->questionArr[sharedMemoryObj->producerIdx].isFull);
}

void createPipe(SharedMemory* sharedMemoryObj, char const *pythonFileName, unsigned int timeout){
    alarm(timeout);
    catchSignal(pipeSignalHandler, true);
    FILE *fp = NULL;
    char *pythonFullPath;
    char buffer[PIPE_BUFFER] = {0};
    char folderPath[FILE_PATH_BUFFER] = {0};
    char python_path[FILE_PATH_BUFFER] = {0};
    pid_t python_pid;
    int bufferIdx;
    char chr;

    if (getcwd(folderPath, sizeof(folderPath)) != NULL)
        fprintf(stdout, "%s[%d]: Current working dir is %s\n", getFileName(__FILE__), __LINE__, folderPath);
    else{
        fprintf(stderr, "%s[%d]: Unable to find folder path\n", getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    getRelativeFolder(folderPath, "cmake-build-debug");


    pathJoin(python_path, folderPath, pythonFileName, DIR_SEPARATOR);

    pythonFullPath = malloc(strlen("python2 ") + strlen(python_path) + 1);//+1 for the null-terminator

    if(pythonFullPath == NULL) {
        fprintf(stderr, "%s[%d]MallocError: memory not allocated\n", getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    if( access(python_path, F_OK ) == -1 ){
        fprintf(stderr, "\n%s[%d]FileNotExistError: The file does not exist in following '%s' path\n",
                getFileName(__FILE__), __LINE__, python_path);
        printf("%d\n", EXIT_FAILURE);
        exit(EXIT_FAILURE);
    }
    joinTwoString(pythonFullPath, "python2 ", python_path);
    fp = popen(pythonFullPath, "r");
    if (fp == NULL){
        fprintf(stderr, "%s[%d]FileError:Can not open %s\n", getFileName(__FILE__), __LINE__,
                getFileName(pythonFullPath));
        exit(EXIT_FAILURE);
    }
    python_pid = server();

    bufferIdx = 0;
    while(pipeLoopFlag) {
        chr = (char) getc(fp);
        while (chr != '\n' && chr != '\0' && chr != EOF) {
            buffer[bufferIdx++] = chr;
            chr = (char) getc(fp);
            if(bufferIdx > PIPE_BUFFER){
                break;
            }
        }

        buffer[bufferIdx] = '\0';
        printf("idx %d\n", bufferIdx);
        if(chr != EOF && bufferIdx > 14) {
            printf("Question from file: %s\n", buffer);
            getQuestionFromString(sharedMemoryObj, buffer);
        }
        bufferIdx = 0;

        #if PRINT_PIPE_DEBUG
            printf("%s[%d]: Debug mode\n", getFileName(__FILE__), __LINE__);
            arrQuestionToString(sharedMemoryObj->questionArr, sharedMemoryObj->questionArrSize);
        #endif
    }
    printf("PIPE timeout!\n");
    kill(python_pid, SIGKILL);
    sleep(3);
    free(pythonFullPath);
}
