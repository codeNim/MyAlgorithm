#include<iostream>
using namespace std;

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for(int j = p; j <= r-1; ++j)
	{
		if(A[j] <= x)
		{
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return i + 1;
}

void quicksort(int A[], int p, int r)
{
	if(p < r)
	{
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
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
	int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
	int length=(sizeof(A))/(sizeof(A[0]));
	quicksort(A, 0, length-1);
	print(A, length);
	return 0;
}
