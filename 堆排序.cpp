#include<iostream>
using namespace std;

int parent(int i)
{
	return (i - 1) >> 1;
}

int left(int i)
{
	return (i << 1) + 1;
}

int right(int i)
{
	return (i << 1) + 2;
}

void max_heapify(int A[], int heap_size, int i)
{
	int l = left(i);
	int r = right(i);
	int largest;
	if(l < heap_size && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if(r < heap_size && A[r] > A[largest])
		largest = r;
	if(largest != i)
	{
		swap(A[i], A[largest]);
		max_heapify(A, heap_size, largest);
	}
}

void build_max_heap(int A[], int &heap_size, int length)
{
	heap_size = length;
	for(int i = length / 2 - 1; i >= 0; --i)
		max_heapify(A, heap_size, i);
}

void heapsort(int A[], int length)
{
	int heap_size;
	build_max_heap(A, heap_size, length);
	for(int i = length - 1; i >= 1; --i)
	{
		swap(A[0], A[i]);
		--heap_size;
		max_heapify(A, heap_size, 0);
	}
}

void print(int A[], int length)
{
	for(int i = 0; i < length; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main()
{
	int A[]={4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int length=(sizeof(A))/(sizeof(A[0]));
	heapsort(A, 10);
	print(A, 10);
	return 0;
}
