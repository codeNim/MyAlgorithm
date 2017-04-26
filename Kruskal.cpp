#include<iostream>
#include<algorithm>
using namespace std;
// 最大边的数量 
const int MAXE = 20000;
// 最大顶点的数量
const int MAXV = 20000; 
// 边的结构体 
struct edge
{
	int u, v, cost;
};

// 数组，用来保存所有的边 
edge road[MAXE];
// 数组，用来保存对应顶点的终点 
int endpoint[MAXV];

// sort需要的比较函数 
bool cmp(const edge &e1, const edge &e2)
{  
    return e1.cost<e2.cost;  
}

// find函数返回顶点x的终点 
int find(int x)
{  
    if (endpoint[x] == x) return x;  
    else return endpoint[x] = find(endpoint[x]);  
}  

// unite函数的结果是将顶点x和顶点y加入到最小生成树中 
void unite(int x, int y)
{  
    x = find(x);  
    y = find(y);  
    // 终点一样则不发生变化 
    if (x == y) return;  
    // 否则，修改x的终点为y 
    else endpoint[x] = y;  
}  

// init函数的结果是将所有顶点的终点初始化为自己 
void init(int vexnum)
{
	for(int i=0;i<vexnum;++i)
		endpoint[i] = i;
}

int KRUSKAL(int vexnum, int edgenum)
{
	// ans用于记录最小生成树的总权值 
	int ans = 0;
	// 初始化每个顶点的终点为它自己
	init(vexnum);
	//  对边的权值从小到大进行排序
	sort(road, road+edgenum, cmp);
	for(int i=0;i<edgenum;i++){  
        if(find(road[i].u)!=find(road[i].v)){  
        	// 将边(u,v)加入到最小生成树中
            // 修改顶点u的终点;
            unite(road[i].u, road[i].v);  
            ans += road[i].cost;  
        }  
    }
	return ans;
}

int main()
{
	int vexnum, edgenum;
	cin>>vexnum>>edgenum;
	for(int i=0;i<edgenum;++i)
	{
		cin>>road[i].u>>road[i].v>>road[i].cost;
	}
	cout<<KRUSKAL(vexnum, edgenum)<<endl;
	return 0;
	/*  input:
		7 11
		0 1 7
		0 3 5
		1 2 8
		1 3 9
		1 4 7
		2 4 5
		3 4 15
		3 5 6
		4 5 8
		4 6 9
		5 6 11		
		output:	
		39 		*/
}
