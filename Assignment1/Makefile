BUILD_FLAGS = -W -Wall -pedantic 
CC = g++
RM = rm
EXES = *.exe

all: Assignment1.exe
	
Assignment1.exe: Makefile Assignment1.cpp
	$(CC) $(BUILD_FLAGS) -o Assignment1.exe Assignment1.cpp

clean:
	$(RM) $(EXES) $(OBJECTS)