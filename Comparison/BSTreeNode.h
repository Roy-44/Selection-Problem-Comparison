#ifndef _BSTREENODE_h
#define _BSTREENODE_h

#include<iostream>
#include "Person.h"


class BSTreeNode
{
private:
	int key;
	int leftSubTreeSize;
	int rightSubTreeSize;
	Person data;
	BSTreeNode *left, *right;
	 
public:
	/*BSTreeNode();*/
	BSTreeNode(Person data, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();

	void InOrder();
	void PreOrder();
	void PostOrder();

	friend class BSTree;
};
#endif // !_BSTREENODE_h
