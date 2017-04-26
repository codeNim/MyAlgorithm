#include<iostream>
#include<algorithm>
using namespace std;
// ���ߵ����� 
const int MAXE = 20000;
// ��󶥵������
const int MAXV = 20000; 
// �ߵĽṹ�� 
struct edge
{
	int u, v, cost;
};

// ���飬�����������еı� 
edge road[MAXE];
// ���飬���������Ӧ������յ� 
int endpoint[MAXV];

// sort��Ҫ�ıȽϺ��� 
bool cmp(const edge &e1, const edge &e2)
{  
    return e1.cost<e2.cost;  
}

// find�������ض���x���յ� 
int find(int x)
{  
    if (endpoint[x] == x) return x;  
    else return endpoint[x] = find(endpoint[x]);  
}  

// unite�����Ľ���ǽ�����x�Ͷ���y���뵽��С�������� 
void unite(int x, int y)
{  
    x = find(x);  
    y = find(y);  
    // �յ�һ���򲻷����仯 
    if (x == y) return;  
    // �����޸�x���յ�Ϊy 
    else endpoint[x] = y;  
}  

// init�����Ľ���ǽ����ж�����յ��ʼ��Ϊ�Լ� 
void init(int vexnum)
{
	for(int i=0;i<vexnum;++i)
		endpoint[i] = i;
}

int KRUSKAL(int vexnum, int edgenum)
{
	// ans���ڼ�¼��С����������Ȩֵ 
	int ans = 0;
	// ��ʼ��ÿ��������յ�Ϊ���Լ�
	init(vexnum);
	//  �Աߵ�Ȩֵ��С�����������
	sort(road, road+edgenum, cmp);
	for(int i=0;i<edgenum;i++){  
        if(find(road[i].u)!=find(road[i].v)){  
        	// ����(u,v)���뵽��С��������
            // �޸Ķ���u���յ�;
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
