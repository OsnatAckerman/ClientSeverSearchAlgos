//
// Created by shira on 1/12/19.
//

#ifndef UNTITLED4_SERVER_H
#define UNTITLED4_SERVER_H

#include "MyMatrixClientHandler.h"

class Server{
    void open(int port, MyMatrixClientHandler clientHandle);
    void stop();
};
#endif //UNTITLED4_SERVER_H
