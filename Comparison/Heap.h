#ifndef _HEAP_H_
#define _HEAP_H_

class Person;

class Heap
{
private:
	Person** pArr;
	int maxSize;
	int heapSize;
	static int left(int node);
	static int right(int node);
	static int parent(int node);
	void fixHeap(int node,int& counter);

public:
	Heap(Person** pArr, int pArrSize,int& counter);
	~Heap();
	Person min();
	Person deleteMin(int& counter);
	void insert(Person& p,int& counter);
	bool isEmpty();
	void makeEmpty();

	static const Person & selectHeap(Person** pArr ,int pArrSize, int k, int &NumComp);

};

template<class T>
void swap(T & p1, T & p2)
{
	T temp = p1;
	p1 = p2;
	p2 = temp;
}

#endif // !_HEAP_H_
