#include<iostream>
using namespace std;

void print(int a[], int n ,int i)
{  
    cout<<"��"<<i+1<<"�� : ";  
    for(int j= 0; j<8; j++){  
        cout<<a[j]<<"  ";  
    }  
    cout<<endl;  
}

void BubbleSort(int r[],int size)
{
	int i,j,temp;
	bool exchange;	//������־
	for(i=0;i<size;i++)
	{
		exchange=false;	//��������ʼǰ��������־��Ϊ��
		for(j=size-1;j>=i;--j)
			if(r[j]<r[j-1])
			{
				temp=r[j];	//�ݴ浥Ԫ 
				r[j]=r[j-1];
				r[j-1]=temp;
				exchange=true;	//�����˽������ʽ�������־��Ϊ�� 
			}
		if(!exchange)	//����û�з�����������ǰ��ֹ�㷨 
			return;
		print(r,size,i);
	}
}

int main()
{
	int r[10]={3,1,5,7,3,4,6,9,8,2};
	cout<<"ԭʼ���У�";
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
