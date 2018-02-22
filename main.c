#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

#include "C/Headers/argumentsParser.h"
#include "C/Headers/question.h"
#include "C/Headers/shared_memory.h"
#include "C/Headers/consumner_and_producer.h"
#include "C/Headers/global_variables.h"
#include "C/Headers/my_signal.h"
#include "C/Headers/create_pipe.h"

pid_t *pidsArr;

void freeAllAllocated(SharedMemory *sharedMemoryObj, Args *args, const char *sharedMemoryName);

void createProcesses(SharedMemory* sharedMemoryObj, void (func)(SharedMemory* sharedMemory),
                      int numOfProcesses, int pidsArrIdx, unsigned int timeout);

void createPipeProcess(SharedMemory* sharedMemoryObj, char const *pythonFileName, unsigned int timeout, int pidIdx,
                       void (func)(SharedMemory*, char const*, unsigned int));

void mainSignalHandler(int signum, siginfo_t *info, void *ptr);

void killAllProcessChildsAfterSignal(int numOfProcess);

int main(int argc, char *argv[]) {
    SharedMemory *sharedMemoryObj = NULL;
    Args *args = NULL;
    const char *sharedMemoryName = "/shared_memory";

    catchSignal(mainSignalHandler, false);

    // Initialize the seed value to get random numbers
    srand((unsigned int) time(NULL));

    args = configParser(argc, argv, QUESTION_ARR_SIZE);

    pidsArr = (pid_t*) malloc(sizeof(pid_t) * (args->producersSize + args->consumersSize + 1));
    createSharedMemory(&sharedMemoryObj, args->questionArrSize, sharedMemoryName);


//    createProcesses(sharedMemoryObj, producerProcess, args->producersSize, 0, args->timeout);
    createProcesses(sharedMemoryObj, consumerProcess, args->consumersSize, args->producersSize, args->timeout);
    createPipeProcess(sharedMemoryObj, "Python/run.py", 50, args->producersSize + args->consumersSize,
                      createPipe);

    killAllProcessChildsAfterSignal(args->consumersSize + args->producersSize + 1);

    freeAllAllocated(sharedMemoryObj, args, sharedMemoryName);
    return 0;
}

void freeAllAllocated(SharedMemory *sharedMemoryObj, Args *args, const char *sharedMemoryName){
    free(args);
    free(pidsArr);
    deleteSharedMemory(sharedMemoryObj, sharedMemoryName);
    printf("All assigned memory allocations have been successfully released\n");
}

void createProcesses(SharedMemory* sharedMemoryObj, void (func)(SharedMemory* sharedMemory),
                     int numOfProcesses, int pidsArrIdx, unsigned int timeout) {
    for (int i = pidsArrIdx; i < numOfProcesses + pidsArrIdx; i++) {
        pidsArr[i] = fork();
        if (pidsArr[i] == -1) {
            fprintf(stderr, "ForkError: Could not create new process\n");
            exit(EXIT_FAILURE);
        } else if (pidsArr[i] == 0) {
            alarm(timeout);
            #if DEBUG
                printf("Process pid %d\n", getpid());
            #endif


            while(1) {
                func(sharedMemoryObj);
            }
        }

    }
}

void createPipeProcess(SharedMemory* sharedMemoryObj, char const *pythonFileName, unsigned int timeout, int pidIdx,
                         void (func)(SharedMemory*, char const*, unsigned int)) {
    pidsArr[pidIdx] = fork();
    if (pidsArr[pidIdx] == -1) {
        fprintf(stderr, "ForkError: Could not create new process\n");
        exit(EXIT_FAILURE);
    } else if (pidsArr[pidIdx] == 0) {
//        alarm(timeout);
        #if DEBUG
                printf("Process pid %d\n", getpid());
        #endif
        while (1) {
            func(sharedMemoryObj, pythonFileName, timeout);
        }
        exit(0);
    }

}



void mainSignalHandler(int signum, siginfo_t *info, void *ptr) {
    #if DEBUG
        printf("%s: Kill process pid %d, %d\n", __FUNCTION__, signum, getpid());
    #endif
    if (signum == SIGALRM) {
        kill(getpid(), SIGKILL);
    }
}




void killAllProcessChildsAfterSignal(int numOfProcess) {
    int numOfProcessKilled = 0, status;
    while (numOfProcess != numOfProcessKilled) {
        for (int j = 0; j < numOfProcess; j++) {
            if (waitpid(pidsArr[j], &status, 0) > 0) {
                printf("%s: Kill child %d\n", __FUNCTION__, pidsArr[j]);
                numOfProcessKilled++;
            }
        }
        #if DEBUG
                printf("***************************************************************\n");
                printf("Debug mode: %s\t%s\t%d\n", __FUNCTION__, __FILE__, __LINE__);
                printf("Wait until all processes (producers and consumers) are finished\n");
                printf("Sleeping for 5 secs\n");
                printf("Number of process was killed %d\n", numOfProcessKilled);
                printf("***************************************************************\n");
        #endif
        sleep(5);
    }
}

