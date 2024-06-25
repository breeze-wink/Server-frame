// #include <iostream>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <unistd.h>
// #include <cstring>
// #include <string>
// #include "Socket/socket.h"
#include "client_socket.h"
#include <cstdio>
using namespace breeze::socket;

int main()
{
    Singleton<Logger>::Instance() -> open("../client.log");
    // Socket client;
    // client.connect("127.0.0.1", 8080);
    Client_socket client("127.0.0.1", 8080);
    char data[] = "hello Server";
    client.send(data, sizeof(data));

    char buffer[1024] = {0};
    client.recv(buffer, sizeof(buffer));
    printf("recv: %s\n", buffer); 

    client.close();
}