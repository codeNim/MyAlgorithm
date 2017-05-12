#include<iostream>
using namespace std;

const int INF = 9527;

void printArray(int A[], int size)
{
	for(int i = 0; i < size; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

void merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1+1], R[n2+1];
	for(int i = 1; i <= n1; ++i)
	{
		L[i] = A[p+i-1];
		R[i] = A[q+i];
	}
	L[n1+1] = R[n2+1] = INF;
	int i = 1;
	int j = 1;
	for(int k = p; k <= r; ++k)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i++];
		}
		else
		{
			A[k] = R[j++];
		}
	}
}

void merge_sort(int A[], int p, int r)
{
	if(p < r)
	{
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main()
{
	int testArray[] = {5, 2, 4, 7, 1, 3, 2, 6};
	merge_sort(testArray, 0, 7);
	printArray(testArray, 8);
	return 0;
}
