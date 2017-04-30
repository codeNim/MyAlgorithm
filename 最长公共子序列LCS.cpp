#include<iostream>
#include<string.h>
using namespace std;

string s1, s2;
// ��¼�м��������� 
int num[501][501];
// ������飬���ڱ�ʶ�±�����򣬹�������������� 
// 1��ʾб���±�ǣ�2��ʾ���ұ�ǣ�3��ʾ���±�� 
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
				// б���±�� 
				flag[i][j] = 1;
			}
			else if(num[i][j-1]>num[i-1][j])
			{
				num[i][j] = num[i][j-1];
				// ���ұ�� 
				flag[i][j] = 2;
			}
			else
			{
				num[i][j] = num[i-1][j];
				// ���±�� 
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
