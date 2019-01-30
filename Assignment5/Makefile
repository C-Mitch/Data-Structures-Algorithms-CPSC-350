BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment5.exe

Assignment5.o: Makefile Assignment5.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment5.cpp -o Assignment5.o
	
GenFileIn.o: Makefile GenFileIn.cpp
	$(CC) $(BUILD_FLAGS) -c GenFileIn.cpp -o GenFileIn.o
	
Person.o: Makefile Person.cpp
	$(CC) $(BUILD_FLAGS) -c Person.cpp -o Person.o
	
Assignment5.exe: Makefile Assignment5.o GenFileIn.o Person.o Assignment5Driver.cpp
	$(CC) $(BUILD_FLAGS) Assignment5.o GenFileIn.o Person.o Assignment5Driver.cpp -o Assignment5.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)