#ifndef _BSTree_H_
#define _BSTree_H_

#include<stdlib.h>

class BSTreeNode;
class Person;


class BSTree
{
private:
	BSTreeNode* root;

public:
	BSTree(BSTreeNode* root=nullptr);
	~BSTree();
	BSTreeNode* Find(int key,int& counter);
	void Insert(Person& p, int& counter);
	void Delete(Person& p);

	BSTreeNode* findParent(int key,BSTreeNode** curr);
	BSTreeNode* Min();
	BSTreeNode* Max();
	void PrintTree();
	bool isEmpty();
	void makeEmpty();


	static const Person BST(Person** n, int k, int &NumComp,int arrSize);
};

#endif // !_BSTree_H_
