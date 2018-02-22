//
// Created by ubuntu on 12/02/18.
//

#ifndef OREN_DEFINES_H
#define OREN_DEFINES_H

#include <stdbool.h>
#define PIPE_BUFFER 256
#if defined(WIN32)
    #define DIR_SEPARATOR '\\'
#else
    #define DIR_SEPARATOR '/'
#endif
#define FILE_PATH_BUFFER 256
#define CONSUMER_PRODUCER_SIGNAL_MESSAGE "Consumer & Producer signal received.\n"
#define PIPE_SIGNAL_MESSAGE "PIPE signal received.\n"

#define TIMEOUT 30
#define BUFFER_SIZE 100
#define PORT 1234
#define ARGUMENTS_SIZE 7
#define DEBUG false
#define QUESTION_ARR_SIZE 10
#define PRINT_QUESTIONS_ARR false
#define PRINT_PIPE_DEBUG false


extern bool pipeLoopFlag;



#endif //OREN_DEFINES_H
