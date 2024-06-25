#include "server_socket.h"
using namespace breeze::socket;

Serversocket::Serversocket(const string& ip, int port):Socket()
{   
    //set_non_blocking();
    // set_recv_buffer(10 * 1024);
    // set_send_buffer(10 * 1024);
    // set_linger(true, 0);
    // set_keepalive();
    // set_reuse_addr();
    bind(ip, port);
    listen(1024);
}