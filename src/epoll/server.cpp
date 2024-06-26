#include "Logger.h"
#include "socket_handler.h"
#include "task_dispatcher.h"
#include "iniFile.h"

using namespace breeze::thread;
using namespace breeze::socket;

const string config_file_path = "/home/breeze/exercise/web/config/config.ini";

int main()
{
    auto ini = Singleton<IniFile>::Instance();
    ini -> load(config_file_path);
    string ip = ini -> get("server", "ip");
    int port = ini -> get("server", "port");
    int thread_num = ini -> get("server", "threads");
    int max_conns = ini -> get("server", "max_conns");
    int wait_time = ini -> get("server", "wait_time");
    int log_level = ini -> get("server", "log_level");

    auto logger = Singleton<Logger>::Instance();
    logger -> open("/home/breeze/exercise/web/log/server.log");
    logger -> setConsole(false);
    logger -> setLevel(static_cast<Logger::Level>(log_level));

    auto dispatcher = Singleton<TaskDispatcher>::Instance();
    dispatcher -> init(thread_num);

    auto handle = Singleton<SocketHandler>::Instance();
    handle -> listen(ip, port);
    handle -> handle(max_conns, wait_time);

    return 0;
}