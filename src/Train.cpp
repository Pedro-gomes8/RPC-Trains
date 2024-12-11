#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "../include/Train.h"
#include "../include/types.h"

Train::Train(const char *ip, int port)
{
    // Client Setup
    this->sktDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
    this->addrcli.sin_family = AF_INET;

    this->addrcli.sin_addr.s_addr = inet_addr(ip);

    this->addrcli.sin_port = 0; // Let the os decide which port is available

    if (bind(this->sktDescriptor, (const struct sockaddr *)&addrcli, sizeof(addrcli)) < 0)
    {
        std::cout << "Failed to bind socket\n";
    }
    this->adrlg = sizeof(struct sockaddr_in);

    // Server setup
    this->addrServ.sin_port = htons(port);
    this->addrServ.sin_addr.s_addr = inet_addr(LOCALIP);
}

void Train::sendMessage()
{
    while (1)
    {
        /*
        Example of a message to test if the communication works.

        Train will continously send a message (struct defined in include/types.h) to the server and the server will print out, in this case, the code received
        */

        struct TrainData data = {-1, 0, -1};
        this->buffer->code = 201; // example to test
        this->buffer->data = data;
        // std::cout << "Sending Client message\n";
        ssize_t bytesreceived = sendto(this->sktDescriptor, this->buffer, sizeof(buffer) + 1, 0, (const struct sockaddr *)&addrServ, sizeof(struct sockaddr_in));
    }
}
