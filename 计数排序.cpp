#include<iostream>
using namespace std;

void print(int A[], int length)
{
	for(int i = 0; i < length; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

void counting_sort(int A[], int B[], int length, int k)
{
	int C[k];
	for(int i = 0; i <= k; ++i)
	{
		C[i] = 0;
	}
	for(int i = 0; i < length; ++i)
	{
		C[A[i]] = C[A[i]] + 1;
	}
	for(int i = 1; i <= k; ++i)
	{
		C[i] = C[i] + C[i-1];
	}
	for(int i = length-1; i >= 0; --i)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
}

int main()
{
	int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
	int length=(sizeof(A))/(sizeof(A[0]));
	int k = 5;
	int B[length];
	counting_sort(A, B, length, k);
	print(B, length);
	return 0;
}
