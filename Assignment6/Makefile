BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment6.exe

Assignment6.o: Makefile Assignment6.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment6.cpp -o Assignment6.o
	
GenFileIn.o: Makefile GenFileIn.cpp
	$(CC) $(BUILD_FLAGS) -c GenFileIn.cpp -o GenFileIn.o
	
Assignment6.exe: Makefile Assignment6.o GenFileIn.o Assignment6Driver.cpp
	$(CC) $(BUILD_FLAGS) Assignment6.o GenFileIn.o Assignment6Driver.cpp -o Assignment6.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)