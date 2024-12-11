#pragma once

#include <string>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <vector>
#include "types.h"

#define LOCALIP "127.0.0.1"

class Server
{
public:
    int sktDescriptor;
    int idxLastTrain = -1;
    socklen_t adrlg;
    struct MessageTrain *buffer;
    struct sockaddr_in addrlect;
    struct sockaddr_in addrcli;
    std::vector<TrainData> dataTrain;

    // Constructor, it opens up socket connection
    Server(int port);

    /// @brief Treats the message received by the trains
    void receiveMessage();

    /// @brief Sends the response to a train's demmand
    void sendMessage();

    /// @brief  Manipulates the dataStructure and sets up the response structure to be sent by the previous method
    void treatRequest();

    /// @brief Tries to insert a train
    /// @param *response : Configures the data of the response to be sent
    void insertTrain(struct ServerResponse *response);

    // Functions below are yet to be implemented for debugging purposes
    void sendTrainInfo();
    void sendUnauthorized();
};