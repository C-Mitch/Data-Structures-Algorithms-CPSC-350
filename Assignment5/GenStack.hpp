//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5

#include "DoublyLinkedList.hpp"

using namespace std;

#ifndef GenStack_HPP
#define	GenStack_HPP

template<class T>
class GenStack
{
	public:
		GenStack();
		~GenStack();

		void push(T& data);
		T* pop();
		T* peek();

		int getSize();
		bool isEmpty();

		
	private:
		DoublyLinkedList<T> *myStack;

};

template<class T>
GenStack<T>::GenStack()
{
	myStack = new DoublyLinkedList<T>();
}

template<class T>
GenStack<T>::~GenStack()
{
	delete myStack;
}

template<class T>
void GenStack<T>::push(T& data)
{
	myStack->insertFront(data);
}

template<class T>
T* GenStack<T>::pop()
{
	if(!isEmpty())
	{
		return myStack->removeFront();
	}
	else cout << "Stack Is Empty" << endl;
	
	return NULL;
}

template<class T>
T* GenStack<T>::peek()
{
	return myStack->getFront();
}

template<class T>
int GenStack<T>::getSize()
{
	return myStack->getSize();
}

template<class T>
bool GenStack<T>::isEmpty()
{
	return myStack->isEmpty();
}
#endif