//h
// Created by ubuntu on 07/02/18.
//

#ifndef LIRANPROJECT_OREN_ARGUMENTS_PARSER_H
#define LIRANPROJECT_OREN_ARGUMENTS_PARSER_H
#include <stdlib.h>
#include <malloc.h>
#include <getopt.h>
#include "global_variables.h"
#include "path.h"

typedef struct args{
    int producersSize;
    int consumersSize;
    int questionArrSize;
    unsigned int timeout;
}Args;

Args* configParser(int argc,  char *argv[], int questionArrSize);
#endif //LIRANPROJECT_OREN_ARGUMENTS_PARSER_H
