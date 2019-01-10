//
// Created by osnat on 1/6/19.
//

#ifndef UNTITLED4_MYSERIALSERVER_H
#define UNTITLED4_MYSERIALSERVER_H

#include "ClientHandler.h"

namespace server_side{
    class Server{
    public:
        virtual void open(int port, ClientHandler c) = 0;
        virtual void stop() = 0;
    };
}

class MySerialServer : server_side::Server{
    void open(int port, ClientHandler c) override;
    void stop() override;

};


#endif //UNTITLED4_MYSERIALSERVER_H
