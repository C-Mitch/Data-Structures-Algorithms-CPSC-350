BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment2.exe

Assignment2.o: Makefile Assignment2.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment2.cpp -o Assignment2.o
	
Assignment2.exe: Makefile Assignment2.o Assignment2Driver.cpp
	$(CC) $(BUILD_FLAGS) Assignment2.o Assignment2Driver.cpp -o Assignment2.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)