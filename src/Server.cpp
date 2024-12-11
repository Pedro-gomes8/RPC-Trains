#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "../include/Server.h"

Server::Server(int port)
{
    // Setup socket
    this->sktDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
    this->addrlect.sin_family = AF_INET;
    this->addrlect.sin_addr.s_addr = INADDR_ANY; // loopback
    this->addrlect.sin_port = htons(port);

    if (bind(this->sktDescriptor, (const struct sockaddr *)&this->addrlect, sizeof(this->addrlect)) == -1)
    {
        std::cout << "Failed to bind socket\n";
    }
    this->adrlg = sizeof(struct sockaddr_in);
}

void Server::treatRequest()
{
    struct ServerResponse response;
    switch (this->buffer->code)
    {

    case 101:
        Server::insertTrain(&response);

        break;

    case 102:
        break;
    case 103:
        break;
    case 104:
        break;
    }
}

void Server::insertTrain(struct ServerResponse *response)
{

    if (this->idxLastTrain < 0) // First train case
    {
        this->idxLastTrain = 0;
        response->traindata.id = 0;
        response->traindata.EOA = 100;
        response->traindata.trainLoc = 1;
        response->ack = 201;
    }
}

void Server::receiveMessage()
{
    while (1)
    {
        std::cout << "Server Listening\n";
        ssize_t bytesreceived = recvfrom(this->sktDescriptor, this->buffer, 1024 + 1, 0, (struct sockaddr *)&addrcli, &adrlg);

        std::cout << "Message Received. Code: " << this->buffer->code << '\n';

        Server::treatRequest();
    }
}
