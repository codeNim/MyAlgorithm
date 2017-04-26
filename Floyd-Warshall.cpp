#include<iostream>
using namespace std;

const int maxv = 105;
const int maxe = 10005;
// INF��ʾ�޷����� 
const int INF = 99999;

int vnum, edgenum, q, source, final;
int A[maxv][maxv];

struct graph
{
	int v[maxv];
	int edges[maxv][maxv];
	int n, e;
};

void Floyd(graph g)
{
	for(int i=1;i<=g.n;++i)
	{
		for(int j=1;j<=g.n;++j)
		{
			A[i][j] = g.edges[i][j];
		}
	}
	for(int k=1;k<=g.n;++k)
	{
		for(int i=1;i<=g.n;++i)
		{
			for(int j=1;j<=g.n;++j)
			{
				if(A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
	for(int i=0;i<q;++i)
	{
		// ����Դ�㡢�յ� 
		cin>>source>>final;
		if(A[source][final]==INF)
			cout<<"�޷�����"<<endl;
		else
			cout<<A[source][final]<<endl;
	}
}

int main()
{
	graph g;
	// ���붥���������������ʴ��� 
	while(cin>>g.n>>g.e>>q)
	{
		// ��ʼ������ 
		for(int i=1;i<=g.n;++i)
		{
			for(int j=1;j<=g.n;++j)
			{
				if(i==j)
					g.edges[i][j] = 0;
				else g.edges[i][j] = INF;
			}
		}
		int p, q, val;
		for(int i=1;i<=g.e;++i)
		{
			cin>>p>>q>>val;
			if(g.edges[p][q]==INF)
				g.edges[p][q] = val;
			else
			{
				// ���Ƕ��رߵ�������洢Ȩֵ��С�ı� 
				if(val <= g.edges[p][q])
				{
					g.edges[p][q] = val;
				}
				else
				{
					g.edges[p][q] = g.edges[p][q];
				}
			}
		}
		Floyd(g);
	}
	/* input:
		4 3 2
		1 2 3
		2 3 4
		2 4 3
		1 3
		2 4
		outptut:
		7
		3	*/
	return 0;
}
