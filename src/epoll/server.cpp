#include "socket_handler.h"

using namespace breeze::socket;

int main()
{
    Singleton<Logger>::Instance() -> open("/home/breeze/exercise/web/log/server.log");

    auto handle = Singleton<SocketHandler>::Instance();
    handle -> listen("127.0.0.1", 8080);
    handle -> handle(1024, -1);

    return 0;
}