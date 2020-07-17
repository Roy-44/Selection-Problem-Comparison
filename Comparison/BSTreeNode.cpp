#include "BSTreeNode.h"

BSTreeNode::BSTreeNode(Person data, BSTreeNode * left, BSTreeNode * right):data(data)
{
	key = data.GetID();
	this->left = left;
	this->right = right;
	leftSubTreeSize = rightSubTreeSize = 0;
}

BSTreeNode::~BSTreeNode()
{
	delete left;
	delete right;
}

void BSTreeNode::InOrder()
{//print the tree in order
	if (!this)
	{
		std::cout << "invalid input";
		exit(1);
	}
	if (!left && !right)
		std::cout << data<<", ";
	if (left)
		left->InOrder();
	std::cout << this->data << ", ";
	if (right)
		right->InOrder();
}

void BSTreeNode::PreOrder()
{//print the tree pre order
	if (!this)
	{
		std::cout << "invalid input";
		exit(1);
	}
	std::cout << this->data << ", ";
	if (!left && !right)
		std::cout << data << ", ";
	if (left)
		left->InOrder();
	if (right)
		right->InOrder();
}

void BSTreeNode::PostOrder()
{//print the tree post order
	if (!this)
	{
		std::cout << "invalid input";
		exit(1);
	}
	if (!left && !right)
		std::cout << data << ", ";
	if (left)
		left->InOrder();
	if (right)
		right->InOrder();
	std::cout << this->data << ", ";
}

