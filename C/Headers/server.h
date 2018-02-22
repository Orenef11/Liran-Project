//
// Created by ubuntu on 12/02/18.
//

#ifndef OREN_SERVER_H
#define OREN_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "global_variables.h"
#include "my_signal.h"

pid_t server();
#endif //OREN_SERVER_H
