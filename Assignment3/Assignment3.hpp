//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef Assignment3_HPP
#define Assignment3_HPP

//A general object to get and validate file input and output
class GenFileIO
{
	public:
		GenFileIO();
		~GenFileIO();
		
		void setPath(); //Sets a file path to be used
		std::string getStringInput(); //Gets general string input
		std::string getPath(); //Gets a file path and validates it, loops till valid file path found
		bool validatePath(); //A test to check if a path is valid, returns true if path connects, false if not
		
	private:
		std::string path; //Std::string to hold a file path
	
	
};

//A template of a general array based stack that can be reused in other classes and functions
template <class T>
class GenStack
{
	public:
		GenStack();
		GenStack(int maxSize);
		~GenStack();
		
		void push(T d); //Push an object type T onto the stack, update top
		T pop(); //Pop and return an object type T off of stack at position top, update top
		T peek(); //Return an object type T off of stack at position top
		T peekNext(); //Return an object type T off of stack at position top-1
		bool isEmpty(); //Boolean return of condition: (top == -1)
		bool isFull();  //Boolean return of Condition: (top == size-1)
		int getSize();	//Returns Stack Size
		void increaseSize();  //Function for increasing stack size and copying stored values
	
	private:
		T *myArray;
		T *hArray;
		int top;
		int size;
	
};

template <class T>
GenStack<T>::GenStack()
{
	myArray = new T[20];
	hArray = new T[20];
	size = 20;
	top =  -1;
	
	cout << "Default Stack Created" << endl;
}

template <class T>
GenStack<T>::GenStack(int maxSize)
{
	myArray = new T[maxSize];
	hArray = new T[maxSize];
	size = maxSize;
	top =  -1;
	
	cout << "Stack Created" << endl;
}

template <class T>
GenStack<T>::~GenStack()
{
	while (!isEmpty()) pop();
	
	cout << endl << "Object Deleted" << endl;
}

template <class T>
void GenStack<T>::push(T d)
{
	myArray[++top] = d;
	
}

template <class T>
T GenStack<T>::pop()
{
	return myArray[top--];
	
}

template <class T>
T GenStack<T>::peek()
{
	return myArray[top];
}

template <class T>
T GenStack<T>::peekNext()
{
	return myArray[top-1];
}

template <class T>
bool GenStack<T>::isFull()
{
	return (top == size -1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
	return (top == -1);
}

template <class T>
int GenStack<T>::getSize()
{
	return size;
}

template <class T>
void GenStack<T>::increaseSize()
{
	cout << "Increasing Stack Size" << endl;
	//Copy current stack values to holder stack
	for(int i = 0; i < size; ++i)
	{
		hArray[i] = myArray[i];
	}
	//Increase main stack size and transfer values back from holder stack
	myArray = new T[size+20];
	for(int i = 0; i < size; ++i)
	{
		myArray[i] = hArray[i];
	}
	//Increase holder stack and update size value
	hArray = new T[size+20];
	size += 20;
	
}
//A class that handles delimiter syntax checking for valid files
class Delimiter
{
	public:
		Delimiter();
		~Delimiter();
		
		void readFile(std::string path); //Reads single character input from valid file as well as cases for checking delimiter syntax errors
		void printError(char c); //Prints delimiter syntax errors based on passed condition from readFile function
	
	private:
		int lineCount;
		GenStack <char> stack;
	
};

#endif