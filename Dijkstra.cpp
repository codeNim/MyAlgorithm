#include<iostream>
using namespace std;

const int INF = 32767;
const int MAXV = 100;
int dist[MAXV];
int prev[MAXV];
int vnum, edgenum, start, end;
int A[MAXV][MAXV];

void Dijkstra(int start, int end)
{
	// 判断是否已存入该点到S集合中
	bool S[MAXV];
	for(int i=1;i<=vnum;++i)
	{
		dist[i] = A[start][i];
		S[i] = false;
		if(dist[i]==INF)
			prev[i] = -1;
		else
			prev[i] = start;
	}
	dist[start] = 0;
	S[start] = true;
	for(int i=2;i<=vnum;++i)
	{
		int mindist = INF;
		int u = start;
		for(int j=1;j<=vnum;++j)
		{
			if(!S[j] && dist[j]<mindist)
			{
				u = j;
				mindist = dist[j];
			}
		}
		S[u] = true;
		for(int j=1;j<=vnum;++j)
		{
			if(!S[j] && A[u][j]<INF)
			{
				if(dist[u]+A[u][j]<dist[j])
				{
					dist[j] = dist[u] + A[u][j];
					prev[j] = u;
				}
			}
		}
	}
	// 回溯出start到end的最短路径 
	int k = end;
	while(prev[k]!=-1)
	{
		if(k==prev[k])
			break;
		cout<<prev[k]<<" "<<k<<" "<<A[prev[k]][k]<<endl;
		k = prev[k];
	}
}

int main()
{
	while(cin>>vnum>>edgenum>>start>>end)
	{
		int p, q, val;
		for(int i=1;i<=vnum;++i)
		{
			for(int j=1;j<=vnum;++j)
			{
				if(i==j)
					A[i][j] = 0;
				else
					A[i][j] = INF;
			}
		}
		for(int i=1;i<=edgenum;++i)
		{
			cin>>p>>q>>val;
			A[p][q] = val;
			A[q][p] = val;
		}
		Dijkstra(start, end);
	}
	return 0;
}
