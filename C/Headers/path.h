//
// Created by ubuntu on 12/02/18.
//

#ifndef OREN_PATH_H
#define OREN_PATH_H

#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdlib.h>

#include "global_variables.h"

char *getcwd(char *buf, size_t size);
void pathJoin(char *newFilePath, const char *filePath, const char *filePath2, char separator);
void joinTwoString(char *newFilePath, const char *filePath, const char *filePath2);
void getRelativeFolder(char *filePath, char const *extension);
char* getFileName(char *file);
#endif //OREN_PATH_H
