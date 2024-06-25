#pragma once
#include "socket.h"

using namespace breeze::socket;

class Serversocket : public Socket
{
public:
    Serversocket() = delete;
    Serversocket(const string& ip, int port);
    ~Serversocket() = default;
};
 