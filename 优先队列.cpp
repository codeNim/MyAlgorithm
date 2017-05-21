#include<iostream>
using namespace std;

const int minusINF = -9527;

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

int heap_maximum(int A[])
{
	return A[0];
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

int heap_extract_max(int A[], int &heap_size)
{
	if(heap_size < 1)
		throw "heap underflow";
	int max = A[0];
	A[0] = A[heap_size-1];
	--heap_size;
	max_heapify(A, heap_size, 0);
	return max;
}

void heap_increase_key(int A[], int i, int key)
{
	if(key < A[i])
		throw "new key is smaller than current key";
	A[i] = key;
	while(i > 0 && A[parent(i)] < A[i])
	{
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}

void max_heap_insert(int A[], int &heap_size, int key)
{
	++heap_size;
	A[heap_size-1] = minusINF;
	heap_increase_key(A, heap_size-1, key);
}

void build_max_heap(int A[], int &heap_size, int length)
{
	heap_size = length;
	for(int i = length / 2 - 1; i >= 0; --i)
		max_heapify(A, heap_size, i);
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
	int heap_size;
	cout<<"原始数组：";
	print(A, length);
	build_max_heap(A, heap_size, length);
	cout<<"优先队列：";
	print(A, heap_size);
	cout<<"队头："<<heap_maximum(A)<<endl;
	cout<<"去掉队头："<<heap_extract_max(A, heap_size)<<endl;
	cout<<"优先队列：";
	print(A, heap_size);
	heap_increase_key(A, 8, 15);
	cout<<"增加第9个元素的值到15：";
	print(A, heap_size);
	max_heap_insert(A, heap_size, 5);
	cout<<"插入一个元素5：";
	print(A, heap_size);
	return 0;
}
