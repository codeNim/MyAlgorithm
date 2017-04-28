#include<iostream>
using namespace std;

const int INF = 999999;
const int MAXV = 10000;
int vnum, edgenum, start;

// 邻接矩阵 
int edge[MAXV][MAXV];
// 记录Vnew中每个点到V中邻接点的最短边
int lowcost[MAXV];
// 标记某点是否加入Vnew
int addVnew[MAXV];
// 记录V中与Vnew最邻近的点
int adj[MAXV];

void prim(int start)
{
	// 最小生成树的权值 
	int sumweight = 0;
	int i, j;
	int k = 0;
	for(i=1;i<=vnum;++i)
	{
		lowcost[i] = INF;
		adj[i] = start;		
	}
	// 顶点从1开始 
	for(i=1;i<=vnum;++i)
	{
		// 将所有点至于Vnew之外,V之内
		// 这里只要addVnew对应的值为-1，就表示在Vnew之外
		lowcost[i] = edge[start][i];
		addVnew[i] = -1;
	}
	// 将起始点start加入Vnew
	addVnew[start] = 0;
	adj[start] = start;
	for(i=1;i<=vnum;++i)
	{
		// 由于从start开始的，因此不需要再对第start个顶点进行处理
		if(start==i)
			continue;
		int min = INF;
		int v = -1;
		for(j=1;j<=vnum;++j)
		{
			// 在Vnew之外寻找最短路径
			if(addVnew[j]==-1 && lowcost[j]<min)
			{
				min = lowcost[j];
				v = j;
			}
		}
		if(v!=-1)
		{
			// 输出新加入的边 
			cout<<adj[v]<<" "<<v<<" "<<lowcost[v]<<endl;
			// 将v加Vnew中
			addVnew[v] = 0;
			// 计算路径长度之和
			sumweight += lowcost[v];
			for(j=1;j<=vnum;++j)
			{
				if(addVnew[j]==-1 && edge[v][j]<lowcost[j])
				{
					// 此时v点加入Vnew 需要更新lowcost
					lowcost[j] = edge[v][j];
					adj[j] = v;
				}
			}
		}
	}
	// 输出最小生成树的权值 
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
