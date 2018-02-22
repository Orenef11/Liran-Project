//
// Created by ubuntu on 10/02/18.
//

#include "../Headers/consumner_and_producer.h"


void consumerProcess(SharedMemory *sharedMemoryFile) {
    unsigned int sleepTime = (unsigned int) ((random() % 5) + 1);
    pthread_mutex_lock(&sharedMemoryFile->mutex);
    #if DEBUG
        printf("Producer index in array %d, Consumer index in array %d\n",
               sharedMemoryFile->producerIdx, sharedMemoryFile->consumerIdx);
    #endif
    #if PRINT_QUESTIONS_ARR
        arrQuestionToString(sharedMemoryFile->questionArr, sharedMemoryFile->questionArrSize);
    #endif
//    if(PRINT_QUESTIONS_ARR)
//        arrQuestionToString(sharedMemoryFile->questionArr, sharedMemoryFile->questionArrSize);

    if (sharedMemoryFile->questionArr[sharedMemoryFile->consumerIdx].isFull) {
        solveQuestion(&sharedMemoryFile->questionArr[sharedMemoryFile->consumerIdx]);
        sharedMemoryFile->questionArr[sharedMemoryFile->consumerIdx++].isFull = false;
        sharedMemoryFile->consumerIdx %= sharedMemoryFile->questionArrSize;

    }
    printf("The consumer has been sleeping for %d seconds\n", sleepTime);
    pthread_mutex_unlock(&sharedMemoryFile->mutex);
    sleep(sleepTime);


}

void producerProcess(SharedMemory *sharedMemoryFile){
    unsigned int sleepTime = (unsigned int) ((random( ) % 5) + 1);
    pthread_mutex_lock(&sharedMemoryFile->mutex);

    if(!sharedMemoryFile->questionArr[sharedMemoryFile->producerIdx].isFull){
        createQuestion(&(sharedMemoryFile->questionArr[sharedMemoryFile->producerIdx++]), 0);
        printf("Create new question\n");
        sharedMemoryFile->producerIdx %= sharedMemoryFile->questionArrSize;
    }
    #if DEBUG
        printf("Producer index in array %d, Consumer index in array %d\n",
                   sharedMemoryFile->producerIdx, sharedMemoryFile->consumerIdx);
    #endif
    #if PRINT_QUESTIONS_ARR
        arrQuestionToString(sharedMemoryFile->questionArr, sharedMemoryFile->questionArrSize);
    #endif
    pthread_mutex_unlock(&sharedMemoryFile->mutex);
    printf("%s[%d]The producer has been sleeping for %d seconds\n", getFileName(__FILE__), __LINE__,sleepTime);
    sleep(sleepTime);
}

