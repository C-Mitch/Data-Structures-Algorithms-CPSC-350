//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5

#include <iostream>

using namespace std;

#ifndef DoublyLinkedList_HPP
#define DoublyLinkedList_HPP

template<class T>
class List
{
	public:
		virtual void insertFront(T data)=0;
		virtual void insertBack(T data)=0;
		virtual T removeFront()=0;
		virtual T removeBack()=0;
		virtual bool contains(T value)=0;
		virtual T remove(T key)=0;
		virtual T deletePos(int pos)=0;
		virtual unsigned int getSize()=0;
		virtual bool isEmpty()=0;
};

template <class T>
class ListNode
{
	public:
		ListNode();
		ListNode(T d);
		~ListNode();

		bool operator==(const ListNode& b);
		bool operator<(const ListNode& b);		
		bool operator>(const ListNode& b);		
		bool operator!=(const ListNode& b);		
		bool operator!=(const long int b);
		
		T data;
		ListNode *next;
		ListNode *prev;

};

template <class T>
ListNode<T>::ListNode()
{
	next = NULL;
	prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{
    if(next != NULL) 
    {
        next = NULL;
		delete next;
		
        prev = NULL;
        delete prev;
    }
}

template <class T>
bool ListNode<T>::operator==(const ListNode& b)
{
	return this->data == b.data;
}

template <class T>
bool ListNode<T>::operator<(const ListNode& b) 
{
  	return this->data < b.data;
}

template <class T>
bool ListNode<T>::operator>(const ListNode& b) 
{
    return this->data > b.data;
}

template <class T>
bool ListNode<T>::operator!=(const ListNode& b) 
{
    return !(this->data == b.data);
}

template <class T>
bool ListNode<T>::operator!=(const long int b) 
{
    return !(this->data == b);
}


template<class T>
class DoublyLinkedList : public List<T>
{
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		void insertFront(T data);
		void insertBack(T data);
		T removeFront();
		T removeBack();
		
		T remove(T key);
		T deletePos(int pos);
		
		unsigned int getSize();
		T getFront();
		ListNode<T>* getFrontNode();
		T find(T data);
		bool isEmpty();
		bool contains(T value);
		void printList();


	private:
		ListNode <T> *front;
		ListNode <T> *back;
		int size;
};


template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size = 0;
	front = new ListNode<T>();
	back = new ListNode<T>();
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (front != NULL) delete front;
}

template<class T>
void DoublyLinkedList<T>::insertFront(T data)
{
	ListNode<T> *node = new ListNode<T>(data);
	
	if(isEmpty())back = node;

	else
	{
		front->prev = node;
		node->next = front;
	}

	front = node;
	size++;	
}

template<class T>
void DoublyLinkedList<T>::insertBack(T data)
{
	ListNode<T> *node = new ListNode<T>(data);

	if(isEmpty() == true)
	{
		front = node;
	}
	else
	{
		back->next = node;
		node->prev = back;
	}
	back = node;
	++size;	
}

template<class T>
T DoublyLinkedList<T>::removeFront()
{
	ListNode<T> *node = front;

	if(front->next == NULL) back = NULL;
	else front->next->prev = NULL;

	T td = front->data;
	front = front->next;
	node->next = NULL;

	delete node;
	size--;

	return td;
}

template<class T>
T DoublyLinkedList<T>::removeBack()
{
	ListNode<T> *node = back;

	if(back->prev == NULL) front = NULL;
	else back->prev->next = NULL;


	T td = back->data;
	back = back->prev;
	back->prev = NULL;

	delete back;
	size--;

	return td;
}

template<class T>
T DoublyLinkedList<T>::remove(T key)
{
	ListNode<T> *curr = front;
	
	while(curr->data != key)
	{
		curr = curr->next;
		if(curr == NULL) return {};
	}
	
	if(curr == front) front = curr->next;
	else curr->prev->next = curr->next;

	if (curr == back) back = curr->prev;
	else curr->next->prev = curr->prev;

	curr->next = NULL;
	curr->prev = NULL;
	size--;

	T temp = curr->data;
	delete curr;

	return temp;
}

template<class T>
T DoublyLinkedList<T>::deletePos(int pos)
{
	int idx = 0;

	ListNode<T> *curr = front;
	ListNode<T> *prev = front;

	while(idx != pos)
	{
		prev = curr;
		curr = curr->next;
		idx++;
	}

	prev->next = curr->next;
	curr->next = NULL;
	T td = curr->data;

	delete curr;
	size--;

	return td;
}

template<class T>
unsigned int DoublyLinkedList<T>::getSize()
{
	return size;
}

template<class T>
T DoublyLinkedList<T>::getFront()
{
	ListNode<T> *curr = front;
	return curr->data;
}

template<class T>
ListNode<T>* DoublyLinkedList<T>::getFrontNode()
{
	return front;
}

template<class T>
T DoublyLinkedList<T>::find(T d)
{
	int idx = -1;
	ListNode<T> *curr = front;
	
	while(curr != NULL)
	{
		++idx;
		if (curr->data == d) break;
		else curr = curr->next;
	}

	if(curr == NULL) idx = -1;

	return idx;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty()
{
	if(size == 0) return true;
	else return false;
}

template<class T>
bool DoublyLinkedList<T>::contains(T value)
{
	int idx = -1;
	ListNode<T> *curr = front;
	
	while(curr != NULL)
	{
		++idx;
		if (curr->data == value) return true;
		else curr = curr->next;
	}
	
	if(curr == NULL) return false;
	return false;
}

template<class T>
void DoublyLinkedList<T>::printList()
{
	ListNode<T> *curr = front;
	if(!isEmpty())
	{
		cout << "[";
		while(curr != NULL)
		{
			if(curr->next != NULL) cout << curr->data << ", ";
			else cout << curr->data;
			curr = curr->next;
		}
		cout << "]";
	}
	else cout << "Empty";
}

#endif
