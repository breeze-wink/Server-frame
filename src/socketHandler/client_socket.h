#include "socket.h"
using namespace breeze::socket;

class Client_socket : public Socket
{
public:
    Client_socket() = delete;
    Client_socket(const string& ip, int port);
    ~Client_socket() = default;
};