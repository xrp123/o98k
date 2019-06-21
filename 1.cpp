#include<iostream>
using namespace std;
#define MaxSize 100
void jiao(int *A,int *B,int length1,int length2)
{
	int i=0;
	int c=0;
	for(i=0;i<=length1 -1;i++)
	{
		for(int j=0;j<=length2-1;j++)
		{
			if(A[i]==B[j])
			{
				cout<<A[i]<<" ";
				c++;
				break;
			}
		}
	}
	if(c==0)
		cout<<"两个数组没有交集";
	cout<<endl;
}
void bing(int *A,int *B,int length1,int length2)
{
	int *AB=new int[length1+length2];
	for(int i=0;i<length1;i++)
		AB[i]=A[i];
	for(int i=length1;i<length1+length2;i++)
		AB[i]=B[i-length1];
	int *ABC=new int[length1];
	int c=0;
	for(int i=0;i<length1;i++)
	{
		for(int j=0;j<length2;j++)
		{
			if(A[i]==B[j])
			{
				ABC[c]=A[i];
				c++;
				break;
			}
		}
	}
	if(c!=0)
	{
		int d;
		int *w=new int[length1+length2];
		int e=0;
		for(int i=0;i<length1+length2;i++)
		{
			d=0;
			for(int j=0;j<c;j++)
			{
				if(AB[i]!=ABC[j])
					d++;
			}
			if(d==c)
			{
				w[e]=AB[i];
				e++;
			}
		}
		for(int i=0;i<e;i++)
			cout<<w[i]<<" ";
		for(int i=0;i<c;i++)
			cout<<ABC[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=0;i<length1+length2;i++)
			cout<<AB[i]<<" ";
		cout<<endl;
	}
}
void main()
{
	int length1,length2;
	cout<<"请输入两个数组的长度"<<endl;
	cin>>length1>>length2;
	int *p1=new int[length1];
	int *p2=new int[length2];
	cout<<"请输入第一数组的数值"<<endl;
	for(int i=0;i<length1;i++)
		cin>>p1[i];
	cout<<"请输入第二数组的数值"<<endl;
	for(int i=0;i<length2;i++)
		cin>>p2[i];
	cout<<"两个数组的交集为"<<endl;
	jiao(p1,p2,length1,length2);
	cout<<"两个数组的并集为"<<endl;
	bing(p1,p2,length1,length2);
}