#include<iostream>
using namespace std;

int dp[500];
int seq[500];
int slen;
int LISlen;

int binSearch(int array[], int arraySize, int value)
{
	int left = 0;
	int right = arraySize-1;
	int mid;
	while(left<right)
	{
		mid = (right+left)/2;
		if(array[mid]<=value)
			left = mid+1;
		else
			right = mid-1;
	}
	return left;
}

void LIS()
{
	dp[0] = seq[0];
	LISlen = 1;
	int k = 0;
	for(int i=1;i<slen;++i)
	{
		if(seq[i]>dp[LISlen-1])
		{
			dp[LISlen++] = seq[i];
		}
		else
		{
			int pos = binSearch(dp, LISlen, seq[i]);
			dp[pos] = seq[i];
		}
	}
	cout<<LISlen<<endl;
}

int main()
{
	cin>>slen;
	for(int i=0;i<slen;++i)
		cin>>seq[i];
	LIS();
	/* input: 16
	          0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
		output: 6  */
	return 0;
}
