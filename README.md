## Trains TD


The goal of this project is to have an industrial message exchange between multiple clients (trains) and a server, which acts as a controller. 

A train may enter the railroad if there is no train present at the first position. Each train can move up to a certain position, which is calculated by the position of the train in front minus 1 (EOA). Once a train reaches the end of the railroad, it excludes itself from the railroad structure.

For each movement, each client sends a request to the server, which has a data structure containing the trains' ids, positions' and EOA's (End of availability, the maximum amount of spaces a train can move). 

The program consists in the following:

The train requests to enter the railroad -> Server verifies if it is possible (if there is no train at position 1) and sends back the response containing the train id (assigned by the server), their position (set to 1, initially) and their EOA (the amount of spaces the train that just entered can move). 

Each train can request to move N spaces. The server will verify if that is possible or not. If it is not possible, the server sends a message containing a code of refusal and the train cannot move. If it is possible, the server ackowledges the message, updates their data structure of trains (EOA's) and sends an OK to the train, which is now free to move. 

This goes on until every train leaves the railway.


## Usage

### Installation
In the root directory, type
```
 make
 ```
  to create the binaries. It might be necessary to change the compiler variables in the Makefile if your system does not have clang pre-installed. g++ might be an alternative.

### Start the program

The makefile will produce an executable in the **bin** folder. Once you're in the **bin** folder, you can start the program with

```
./main <server_ip> <port>
```

## TODO


Progress:

 So far, communication works. You can run ./main \<ip> \<port> to verify. The data structure of messages and the vector to store train data in the server is also set up. you can view those at Server.h (include folder) and their implementation at Server.cpp (src folder). The structure of messages is being defined by types.h. Both train(s) and the server will use those structures to communicate.

Left to implement: 

- other messages: so far, the server only treats the message to insert a new train, but it is yet unfinished. The switch case structure to handle the different request based on the code is already set. 

- Acknowledge handling: the train must act accordingly to the server's response.

OBS: This code (executable main) launches both server and a train for testing purposes. If you wish to test the server, take a look at the commentaries in the src/main.cpp file
