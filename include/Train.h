#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define LOCALIP "127.0.0.1"

class Train
{
public:
    int id;
    int sktDescriptor;
    struct MessageTrain *buffer;
    struct sockaddr_in addrcli;
    struct sockaddr_in addrServ;
    socklen_t adrlg;

    /// @brief Constructor: sets up the socket
    /// @param ip : ip of the server to connect
    /// @param port : port to connect
    Train(const char *ip, int port);

    /// @brief Sends a message to the server
    void sendMessage();
};