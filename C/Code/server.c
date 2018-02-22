//
// Created by ubuntu on 12/02/18.
//

#include <errno.h>

#include "../Headers/server.h"


pid_t server(){
    struct sockaddr_in server, client;
    char *filesArr[] = {"Data/6.txt", "Data/2.txt", "Data/3.txt", "Data/4.txt", "Data/5.txt"};
    pid_t pythonPid;
    int sizeOfFiles, client_fd, server_fd, numOfbytes, filesSize;
    sizeOfFiles = sizeof(filesArr) /  sizeof(filesArr[0]);

    printf("The server has been created and is active for communication\n");

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Could not create socket\n");
        exit(EXIT_FAILURE);
    }
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(PORT);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) == -1)
    {
        fprintf(stderr, "%s[%d]SetSocketError:  %s\n", getFileName(__FILE__), __LINE__, strerror(errno));
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    if (bind(server_fd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        fprintf(stderr, "%s[%d]BindError: Change the port of server\n", getFileName(__FILE__), __LINE__);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    listen(server_fd, 1);
    memset(&client, 0, sizeof(client));
    if((client_fd = accept(server_fd, (struct sockaddr *) &client, (socklen_t *) &client)) == -1){
        fprintf(stderr, "%s[%d]Could not accept client\n", getFileName(__FILE__), __LINE__);
        close(server_fd);
        close(client_fd);
        exit(EXIT_FAILURE);

    }

    printf("The client connection to server.\n");
    printf("client send the pid\n");
    pythonPid = 0;
    numOfbytes= (int)recv(client_fd, &pythonPid, sizeof(pythonPid), 0);
    if(numOfbytes == -1 || numOfbytes == 0)
    {
        fprintf(stderr, "%s[%d]RecvError: %s (%d)\n", getFileName(__FILE__), __LINE__, strerror(errno), errno);
        exit(EXIT_FAILURE);
    }

    printf("The python pid its %d\n", pythonPid);
    printf("Send to python the size of files\n");
    if((send(client_fd, &sizeOfFiles, sizeof(sizeOfFiles), 0)) == -1) {
        fprintf(stderr, "%s[%d]SendError: %s (%d)\n", getFileName(__FILE__), __LINE__, strerror(errno), errno);
        exit(EXIT_FAILURE);
    }


    for(int i = 0; i < sizeOfFiles; i++) {
        filesSize = (int) strlen(filesArr[i]);
        send(client_fd, &filesSize, sizeof(filesSize), 0);
        send(client_fd, filesArr[i], strlen(filesArr[i]), 0);
    }
    printf("The server has been closed\n");
    close(client_fd);
    close(server_fd);

    return pythonPid;
}