//
// Created by ubuntu on 12/02/18.
//

#include "../Headers/path.h"


void pathJoin(char *newFilePath, const char *filePath, const char *filePath2, char separator){
    const size_t len1 = strlen(filePath);
    const size_t len2 = strlen(filePath2);

    memcpy(newFilePath, filePath, len1);
    newFilePath[len1] = separator;
    memcpy(newFilePath + len1 + 1, filePath2, len2 + 1);//+1 to copy the null-terminator
}

void joinTwoString(char *newFilePath, const char *filePath, const char *filePath2) {
    const size_t len1 = strlen(filePath);
    const size_t len2 = strlen(filePath2);

    memcpy(newFilePath, filePath, len1);
    memcpy(newFilePath + len1, filePath2, len2+1);//+1 to copy the null-terminator
}

void getRelativeFolder(char *filePath, char const *extension) {
    size_t extensionLen = strlen(extension);
    size_t filePathLen = strlen(filePath);
    size_t endOfString;
    for(int i = 1; i <= extensionLen; i++){
        if(extension[extensionLen - i] != filePath[filePathLen - i]){
            return;
        }
    }

    endOfString = ((filePathLen - extensionLen) > 0) ? filePathLen - extensionLen - 1 : filePathLen - extensionLen;
    filePath[endOfString] = '\0';
}

char* getFileName(char *file){

    char* ptr = file,c;
    int file_name_loc =0,i=0;
    while((c=*ptr)) {
        if(c == DIR_SEPARATOR) {
            file_name_loc = i + 1;
        }
        ptr++;
        i++;
    }
    return file + file_name_loc;
}

