#include<iostream>
using namespace std;
#include"BST.h"

template<typename T>
BST<T>::BST()
{
	root = nullptr;
}

template<typename T>
void BST<T>::insert(T val)
{
	if (root == nullptr)
	{
		root = new BTNode<T>(val);
		return;
	}
	BTNode<T>*p = root;
	BTNode<T>*pre = p;
	while (p != nullptr)
	{
		if (val < p->info)
		{
			pre = p;
			p = p->left;
		}
		else
		{
			pre = p;
			p = p->right;
		}
	}
	if (val < pre->info)
	{
		pre->left = new BTNode<T>(val);
	}
	else
	{
		pre->right = new BTNode<T>(val);
	}
}

template<typename T>
bool BST<T>::search(T val)
{
	BTNode<T>*p = root;
	BTNode<T>*pre = p;
	while (p != nullptr)
	{
		if (p->info == val)
		{
			return true;
		}
		if (val < p->info)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return false;
}

template<typename T>
int BST<T>::getDegree(BTNode<T>*p)		//Private Function to get degree of the Node
{
	if (p->right && p->left)
	{
		return 2;
	}
	if (!p->left && !p->right)
	{
		return 0;
	}
	return 1;
}

template<typename T>
void BST<T>::removeDegreeZero(BTNode<T>*p, BTNode<T>*pre)	//Private Function To remove Node of Degree 0
{
	if (p == root)
	{
		delete p;
		root = nullptr;
		return;
	}
	if (p == pre->left)
	{
		pre->left = nullptr;
	}
	else
	{
		pre->right = nullptr;
	}
	delete p;
	return;
}

template<typename T>
void BST<T>::removeDegreeOne(BTNode<T>*p, BTNode<T>*pre)   //Private Function to remove Node of Degree 1
{
	if (p == root)
	{
		if (p->right)
		{
			root = p->right;
			delete p;
		}
		else
		{
			root = p->left;
			delete p;
		}
		return;
	}
	if (p == pre->left)
	{
		if (p->right)
		{
			pre->left = p->right;
		}
		else
		{
			pre->left = p->left;
		}
	}
	else
	{
		if (p->right)
		{
			pre->right = p->right;
		}
		else
		{
			pre->right = p->left;
		}
	}
	delete p;
	return;
}

template<typename T>
BTNode<T>* BST<T>::findMinimumNode(BTNode<T>*p, BTNode<T>**parent) //Private Function to give minimum Node
{
	while (p->left != nullptr)
	{
		*parent = p;				//parent gives Parent Node of Minimum Node
		p = p->left;
	}
	return p;
}

template<typename T>
void BST<T>::removeDegreeTwo(BTNode<T>*p, BTNode<T>*pre)			//Private Function to remove Node of Degree 2
{
	BTNode<T>*parent = p;
	BTNode<T>*min = findMinimumNode(p->right, &parent);
	p->info = min->info;
	int degree = getDegree(min);
	if (degree == 1)
	{
		removeDegreeOne(min, parent);
	}
	else
	{
		removeDegreeZero(min, parent);
	}
}

template<typename T>
void BST<T>::remove(T val)
{
	BTNode<T>*p = root;
	BTNode<T>*pre = p;
	while (p != nullptr)
	{
		if (p->info == val)
		{
			int degree = getDegree(p);
			if (degree == 0)
			{
				removeDegreeZero(p, pre);
				return;
			}
			if (degree == 1)
			{
				removeDegreeOne(p, pre);
				return;
			}
			if (degree == 2)
			{
				removeDegreeTwo(p, pre);
			}
		}
		else if (val < p->info)
		{
			pre = p;
			p = p->left;
		}
		else
		{
			pre = p;
			p = p->right;
		}
	}
}


template<typename T>
void BST<T>::removeNode(BTNode<T>*p)			//Private Function To remove Node
{
	if (p->right)
	{
		removeNode(p->right);
	}
	if (p->left)
	{
		removeNode(p->left);
	}
	delete p;
}

template<typename T>
BST<T>::~BST()
{
	removeNode(root);
	root = nullptr;
}