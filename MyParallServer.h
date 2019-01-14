//
// Created by shira on 1/12/19.
//

#ifndef UNTITLED4_MYPARALLSERVER_H
#define UNTITLED4_MYPARALLSERVER_H


#include "Server.h"
struct arg_struct {
    int socket_args;
    ClientHandle c;
};
class MyParallServer : public Server{
    void open(int port, ClientHandle clientHandle);
    void stop();
};


#endif //UNTITLED4_MYPARALLSERVER_H
