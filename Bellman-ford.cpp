#include<iostream>
using namespace std;

const int maxv = 101;
const int maxe = 4001;
const int INF = 2147483647;

// 边的结构体 
struct edge
{
	int u, v;
	int weight;
};

// 数组，用于存储边 
edge road[maxe];
// 数组，用于存储源点到各顶点的距离 
int dist[maxv];
// 顶点和边的数目 
int vnum, edgenum;
// 源点 
int source = 1;

void init()
{
	for(int i=1;i<=vnum;++i)
		dist[i] = INF;
	dist[source] = 0;
	for(int i=1;i<=edgenum;++i)
	{
		cin>>road[i].u>>road[i].v>>road[i].weight;
		if(road[i].u==source)
			dist[road[i].v] = road[i].weight;
	}
}

// 松弛操作 
void relax(int u, int v, int weight)
{
	if(dist[v] > dist[u] + weight)
		dist[v] = dist[u] + weight;
}

bool Bellman_Ford()
{
	for(int i=1;i<=vnum-1;++i)
		for(int j=1;j<=edgenum;++j)
		{
			relax(road[j].u, road[j].v, road[j].weight);
		}
	for(int i=1;i<=edgenum;++i)
	{
		if(dist[road[i].v] > dist[road[i].u] + road[i].weight)
			return false;
	}
	return true;
}

int main()
{
	while(cin>>vnum>>edgenum)
	{
		init();
		if(Bellman_Ford())
		{
			cout<<dist[edgenum]<<endl;	
		}
		else
		{
			cout<<"存在负权环"<<endl;
		}
	}
	/*	input:
		3 3
		1 2 3
		2 3 2
		1 3 6 
		output:
			5  */
	return 0;
}
