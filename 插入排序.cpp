#include<iostream>
using namespace std;

void insertion_sort(int A[], int size)
{
	int i, j, key;
	// note that array element start from index 0 
	for(int j = 1; j < size; ++j)
	{
		key = A[j];
		// insert A[j] into the sorted sequence A[1...j-1]
		i = j - 1;
		while(i >= 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
}

void print(int A[], int size)
{
	for(int i = 0; i < size; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main()
{
	int testArray[] = {5, 2, 4, 6, 1, 3};
	int ArraySize = 6;
	insertion_sort(testArray, ArraySize);
	print(testArray, ArraySize);
	return 0;
}
