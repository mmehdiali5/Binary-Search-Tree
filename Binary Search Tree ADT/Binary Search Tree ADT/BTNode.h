#ifndef BTNODE_H
#define BTNODE_H

template<typename T>
struct BTNode
{
	T info;
	BTNode<T>*left;
	BTNode<T>*right;
	BTNode()
	{
		left = nullptr;
		right = nullptr;
	}
	BTNode(T val)
	{
		info = val;
		left = nullptr;
		right = nullptr;
	}
};

#endif
