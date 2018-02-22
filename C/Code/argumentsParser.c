//
// Created by ubuntu on 07/02/18.
//

#include <errno.h>
#include "../Headers/argumentsParser.h"

Args* configParser(int argc,  char *argv[],  int questionArrSize){
    if(argc != ARGUMENTS_SIZE){
        fprintf(stderr, "%s[%d]ArgumentsError: please enter the arguments in following form "
                "-p <numberOfProducers> -c <numberOfConsumers> -t <timeAppRunning>\n", getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    Args *args = (Args*)calloc(sizeof(Args), 1);
    args->questionArrSize = questionArrSize;
    int option;

    while((option = getopt(argc, argv,"c:p:a:t:")) != -1){
        switch(option){
            case 'c':
                args->consumersSize = atoi(optarg);
                break;
            case 'p':
                args->producersSize = atoi(optarg);
                break;
            case 't':
                args->timeout = (unsigned int) atoi(optarg);
                break;
            case '?':
            default:
                fprintf(stderr, "%s[%d]ArgumentsError: please enter the arguments in following form -p <numberOfProduc"
                        "ers> -c <numberOfConsumers> -t <timeAppRunning>\n", getFileName(__FILE__), __LINE__);
                exit(EXIT_FAILURE);
        }
    }

    if(args->consumersSize < 0 || args->producersSize < 0 || args->timeout < 1){
        fprintf(stderr, "%s[%d]ArgumentsValueError: You must give positive number!\n", getFileName(__FILE__), __LINE__);
        exit(EXIT_FAILURE);
    }
    return args;
}
