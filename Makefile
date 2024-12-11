

HEADERS=include/Server.h include/Train.h include/types.h
SRC=src/main.cpp src/Server.cpp src/Train.cpp


CC=clang++
CFLAGS=-std=c++17 -stdlib=libc++ 

all: bin/main



bin/main: $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm bin/main

