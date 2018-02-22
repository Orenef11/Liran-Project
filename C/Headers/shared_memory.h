//
// Created by ubuntu on 06/02/18.
//

#ifndef LIRANPROJECT_OREN_SEMAPHORE_SHARED_MEMORY_H
#define LIRANPROJECT_OREN_SEMAPHORE_SHARED_MEMORY_H

#include <semaphore.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <zconf.h>
#include <fcntl.h>
#include <pthread.h>

#include "question.h"
#include "path.h"

typedef struct shared_memory {
    Question questionArr[10];
    pthread_mutex_t mutex;
    int consumerIdx;
    int producerIdx;
    int questionArrSize;
    int sharedMemoryFd;
}SharedMemory;

void createSharedMemory(SharedMemory **sharedMemoryFile, int questionArrSize, const char * shm_mem);
void deleteSharedMemory(SharedMemory *sharedMemoryFile, const char *sharedMemoryName);

#endif //LIRANPROJECT_OREN_SEMAPHORE_SHARED_MEMORY_H
