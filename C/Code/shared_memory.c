//
// Created by ubuntu on 07/02/18.
//

#include "../Headers/shared_memory.h"


void createSharedMemory(SharedMemory **sharedMemoryObj, int questionArrSize, const char * sharedMemoryName){

    long sharedMemorySize = sizeof(SharedMemory) + sizeof(Question) * questionArrSize;
    int sharedMemoryFd;
    /* Create a new memory object */

    if ((sharedMemoryFd= shm_open(sharedMemoryName, O_RDWR | O_CREAT | O_TRUNC, 0660)) == -1) {
        fprintf(stderr, "%s[%d]SharedMemoryError:There was no possibility to open a shared memory\n",
                getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    if (ftruncate(sharedMemoryFd, sizeof(SharedMemory)) == -1) {
        fprintf(stderr, "%s[%d]SharedMemoryError: ftruncate failed\n",
                getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    /* Map memory object */
    *sharedMemoryObj = mmap(0, sizeof(SharedMemory), PROT_READ | PROT_WRITE, MAP_SHARED, sharedMemoryFd, 0);
    if (*sharedMemoryObj == MAP_FAILED) {
        fprintf(stderr, "%s[%d]SharedMemoryError: mmap failed\n",
                getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    (*sharedMemoryObj)->sharedMemoryFd = sharedMemoryFd;
    (*sharedMemoryObj)->questionArrSize = questionArrSize;
    (*sharedMemoryObj)->consumerIdx = (*sharedMemoryObj)->consumerIdx = 0;

}

void deleteSharedMemory(SharedMemory *sharedMemoryFile, const char *sharedMemoryName){
    int fd = sharedMemoryFile->sharedMemoryFd;
    if(munmap(sharedMemoryFile, sizeof(SharedMemory)) == - 1){
        fprintf(stderr, "%s[%d]SharedMemoryError: munmap failed\n", getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    close(fd);
    shm_unlink(sharedMemoryName);
}