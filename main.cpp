#include <iostream>
namespace server_side{
    class Server{
    public:
        virtual void open(int port, ClientHendler c) = 0;
        virtual void stop() = 0;
    };
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}