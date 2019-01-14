//
// Created by shira on 1/12/19.
//

#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <strings.h>
#include <unistd.h>
#include "MyParallServer.h"
void MyParallServer:: open(int port, ClientHandle clientHandle){
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    while(true){
        listen(sockfd,5);
        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        close(sockfd);

        auto args = new arg_struct();
        args->socket_args = newsockfd;
        args->c = clientHandle;
         pthread_t pthread;
        pthread_create(pthread, nullptr, thread_func, args);
    }
}
