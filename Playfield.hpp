#include <iostream> //preprocessor directive

using namespace std;


template <class T>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(T k); //data is key
		~TreeNode();
		
		T key;
		TreeNode<T> *left;
		TreeNode<T> *right;
	
};

template <class T>
TreeNode::TreeNode()
{
	key = 0;
	left = NULL;
	right = NULL;
	
}

template <class T>
TreeNode::TreeNode(T k)
{
	key = k;
	left = NULL;
	right = NULL;
	
}

template <class T>
TreeNode::~TreeNode()
{
	key = k;
	left = NULL;
	right = NULL;
	
}

template <class T>
class BST
{
	public:
		BST();
		~BST();
		
		void insert(T k);
		bool deleteNode(T k);
		bool contains(T k);
		bool isEmpty();
		
		TreeNode* getMin();
		TreeNode* getMax();
		
		void printTree(TreeNode *node);
		void printTree();
		TreeNode* BST::getSuccessor()(TreeNode *d)
		
	private:
		TreeNode *root;
	
}

template <class T>
BST::BST()
{
	root = NULL;
	
}

template <class T>
BST::~BST()
{
	//Iterate & Delete
	
}

template <class T>
void BST::printTree(TreeNode *node) //In-Order Traversal
{
	TreeNode *node = root;
	printTree(node);
}

template <class T>
void BST::printTree(TreeNode *node) //In-Order Traversal
{
	if(node == NULL) return;
	
	printTree(node->left);
	cout << node->key << endl;
	printTree(node->right);
}

template <class T>
TreeNode* BST::getMax()
{
	TreeNode *curr = root;
	
	if(root == NULL) return NULL;
	
	while(curr->right != NULL) curr = curr->right;

	return curr;
}

template <class T>
TreeNode* BST::getMin()
{
	TreeNode *curr = root;
	
	if(root == NULL) return NULL;
	
	while(curr->left != NULL) curr = curr->left;

	return curr;
}

template <class T>
void BST::insert(T k)
{
	TreeNode *node = new TreeNode<T>(k);
	
	if(root == NULL) root = node; //If Empty TreeNode
	else //Not Empty Tree
	{
		TreeNode *curr = root;
		TreeNode *parent = NULL;
		
		while(true)//Iterate and find insertion point
		{
			parent = curr;
			
			if(k < curr->key) //Go Left
			{
				curr = curr->left;
				
				if(curr == NULL) //Insertion point found
				{
					parent->left = node;
					break;
				}
			}
			else //Go Right
			{
				curr = curr->right;
				
				if(curr == NULL) //Insertion point found
				{
					parent->right = node;
					break;
				}				
			}
		}
	}
}

template <class T>
bool BST::contains(T k)
{
	if(root == NULL) return false; //empty tree
	else
	{
		TreeNode *curr = root;
		
		while(curr->key != k)
		{
			if(k < curr->key) //Go Left
			{
				curr = curr->left;
			}
			else //Go Right
			{
				curr = curr->right;
			}
			
			if(curr == NULL) return false;
		}
	}
	return true;
}

template <class T>
bool BST::deleteNode(int k)
{
	if(root == NULL) return false; //empty tree
	
	TreeNode *curr = root;
	TreeNode *parent = root;
	bool isLeft = true;
	
	//Find node we're going to delete
	while(curr->key != k) //searching for nextToDelete
	{
		if(k < curr->key) //Go Left
		{
			isLeft = true;
			curr = curr->left;
		}
		else
		{
			isLeft = false;
			curr = curr->right;
		}
		if(curr = NULL) return false;
	}
	
	//node to delete found; 3 cases:
	
	//NO CHILDREN
	if(curr->left == NULL && curr->right == NULL)
	{
		if(curr == root) root = NULL; //null out the root
		else if(isLeft) parent->left = NULL;
		else parent->right = NULL;
	}
	//ONE CHILD
	//no right child
	else if(curr->right == NULL)
	{
		
		if(curr == root) root = curr->left;
		else if(isLeft) parent->left = curr->left;
		else parent->right = curr->left;
	}
	//no left child
	else if(curr->left == NULL)
	{
		
		if(curr == root) root = curr->right;
		else if(isLeft) parent->left = curr->right;
		else parent->right = curr->right;
	}
	//TWO CHILDREN
	else
	{
		TreeNode *successor = getSuccessor(curr);
		
		if(curr == root) root = successor;
		else if(isLeft) parent->left = successor;
		else parent->right = successor;
		
		//connect successors left child to surrent left child
		successor->left = curr->left;
	}
	
	return true;
	
}


TreeNode* BST::getSuccessor()(TreeNode *d) //d is node to be deleted
{
	TreeNode *sp = d;
	TreeNode *successor = d;
	TreeNode *curr = d->right;
	
	//loop till successor found: one right, all the way left
	while(curr != NULL)
	{
		sp = successor;
		successor = curr;
		curr = curr->left;
	
	}
	if(successor != d->right) //descendant of right child
	{
		sp->left = successor->right;
		successor->right = d->right;
	}
	
}

/*
class List
{
	
	public:
		virtual void insertFront(int data)=0;
		virtual void insertBack(int data)=0;
		virtual int removeFront()=0;
		virtual int removeBack()=0;
		virtual bool contains(int value)=0;
		virtual int remove()=0;
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
		
		T data;
		ListNode *next;
		ListNode *prev;
	
	
};

template <class T>
ListNode::ListNode()
{
	data = NULL;
	next = NULL;
	prev = NULL;
}

template <class T>
ListNode::ListNode(T d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

template <class T>
ListNode::~ListNode()
{
	//build character
}

class DoublyLinkedList : List
{
	private:
		ListNode *front();
		ListNode *back();
		unsigned int size;
	
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		
		virtual void insertFront(int data)=0;
		virtual void insertBack(int data)=0;
		virtual int removeFront()=0;
		virtual int removeBack()=0;
		virtual bool contains(int value)=0;
		virtual int remove()=0;
		virtual unsigned int getSize()=0;
		virtual bool isEmpty()=0;
		
		ListNode remove(int val);
		
		int deletePos();
		void printList();
		int find(int data);
		unsigned int getSize();
		bool isEmpty();
		
	
};

DoublyLinkedList:DoublyLinkedList()
{
	size = 0;
	front = NULL;
	back = NULL;
	
}

DoublyLinkedList::~DoublyLinkedList()
{
	//if(front != NULL) delete front;
	
}

void DoublyLinkedList::printList()
{
	ListNode *curr = front;
	
	while(curr->next != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}

//Insert In FRONT Only
void DoublyLinkedList::insertFront(int data)
{
	ListNode *node = new ListNode(data);
	if(isEmpty())
	{
		back = node;
	}
	else
	{
		front->prev = node;
		node->next = front;
	}
	front = node;
	++size;
}

void DoublyLinkedList::insertBack(int data)
{
	ListNode *node = new ListNode(data);
	
	if(isEmpty())
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

//Remove From Front Of List
int DoublyLinkedList::removeFront()
{
	//Make Neccessary Checks
	//Make Sure List Not Empty
	listNode *node = front;
	
	if(front->next == NULL) back = NULL;
	else front->next->prev = NULL;
	
	front =front->next;
	--size;
	node->next = NULL;
	int temp = node->data;
	
	delete node;
	return temp;

}

int DoublyLinkedList::removeBack()
{
	listNode *node = back;
	
	if(back->prev == NULL) front = NULL;
	else back->prev->next = NULL;
	
	back = back->prev;
	--size;
	node->prev = NULL;
	int temp = node->data;
	
	delete node;
	return temp;
	
}

int DoublyLinkedList::find(int d)
{
	int idx = -1;
	ListNode *curr = front;
	
	while(curr != NULL)
	{
		++idx;
		if(curr->data == d) break;
		else
		{
			curr = cur->next;
		}
	}
	
	if(curr == NULL) idx = -1;
	
	return idx;
}

unsigned int DoublyLinkedList::getSize();
{
	
}

int DoublyLinkedList::removeAt(int key)
{
	ListNode *curr = front;
	
	while(curr->data != key)
	{
		curr = curr->next;
		
		if(curr == NULL) return NULL;
	}
	
	if(curr == front) front = curr->next;
	else curr->prev->next = curr->next;
	
	if(curr == back) back = curr->prev;
	else curr->next->prev = curr->prev;
	
	curr->next = NULL;
	curr->prev = NULL;
	--size;
	
	int temp = curr->data;
	delete curr;
	return temp;
}

int DoublyLinkedList::deletePos(int pos)
{
	int idx = 0;
	
	listNode *curr = front;
	listNode *prev = front;
	
	while(idx != pos) //Update Pointers
	{
		prev = curr;
		curr = curr->next;
		idx++;
	}
	prev->next = curr->next;
	curr->next = null;
	int td = curr->data;
	
	delet curr;
	size--return td;
}
*/

/*
class GenQueue
{
	public:
		GenQueue();
		GenQueue(int maxSize);
		~GenQueue();
		
		void insert(char data);
		char remove();
		char peek();
		int getSize();
		
		bool isFull();
		bool isEmpty();
		
		
	private:
		char *myQueue;
		int rear;
		int front;
		int numElements;
		int size;
	
	
};

*/

/*
class Quiz1
{
	public:
		Quiz1(); //Constructor
		~Quiz1(); //Destructor
		int countVowels(string input);
};

class GenStack
{
	public:
		Genstack();
		GenStack(int maxSize);
		~GenStack();
		
		void push(char d);
		char pop();
		char peek();
		bool isEmpty();
		bool isFull();
		int getSize();
		
		char *myArray;
		int top;
		int size;
		int count;
	
};
*/