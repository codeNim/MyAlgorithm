#include<iostream>
#include<string.h>
using namespace std;

string s1, s2;
// 记录中间结果的数组 
int num[501][501];
// 标记数组，用于标识下标的走向，构造出公共子序列 
// 1表示斜向下标记，2表示向右标记，3表示向下标记 
int flag[501][501];

void LCS()
{
	int i, j;
	for(i=1;i<=s1.size();++i)
	{
		for(j=1;j<=s2.size();++j)
		{
			if(s1[i-1]==s2[j-1])
			{
				num[i][j] = num[i-1][j-1]+1;
				// 斜向下标记 
				flag[i][j] = 1;
			}
			else if(num[i][j-1]>num[i-1][j])
			{
				num[i][j] = num[i][j-1];
				// 向右标记 
				flag[i][j] = 2;
			}
			else
			{
				num[i][j] = num[i-1][j];
				// 向下标记 
				flag[i][j] = 3;
			}
		}
	}
}

void getLCS()
{
	string res = "";
	int i = s1.size();
	int j = s2.size();
	while(i>0 && j>0)
	{
		if(flag[i][j]==1)
		{
			res = s1[i-1] + res;
			--i;
			--j;
		}
		else if(flag[i][j]==2)
		{
			--j;
		}
		else if(flag[i][j]==3)
		{
			--i;
		}
	}
	cout<<res<<endl;
}

int main()
{
	while(cin>>s1>>s2)
	{
		LCS();
		getLCS();
	}
	return 0;
}
