/*
AUTHOR: Pedro GOMES

install executable: $ make

usage:

$ ./bin/main <ip> <port>

Progress: So far, communication works. You can run ./main <ip> <port> to verify. The data structure of messages and the vector to store train data in the server is also set up. you can view those at Server.h (include folder) and their implementation at Server.cpp (src folder). The structure of messages is being defined by types.h. Both train(s) and the server will use those structures to communicate.

Left to implement: other messages: so far, I only treat the message to insert a new train, but it is yet unfinished. The switch case structure to handle the different request based on the code is already set. Acknowledge handling: the train must act accordingly to the server's response.

OBS: This code launches both server and a train for testing purposes. If you wish to test the server, look at the comments below

*/

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/Server.h"
#include "../include/Train.h"

#define LOCALIP "127.0.0.1"

int main(int argc, char *argv[])
{
    int port = 7000;
    const char *ip = LOCALIP;
    if (argc == 3)
    {
        port = atoi(argv[2]);
        ip = argv[1];
    }
    Server server(port);

    Train train1(ip, port);

    int pid;

    /*
    Uncommon this line below if you want to test only the server
    */
    // server.receiveMessage();

    // If you wish to test only the server, there's no need for the fork handling below. you can comment them out if you want. The method server.receiveMessage should stay in a loop trying to receive messages anyway, so the code below doesn't necessarily need to be commented out.
    pid = fork(); // Just for testing. The program will have separated trains and server executables later
    if (pid == 0)
    {
        server.receiveMessage();
    }
    else
    {
        train1.sendMessage();
    }

    return 0;
}