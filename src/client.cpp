#include "client_socket.h"
#include "system.h"
#include <cstdio>
using namespace breeze::socket;

int main()
{
    auto sys = Singleton<System>::Instance();

    string root_path = sys -> get_root_path();
    string client_log_path = root_path + "log/client.log";
    Singleton<Logger>::Instance() -> open(client_log_path);

    Client_socket client("127.0.0.1", 8080);
    
    char data[] = "hello Server";
    client.send(data, sizeof(data));

    char buffer[1024] = {0};
    client.recv(buffer, sizeof(buffer));
    printf("recv: %s\n", buffer); 

    client.close();
    return 0;
}