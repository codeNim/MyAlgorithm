#include<iostream>
using namespace std;

const int minusINF = -9527;

typedef struct ArrayInfo
{
	int low;
	int high;
	int sum;
}ArrayInfo;

ArrayInfo find_max_crossing_subarray(int A[], int low, int mid, int high)
{
	ArrayInfo crossingArray;
	int left_sum = minusINF;
	int sum = 0;
	for(int i = mid; i >= low ; --i)
	{
		sum += A[i];
		if(sum > left_sum)
		{
			left_sum = sum;
			crossingArray.low = i;
		}
	}
	int right_sum = minusINF;
	sum = 0;
	for(int i = mid+1; i <= high ; ++i)
	{
		sum += A[i];
		if(sum > right_sum)
		{
			right_sum = sum;
			crossingArray.high = i;
		}
	}
	crossingArray.sum = left_sum + right_sum;
	return crossingArray;
}

ArrayInfo find_maximum_subarray(int A[], int low, int high)
{
	if(high == low)
	{
		ArrayInfo subarray;
		subarray.low = low;
		subarray.high = high;
		subarray.sum = A[low];
		return subarray;
	}
	else
	{
		int mid = (low + high) / 2;
		ArrayInfo leftArray = find_maximum_subarray(A, low, mid);
		ArrayInfo rightArray = find_maximum_subarray(A, mid+1, high);
		ArrayInfo crossingArray = find_max_crossing_subarray(A, low, mid, high);
		if(leftArray.sum >= rightArray.sum && leftArray.sum >= crossingArray.sum)
			return leftArray;
		else if(rightArray.sum >= leftArray.sum && rightArray.sum >= crossingArray.sum)
			return rightArray;
		else
			return crossingArray;
	}
}

int main()
{
	ArrayInfo ans;
	int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int size = 16;
	ans = find_maximum_subarray(A, 0, size-1);
	cout<<ans.sum<<" "<<ans.low<<" "<<ans.high<<endl;
	return 0;
}
