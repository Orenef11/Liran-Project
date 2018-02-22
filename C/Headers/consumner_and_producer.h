//
// Created by ubuntu on 10/02/18.
//

#ifndef LIRANPROJECT_OREN_CONSUMNER_AND_PRODUCER_H
#define LIRANPROJECT_OREN_CONSUMNER_AND_PRODUCER_H
#include "shared_memory.h"
#include "global_variables.h"
#include "path.h"

void consumerProcess(SharedMemory *sharedMemoryFile);
void producerProcess(SharedMemory *sharedMemoryFile);
#endif //LIRANPROJECT_OREN_CONSUMNER_AND_PRODUCER_H
