//
// Created by ubuntu on 12/02/18.
//

#ifndef OREN_SIGNAL_H
#define OREN_SIGNAL_H

#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <wait.h>

#include "global_variables.h"
#include "path.h"

void pipeSignalHandler(int signum, siginfo_t *info, void *ptr);
//void serverSignalHandler(int signum, siginfo_t *info, void *ptr);
void consumerProducerSignalHandler(int signum, siginfo_t *info, void *ptr);
void catchSignal(void (*signalHandlerFunc)(int signum, siginfo_t *info, void *ptr), bool typeSignalHandler);
#endif //OREN_SIGNAL_H
