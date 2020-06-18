#ifndef BST_H
#define BST_H
#include"BTNode.h"

template<typename T>
class BST
{
public:
	BTNode<T>*root;
	int getDegree(BTNode<T>*p);		//Private Function to get degree of the Node
	void inOrder(BTNode<T>*p)
	{
		if (p == nullptr)
		{
			return;
		}
		if (p->left)
		{
			inOrder(p->left);
		}
		cout << p->info<<",";
		if (p->right)
		{
			inOrder(p->right);
		}
	}

	void removeNode(BTNode<T>*p);								//Private Function To remove Node
	void removeDegreeZero(BTNode<T>*p, BTNode<T>*pre);			//Private Function To remove Node of Degree 0
	void removeDegreeOne(BTNode<T>*p, BTNode<T>*pre);			//Private Function to remove Node of Degree 1
	BTNode<T>*findMinimumNode(BTNode<T>*p, BTNode<T>**parent);	//Private Function to give minimum Node	//parent gives Parent Node of Minimum Node
	void removeDegreeTwo(BTNode<T>*p, BTNode<T>*pre);			//Private Function to remove Node of Degree 2

public:
	BST();
	void insert(T val);
	void remove(T val);
	bool search(T val);
	~BST();
};

#endif
