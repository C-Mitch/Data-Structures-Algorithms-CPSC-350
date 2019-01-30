BUILD_FLAGS = -w -g -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Assignment3.exe

Assignment3.o: Makefile Assignment3.cpp
	$(CC) $(BUILD_FLAGS) -c Assignment3.cpp -o Assignment3.o
	
Assignment3.exe: Makefile Assignment3.o Assignment3Driver.cpp
	$(CC) $(BUILD_FLAGS) Assignment3.o Assignment3Driver.cpp -o Assignment3.exe
	
clean:
	$(RM) $(EXES) $(OBJECTS)