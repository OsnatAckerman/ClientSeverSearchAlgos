//
// Created by shira on 1/12/19.
//

#ifndef UNTITLED4_MYPARALLSERVER_H
#define UNTITLED4_MYPARALLSERVER_H
#include "Server.h"
#include <iostream>
#include <sys/types.h>
#include <algorithm>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <netinet/in.h>
using namespace std;
struct arg_struct {
    int new_sock;
    ClientHandle* clientHandle;
};
class MyParallelServer : public Server{
    int port;
    ClientHandle* clientHandler;
    vector<pthread_t> victor;
    int server_fd;
public:
    void open(int port, ClientHandle* clientHandler) override;

    void stop() override;

};


#endif //UNTITLED4_MYPARALLSERVER_H
