//
// Created by ubuntu on 12/02/18.
//


#include "../Headers/my_signal.h"
#include "../Headers/global_variables.h"


void pipeSignalHandler(int signum, siginfo_t *info, void *ptr) {
    if(signum == SIGALRM){
        fprintf(stderr, "PipeSignal: pipe send '%s' signal\n", "SIGALRM");
    }
    if(signum == SIGPIPE){
        fprintf(stderr, "PipeSignal: The pipe broken\n");
    }
    pipeLoopFlag = false;
    write(STDERR_FILENO, PIPE_SIGNAL_MESSAGE, sizeof(PIPE_SIGNAL_MESSAGE));
}
//void serverSignalHandler(int signum, siginfo_t *info, void *ptr){
//    write(STDERR_FILENO, SERVER_SIGNAL_MESSAGE, sizeof(SERVER_SIGNAL_MESSAGE));
//}

void consumerProducerSignalHandler(int signum, siginfo_t *info, void *ptr){
    int pid;
    int stat;
    pid=waitpid(-1,&stat, WNOHANG);
    while((pid=waitpid(-1,&stat, WNOHANG)) > 0) {
        write(STDERR_FILENO, CONSUMER_PRODUCER_SIGNAL_MESSAGE, sizeof(CONSUMER_PRODUCER_SIGNAL_MESSAGE));
        printf("child %d terminated\n", pid);
    }

}

void catchSignal(void (*signalHandlerFunc)(int signum, siginfo_t *info, void *ptr), bool pipeSignal){
    static struct sigaction _sigact;

    memset(&_sigact, 0, sizeof(_sigact));
    _sigact.sa_sigaction = signalHandlerFunc;
    _sigact.sa_flags = SA_SIGINFO;

    sigaction(SIGALRM, &_sigact, NULL);     //timeout
    sigaction(SIGTSTP, &_sigact, NULL);      //for Ctrl+Z
    sigaction(SIGINT, &_sigact, NULL);      //for Ctrl+c
    if(pipeSignal) {
        sigaction(SIGPIPE, &_sigact, NULL);      //for SIGPIPE
    }
}