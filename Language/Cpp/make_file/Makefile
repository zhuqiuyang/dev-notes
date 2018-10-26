# Define required macros here
CFLAG = -c -Wall
CC = g++

all: hello

hello: main.o function1.o function2.o
	$(CC) main.o function1.o function2.o -o hello

main.o: main.cpp
	$(CC) $(CFLAG) main.cpp

function1.o: function1.cpp
	$(CC) $(CFLAG) function1.cpp

function2.o: function2.cpp
	$(CC) $(CFLAG) function2.cpp

target: dependencies
	action

clean:
	rm -rf *.o hello