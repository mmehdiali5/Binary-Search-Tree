#include<iostream>
using namespace std;
#include"BST.h"

int main()
{
	BST<int>a;
	a.insert(95);
	a.insert(100);
	a.insert(25);
	a.insert(10);
	a.insert(75);
	a.insert(5);
	a.insert(20);
	a.insert(30);
	a.insert(80);
	a.insert(7);
	a.insert(8);
	a.insert(35);
	a.insert(32);
	a.insert(40);
	cout<<a.search(40)<<"\n";
	a.inOrder(a.root);
	cout << "\n";
	a.remove(95);
	a.inOrder(a.root);
	cout << "\n";
	a.remove(75);
	a.inOrder(a.root);
	cout << "\n\n\n\n\n\n\n";
	return 0;
}
