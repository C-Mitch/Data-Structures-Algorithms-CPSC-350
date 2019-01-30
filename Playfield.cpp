#include "Playfield.hpp"
#include <iostream>

using namespace std;


/*
GenQueue::GenQueue()
{
	myQueue = new char[10];
	front = 0;
	rear = -1;
	size = 10;
	numElements = 0;
}

GenQueue::GenQueue(int maxSize)
{
	myQueue = new char[maxSize];
	front = 0;
	rear = -1;
	size = maxSize;
	numElements = 0;
}

GenQueue::~GenQueue
{
	delete myQueue;
}

void GenQueue::insert(char data)
{
	
	if(rear == size-1) rear = -1;
	if(!myQueue.isFull) myQueue[++rear] = data;
	numElements++;
	
}

char GenQueue::remove()
{
	char c = '\0';
	c = myQueue[front];
	++front;
	if(front == size) front = 0;
	
	--numElements;
	return c;
}

char GenQueue::peek()
{
	char c = '\0';
	c = myQueue[front];
	return c;
}

int GenQueue::getSize()
{
	return numElements;
}

bool GenQueue::isFull()
{
	return (numElements == size);
}

bool GenQueue::isEmpty()
{
	return (numElements == 0);
}
*/

/*
Quiz1::Quiz1()
{
	
}

Quiz1::~Quiz1()
{
	cout << "Object Deleted" << endl;
}

int Quiz1::countVowels(string input)
{
	int count = 0;
	for(int i = 0; i<input.size(); ++i)
	{
		if(input[i]=='a') count++;
		else if(input[i]=='e') count++;
		else if(input[i]=='i') count++;
		else if(input[i]=='o') count++;
		else if(input[i]=='u') count++;
	}
	
	return count;
}


GenStack::GenStack() //Default Constructor
{
	myArray = new char[256];
	size = maxSize;
	top =  -1;
	
}

GenStack::GenStack(int maxSize)
{
	myArray = new char[maxSize];
	size = maxSize;
	top =  -1;
	
}

GenStack::~GenStack()
{
	delete myArray[];
	delete size;
	delete top;
	cout << "Object Deleted" << endl;
}

void GenStack::push(char d)
{
	myArray[++top] = d;
	
}

char GenStack::pop()
{
	return myArray[top--];
	
}

char GenStack:peek()
{
	return myArray[top];
}

bool GenStack::isFull()
{
	return (top == maxSize -1);
}

bool GenStack::isFull()
{
	return (top == -1);
}*/
