#include<iostream>
using namespace std;

void print(int a[], int n ,int i)
{  
    cout<<"第"<<i+1<<"趟 : ";  
    for(int j= 0; j<8; j++){  
        cout<<a[j]<<"  ";  
    }  
    cout<<endl;  
}

void BubbleSort(int r[],int size)
{
	int i,j,temp;
	bool exchange;	//交换标志
	for(i=0;i<size;i++)
	{
		exchange=false;	//本趟排序开始前，交换标志设为假
		for(j=size-1;j>=i;--j)
			if(r[j]<r[j-1])
			{
				temp=r[j];	//暂存单元 
				r[j]=r[j-1];
				r[j-1]=temp;
				exchange=true;	//发生了交换，故将交换标志置为真 
			}
		if(!exchange)	//本趟没有发生交换，提前终止算法 
			return;
		print(r,size,i);
	}
}

int main()
{
	int r[10]={3,1,5,7,3,4,6,9,8,2};
	cout<<"原始序列：";
	for(int i=0;i<10;i++)
	{
		cout<<r[i];
		if(i==9)
			cout<<endl;
		else
			cout<<"  ";
	}
	BubbleSort(r,10);
	return 0;
}
