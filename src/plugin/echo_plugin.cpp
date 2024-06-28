#include "echo_plugin.h"
#include "Logger.h"
#include "plugin.h"
#include "system.h"

using namespace breeze::plugin;
using namespace breeze::utility;


EchoPlugin::EchoPlugin()
{
    auto sys = Singleton<System>::Instance();
    const string root_path = sys -> get_root_path();
    auto logger = Singleton<Logger>::Instance();
    logger -> open(root_path + "log/echo_plugin.log");
    logger -> setConsole(false);
}
EchoPlugin::~EchoPlugin()
{

}

bool EchoPlugin::run()
{
    log_info("echo plugin running!");
    return true;
}

DEFINE_PLUGIN(EchoPlugin)