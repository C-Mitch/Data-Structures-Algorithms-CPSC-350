//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5

#include "DoublyLinkedList.hpp"

using namespace std;

#ifndef GenQueue_HPP
#define	GenQueue_HPP

template<class T>
class GenQueue
{
	public:
		GenQueue();
		~GenQueue();

		void insert(T& data);
		T remove();
		T peek();
		int getSize();
		T getIndex(int index);
		
		bool isEmpty();
		void print();
		
	private:
		int numElements;
		DoublyLinkedList<T> *myQueue;
};

template<class T>
GenQueue<T>::GenQueue()
{
	numElements = 0;
	myQueue = new DoublyLinkedList<T>();
}

template<class T>
GenQueue<T>::~GenQueue()
{
	delete myQueue;
}

template<class T>
void GenQueue<T>::insert(T& data)
{
	myQueue->insertBack(data);
	numElements++; 
}

template<class T>
T GenQueue<T>::remove()
{
	T c = {};

	if(!isEmpty())
	{
		c = myQueue->removeFront();
		--numElements;
	}
	else cout << "Queue is empty!";

	return c;
}

template<class T>
T GenQueue<T>::peek()
{
	return myQueue->getFront();
}

template<class T>
int GenQueue<T>::getSize()
{
	return numElements;
}

template<class T>
T GenQueue<T>::getIndex(int index)
{
	ListNode<T> *curr = myQueue->getFrontNode();
	int i = 0;
	while(i != index)
	{
		curr = curr->next;
		++i;
	}

	return curr->data;
}

template<class T>
bool GenQueue<T>::isEmpty()
{
	return (numElements == 0);
}

template<class T>
void GenQueue<T>::print()
{
	myQueue->printList();
	cout << endl;
}

#endif