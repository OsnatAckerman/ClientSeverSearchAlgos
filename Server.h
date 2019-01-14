//
// Created by shira on 1/12/19.
//

#ifndef UNTITLED4_SERVER_H
#define UNTITLED4_SERVER_H

#include "ClientHandle.h"

class Server{
    void open(int port, ClientHandle clientHandle);
    void stop();
};
#endif //UNTITLED4_SERVER_H
