BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment4.exe

Assignment4.o: Makefile Assignment4.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment4.cpp -o Assignment4.o
	
GenFileIn.o: Makefile GenFileIn.cpp
	$(CC) $(BUILD_FLAGS) -c GenFileIn.cpp -o GenFileIn.o
	
Registrar.o: Makefile Registrar.cpp
	$(CC) $(BUILD_FLAGS) -c Registrar.cpp -o Registrar.o
	
Assignment4.exe: Makefile Assignment4.o GenFileIn.o Registrar.o Assignment4Driver.cpp
	$(CC) $(BUILD_FLAGS) Assignment4.o GenFileIn.o Registrar.o Assignment4Driver.cpp -o Assignment4.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)