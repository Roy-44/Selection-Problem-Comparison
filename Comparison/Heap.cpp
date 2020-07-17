#include "Heap.h"
#include"Person.h"

int Heap::left(int node)
{//return the left child index
	return 2*node+1;
}

int Heap::right(int node)
{//return the right child index
	return 2*node+2;
}

int Heap::parent(int node)
{//return the parent index
	return (node-1)/2;
}

void Heap::fixHeap(int node,int& counter)
{// fix the heap form the node "node" to bottom
 //runing time: worst time ϴ(logn), avg time ϴ(logn).
	int min;
	int left = this->left(node);
	int right = this->right(node);
	if (left < heapSize && pArr[left]->GetID()<pArr[node]->GetID())//left child got smaller key then parent key
		min = left;
	else//left child is not exist or got bigger key then parent key
		min = node;
	if(left<heapSize)
		++counter;
	if (right<heapSize && pArr[right]->GetID()<pArr[min]->GetID())//right child got smaller key then parent key
		min = right;
	if (right < heapSize)
		++counter;
	if (min != node)//node key is biger then one of his childern 
	{
		swap(pArr[node], pArr[min]);
		fixHeap(min,counter);
	}
}

Heap::Heap(Person ** pArr, int pArrSize,int& counter)
{//runing time: worst time ϴ(nlogn), avg time ϴ(nlogn).
	this->pArr = pArr;
	heapSize = maxSize = pArrSize;
	for (int i = pArrSize / 2 - 1; i >= 0; i--) 
		fixHeap(i,counter);
}

Heap::~Heap()
{
	pArr = nullptr;
}

Person Heap::min()
{//return the person with the lowest key.
	if (heapSize < 1)
	{
		std::cout << "invalid input\n";
		exit(1);
	}
	return *pArr[0];
}

Person Heap::deleteMin(int& counter)
{//"delete" the node with lowest key ,return the node data and count how many comparisons made
	if (heapSize < 1)
	{
		std::cout << "invalid input\n";
		exit(1);
	}
	Person temp = *pArr[0];
	--heapSize;
	*pArr[0] = *pArr[heapSize];
	fixHeap(0,counter);
	return temp;
}

void Heap::insert(Person & p,int& counter)
{//insert new node to the heap and count how many comparisons made
	if (heapSize == maxSize)
	{
		std::cout << "invalid input\n";
		exit(1);
	}
	int i = heapSize++;
	while (i > 0 && pArr[parent(i)]->GetID() > p.GetID())
	{
		++counter;
		*pArr[i] = *pArr[parent(i)];
		i = parent(i);
	}
	if (i != 0)
		++counter;
	*pArr[i] = p;
}

bool Heap::isEmpty()
{
	return heapSize;
}

void Heap::makeEmpty()
{
	heapSize = 0;
}

const Person & Heap::selectHeap(Person** pArr, int pArrSize, int k, int & NumComp)
{ //runing time: worst time ϴ(nlogn), avg time ϴ(nlogn). because k<=n
	if (k<1 || k>pArrSize)
	{
		std::cout << "invalid input\n";
		exit(1);
	}
	Heap heap(pArr, pArrSize, NumComp);
	for (int i = 0; i < k - 1; i++)
		heap.deleteMin(NumComp);
	return heap.deleteMin(NumComp);
}
