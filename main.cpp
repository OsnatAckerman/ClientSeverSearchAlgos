#include <iostream>
#include "ClientHandler.h"

namespace server_side{
    class Server{
    public:
        virtual void open(int port, ClientHandler c) = 0;
        virtual void stop() = 0;
    };
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}