#include <iostream>
#include "SFML/Network.hpp"
#include <string>

using namespace sf;

int main()
{
    TcpListener server;
    server.listen(55001, IpAddress::LocalHost);

    while (true) {
        TcpSocket client;
        Packet packet;
        char buffer[1000];
        size_t size = sizeof(buffer);
        size_t len;

        if (server.accept(client) == Socket::Done) {
            printf("New connection received from: %s\n", client.getRemoteAddress().toString().c_str());

            client.receive(buffer, size, len);

            for (int i = 0; i < len; ++i) {
                std::cout << buffer[i];
            }
            std::cout << '\n';
        }
    }
}