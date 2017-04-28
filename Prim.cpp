#include<iostream>
using namespace std;

const int INF = 999999;
const int MAXV = 10000;
int vnum, edgenum, start;

// �ڽӾ��� 
int edge[MAXV][MAXV];
// ��¼Vnew��ÿ���㵽V���ڽӵ����̱�
int lowcost[MAXV];
// ���ĳ���Ƿ����Vnew
int addVnew[MAXV];
// ��¼V����Vnew���ڽ��ĵ�
int adj[MAXV];

void prim(int start)
{
	// ��С��������Ȩֵ 
	int sumweight = 0;
	int i, j;
	int k = 0;
	for(i=1;i<=vnum;++i)
	{
		lowcost[i] = INF;
		adj[i] = start;		
	}
	// �����1��ʼ 
	for(i=1;i<=vnum;++i)
	{
		// �����е�����Vnew֮��,V֮��
		// ����ֻҪaddVnew��Ӧ��ֵΪ-1���ͱ�ʾ��Vnew֮��
		lowcost[i] = edge[start][i];
		addVnew[i] = -1;
	}
	// ����ʼ��start����Vnew
	addVnew[start] = 0;
	adj[start] = start;
	for(i=1;i<=vnum;++i)
	{
		// ���ڴ�start��ʼ�ģ���˲���Ҫ�ٶԵ�start��������д���
		if(start==i)
			continue;
		int min = INF;
		int v = -1;
		for(j=1;j<=vnum;++j)
		{
			// ��Vnew֮��Ѱ�����·��
			if(addVnew[j]==-1 && lowcost[j]<min)
			{
				min = lowcost[j];
				v = j;
			}
		}
		if(v!=-1)
		{
			// ����¼���ı� 
			cout<<adj[v]<<" "<<v<<" "<<lowcost[v]<<endl;
			// ��v��Vnew��
			addVnew[v] = 0;
			// ����·������֮��
			sumweight += lowcost[v];
			for(j=1;j<=vnum;++j)
			{
				if(addVnew[j]==-1 && edge[v][j]<lowcost[j])
				{
					// ��ʱv�����Vnew ��Ҫ����lowcost
					lowcost[j] = edge[v][j];
					adj[j] = v;
				}
			}
		}
	}
	// �����С��������Ȩֵ 
	cout<<sumweight<<endl;
}

int main()
{
	while(cin>>vnum>>edgenum>>start)
	{
		for(int i=1;i<=vnum;++i)
		{
			for(int j=1;j<=vnum;++j)
			{
				if(i==j)
					edge[i][j] = 0;
				else
					edge[i][j] = INF;
			}
		}
		int p, q, val;
		for(int i=1;i<=edgenum;++i)
		{
			cin>>p>>q>>val;
			edge[p][q] = val;
			edge[q][p] = val;
		}
		prim(start);
	}
	return 0;
	/*  input: 	7 11 4
				1 2 7
				1 4 5
				2 3 8
				2 4 9
				2 5 7
				3 5 5
				4 5 15
				4 6 6
				5 6 8
				5 7 9
				6 7 11
		output:
				4 1 5
				4 6 6
				1 2 7
				2 5 7
				5 3 5
				5 7 9
				39  */
}
