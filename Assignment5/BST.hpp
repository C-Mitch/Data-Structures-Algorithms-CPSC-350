//Chase Mitchell
//#002274657
//Mitch213@mail.chapman.edu
//CPSC-350-01
//Assignment5


using namespace std;

#ifndef BST_HPP
#define BST_HPP

template <class T>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(T d, int k); //data is key
		~TreeNode();
		
		bool operator==(const TreeNode& b);
		bool operator<(const TreeNode& b);		
		bool operator>(const TreeNode& b);		
		bool operator!=(const TreeNode& b);		
		bool operator!=(const long int b);
		
		int key;
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;
	
};

template <class T>
TreeNode<T>::TreeNode()
{
	key = 0;
	left = NULL;
	right = NULL;
	
}

template <class T>
TreeNode<T>::TreeNode(T d, int k)
{
	key = k;
	data = d;
	left = NULL;
	right = NULL;
	
}

template <class T>
TreeNode<T>::~TreeNode()
{
	left = NULL;
	right = NULL;
}

template <class T>
bool TreeNode<T>::operator==(const TreeNode& b)
{
	return this->key == b.key;
}

template <class T>
bool TreeNode<T>::operator<(const TreeNode& b) 
{
  	return this->key < b.key;
}

template <class T>
bool TreeNode<T>::operator>(const TreeNode& b) 
{
    return this->key > b.key;
}

template <class T>
bool TreeNode<T>::operator!=(const TreeNode& b) 
{
    return !(this->key == b.key);
}

template <class T>
bool TreeNode<T>::operator!=(const long int b) 
{
    return !(this->key == b);
}


template <class T>
class BST
{
	public:
		BST();
		~BST();
		
		void insert(T d, int k);
		bool deleteNode(int k);
		bool contains(int k);
		T* find(int k);
		bool isEmpty();
		
		TreeNode<T>* getMax();
		TreeNode<T>* getMin();
		TreeNode<T>* getSuccessor(TreeNode<T> *d);
		
		void printTree(TreeNode<T> *node);
		void printTree();
		
	private:
		TreeNode<T> *root;
	
};

template <class T>
BST<T>::BST()
{
	root = NULL;
	
}

template <class T>
BST<T>::~BST()
{
	delete root;
	
}

template <class T>
void BST<T>::insert(T d, int k)
{
	
	TreeNode<T> *node = new TreeNode<T>(d,k);
	
	if(root == NULL) root = node; //If Empty TreeNode
	else //Not Empty Tree
	{
		TreeNode<T> *curr = root;
		TreeNode<T> *parent = NULL;
		
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
bool BST<T>::deleteNode(int k)
{
	if(root == NULL) return false; //empty tree
	else
	{
		TreeNode<T> *curr = root;
		TreeNode<T> *parent = root;
		bool isLeft = true;
		
		//Find node we're going to delete

		while( curr->key != k) //searching for nextToDelete
		{
			parent = curr;
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
			if(curr == NULL) return false;
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
			TreeNode<T> *successor = getSuccessor(curr);
			
			if(curr == root) root = successor;
			else if(isLeft) parent->left = successor;
			else parent->right = successor;
			
			//connect successors left child to surrent left child
			successor->left = curr->left;
		}
		
	}
	return true;
	
}

template <class T>
bool BST<T>::contains(int k)
{
	if(root == NULL) return false; //empty tree
	else
	{
		TreeNode<T> *curr = root;
		
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
T* BST<T>::find(int k)
{
	if(contains(k)) 
	{
		TreeNode<T> *curr = root;

		while(curr->key != k) 
		{
			if(k < curr->key) curr = curr->left;
			else curr = curr->right;

			if(curr == NULL) return NULL;
		}
		T* temp = &curr->data;

		return temp;
	}
	else return NULL;
	
}

template <class T>
bool BST<T>::isEmpty()
{
	if(root == NULL) return true;
	else return false;
}

template <class T>
TreeNode<T>* BST<T>::getMax()
{
	TreeNode<T> *curr = root;
	
	if(root == NULL) return NULL;
	
	while(curr->right != NULL) curr = curr->right;

	return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMin()
{
	TreeNode<T> *curr = root;
	
	if(root == NULL) return NULL;
	
	while(curr->left != NULL) curr = curr->left;

	return curr;
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) //d is node to be deleted
{
	TreeNode<T> *sp = d;
	TreeNode<T> *successor = d;
	TreeNode<T> *curr = d->right;
	
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
	
	return successor;
	
}

template <class T>
void BST<T>::printTree(TreeNode<T> *node) //In-Order Traversal
{
	if(node == NULL) return;
	
	printTree(node->left);
	cout << node->key << endl;
	printTree(node->right);
}

template <class T>
void BST<T>::printTree() //In-Order Traversal
{
	TreeNode<T> *node = root;
	printTree(node);
}


#endif