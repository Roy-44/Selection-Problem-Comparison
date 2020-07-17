//Operating Instructions:
//enter the number of persons you want to insert and press enter.
//enter the person's ID, press space, enter the person's first name, press enter, enter the person's last name
//and press enter.
//enter the k'th person you want to find and press enter.
//the programm will show the k'th person and the numer of comparisons in evrry function.
#include"BSTree.h"
#include"Person.h"
#include"BSTreeNode.h"
#include"Heap.h"
#include <stdlib.h>
#include <time.h>


const Person & RandSelection(Person** pArr ,int pArrSize, int k, int &NumComp);
Person Select(Person** pArr, int left, int right, int k, int& NumComp);
int partition(Person** pArr, int left, int right, int& NumComp);
void checkID(Person** pArr, int ID, int i);

int main()
{
	int size;
	int ID;
	std::string name;
	std::cin >> size;
	Person** pArr = new Person* [size];
	Person** tempArr = new Person*[size];
	for (int i = 0; i < size; i++)
	{//fill the array pArr
		std::cin >> ID;
		checkID(pArr,ID,i);
		std::cin >> name;
		pArr[i] = new Person(ID, name);
		tempArr[i] = new Person(ID, name);
	}
	int k;
	std::cin >> k;
	int randCounter = 0, BSTcounter = 0, heapCounter = 0;
	Person temp(BSTree::BST(pArr, k, BSTcounter, size));
	Heap::selectHeap(tempArr, size, k, heapCounter);
	RandSelection(pArr, size, k, randCounter);
	std::cout <<"\n"<<temp.GetID() << " " << temp.GetName() << "\n" << "RandSelection: " << randCounter << " comparisons\n"
		<< "selectHeap: " << heapCounter << " comparisons\n" << "BST: " << BSTcounter << " comparisons\n";
	for (int i = 0; i < size; i++)
	{
		delete pArr[i];
		delete tempArr[i];
	}
	delete[] pArr;
	delete[] tempArr;
}

const Person & RandSelection(Person** pArr, int pArrSize, int k, int &NumComp)
{ //runing time: worst time ϴ(n^2), avg time ϴ(n).
	return Select(pArr, 0, pArrSize-1, k,NumComp);
}

Person Select(Person** pArr, int left, int right, int k,int& NumComp)
{// an auxiliary function for RandSelection.
 //runing time: worst time ϴ(n^2), avg time ϴ(n).
	int pivot = partition(pArr, left,right, NumComp);
	int leftPart = pivot - left + 1;
	if (k == leftPart)
		return *pArr[pivot];
	if (k < leftPart)
		return Select(pArr, left, pivot - 1, k,NumComp);
	else
		return Select(pArr, pivot + 1, right, k - leftPart,NumComp);
}

int partition(Person** pArr,int left,int right,int& NumComp)
{//pick a random pivot and arrange the array pArr so that the numbers that smaller the pivot will be left from pivot.
 //runing time: worst time ϴ(n), avg time ϴ(n).
	srand((unsigned)time(NULL));
	int pivot = left + (rand() % (right - left + 1));
	int other = right;
	swap(*pArr[pivot], *pArr[left]);
	pivot = left;
	while (pivot != other)
	{
		++NumComp;
		if ((other > pivot && pArr[pivot]->GetID() > pArr[other]->GetID())
			|| (other < pivot && pArr[pivot]->GetID() < pArr[other]->GetID()))
		{
			swap(*pArr[pivot], *pArr[other]);
			swap(pivot, other);
		}
		if (pivot < other)
			--other;
		else
			++other;
	}
	return pivot;
}

void checkID(Person** pArr,int ID,int i)
{//print error message if the ID is already exist.
	for (int j = 0; j < i; j++)
		if (pArr[j]->GetID() == ID)
		{
			std::cout << "invalid input\n";
			exit(1);
		}
}

