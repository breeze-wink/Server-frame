#include "socket_handler.h"
#include "task_dispatcher.h"

using namespace breeze::thread;
using namespace breeze::socket;

int main()
{
    Singleton<Logger>::Instance() -> open("/home/breeze/exercise/web/log/server.log");

    auto dispatcher = Singleton<TaskDispatcher>::Instance();
    dispatcher -> init(16);
    
    auto handle = Singleton<SocketHandler>::Instance();
    handle -> listen("127.0.0.1", 8080);
    handle -> handle(1024, -1);

    return 0;
}