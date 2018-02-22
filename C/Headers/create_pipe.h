//
// Created by ubuntu on 12/02/18.
//


#include <stdio.h>
#include <stdlib.h>

#include "path.h"
#include "global_variables.h"
#include "my_signal.h"
#include "server.h"
#include "shared_memory.h"
#include "global_variables.h"
#include "my_signal.h"
#include "server.h"

#ifndef OREN_CREATE_PIPE_H
#define OREN_CREATE_PIPE_H

void getQuestionFromString(SharedMemory* sharedMemoryObj, const char *questionString);
void createPipe(SharedMemory* sharedMemoryObj, char const *pythonFileName, unsigned int timeout);

#endif //OREN_CREATE_PIPE_H
