#include "BSTree.h"
#include"BSTreeNode.h"
#include"Person.h"

BSTree::BSTree(BSTreeNode* root)
{
	this->root = root;
}

BSTree::~BSTree()
{
	delete root;
}

BSTreeNode * BSTree::Find(int key, int& counter)
{//return the node with the key "key" and count how many comparisons made
 //runing time: worst time ϴ(n), avg time ϴ(logn).
	BSTreeNode* temp = root;
	while (temp != nullptr)
	{
		counter++;
		if (key == temp->key)//the key found
			return temp;
		else if (key < temp->key)//we need to search on the left sub tree.
			temp = temp->left;
		else//key>temp->key so wo need to search on the right sub tree.
			temp = temp->right;
	}
	return nullptr;
}

void BSTree::Insert(Person & p, int& counter)
{//insert the new person 'p' and count how many comparisons made.
 //runing time: worst time ϴ(n), avg time ϴ(logn).
	if (Find(p.GetID(), counter))//p is already exist.
	{
		std::cout << "invalid input\n";
		exit(1);
	}
	BSTreeNode* temp = root, *parent = nullptr,*newNode;
	while (temp != nullptr)
	{
		parent = temp;
		counter++;
		if (p.GetID() < temp->key)//'p' key is smaller the the pointed person key.
		{
			temp->leftSubTreeSize++;
			temp = temp->left;
		}
		else//'p' key is bigger the the pointed person key.
		{
			temp->rightSubTreeSize++;
			temp = temp->right;
		}
	}
	newNode = new BSTreeNode(p, nullptr, nullptr);
	if (parent == nullptr)//empty tree.
		root = newNode;
	else if (p.GetID() < parent->key)//'p' key is smaller then parent key
	{
		counter++;
		parent->left = newNode;
	}
	else//'p' key is bigger then parent key
	{
		counter++;
		parent->right = newNode;
	}
}

void BSTree::Delete(Person & p)
{
	BSTreeNode* curr=nullptr, *child;
	BSTreeNode* parent = findParent(p.GetID(), &curr);
	if (curr->left && curr->right)
	{// curr got 2 kids.
		BSTreeNode* temp = curr->left,*MleftParent = nullptr, *Mleft = curr;
		curr->leftSubTreeSize--;
		while (temp)//search the max key on the left sub tree and his father.
		{
			temp->rightSubTreeSize--;
			MleftParent = Mleft;
			Mleft = temp;
			temp = temp->right;
		}
		curr->data = Mleft->data;
		curr->key = Mleft->key;
		if (Mleft->left)//the max got left child.
		{
			MleftParent->right = Mleft->left;
			Mleft->left = nullptr;
		}
		delete Mleft;
	}
	else //curr got maximum one child
	{
		if (curr->left || curr->right)// curr got one child
		{
			if (curr->left)//got left child
				child = curr->left;
			else//got right child
				child = curr->right;
			if (parent->left == curr)//curr is the left child of his parent
			{
				parent->leftSubTreeSize--;
				parent->left = child;
			}
			else//curr is the right child of his parent
			{
				parent->rightSubTreeSize--;
				parent->right = child;
			}
			curr->left = curr->right = nullptr;
		}
		else//curr got no children
			if (parent->left == curr)
			{
				parent->leftSubTreeSize--;
				parent->left = nullptr;
			}
			else
			{
				parent->rightSubTreeSize--;
				parent->right = nullptr;
			}
		delete curr;
	}
}

BSTreeNode * BSTree::findParent(int key,BSTreeNode** curr)
{//initializ "curr" to the node with key "key" and return curr's parent.
	BSTreeNode* parent = nullptr;
	*curr = root;
	while (*curr && key != (*curr)->key && ((*curr)->left ||(*curr)->right) )
	{
		parent = *curr;
		if (key > (*curr)->key)//the key we looking for is in the right sub tree
			*curr = (*curr)->right;
		else//the key we looking for is in the left sub tree
			*curr = (*curr)->left;
	}
	if (!(*curr))
	{// the node with key "key" not found
		std::cout << "invalid input\n";
		exit(1);
	}
	return parent;
}

BSTreeNode* BSTree::Min()
{//return the node with the smallest key.
	BSTreeNode* temp = root, *parent=nullptr;
	while (temp)
	{
		parent = temp;
		temp = temp->left;
	}
	return parent;
}

BSTreeNode* BSTree::Max()
{//return the node with the bigest key.
	BSTreeNode* temp = root, *parent=nullptr;
	while (temp)
	{
		parent = temp;
		temp = temp->right;
	}
	return parent;
}

void BSTree::PrintTree()
{//print the tree in order
	if (root != nullptr)
		root->InOrder();
}

bool BSTree::isEmpty()
{
	return root;
}

void BSTree::makeEmpty()
{
	delete root;
}

const Person BSTree::BST(Person** n , int k, int & NumComp,int arrSize)
{ //runing time: worst time ϴ(n^2), avg time ϴ(nlogn).
	if(k<1 || k>arrSize)
	{
		std::cout << "invalid input\n";
		exit(1);
	}
	BSTree Tree;
	for (int i = 0; i < arrSize; ++i)// build the tree from the array.
									 //runing time: worst time ϴ(n^2), avg time ϴ(nlogn).
		Tree.Insert(*n[i], NumComp);
	BSTreeNode* curr = Tree.root;
	while (k != 0)
	{ //runing time: worst time ϴ(n), avg time ϴ(logn).
		if (curr->leftSubTreeSize == k - 1)//we found the k'th node.
			return Person(curr->data);
		else if (k <= curr->leftSubTreeSize)
			curr = curr->left;
		else// k > curr->leftSubTreeSize
		{
			k = k - curr->leftSubTreeSize - 1;
			curr=curr->right;
		}
	}
}

