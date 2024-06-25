#include "client_socket.h"
using namespace breeze::socket;

Client_socket::Client_socket(const string& ip, int port) : Socket()
{
    connect(ip, port);
}