#include<iostream>
#include"square.h"
using namespace std;
void square::initialize()
{
	int x,i=0,j=1,m,n;
	while(cin>>x)
	{
		if(x==-1)
			break;
		stall[i]=x;
		i++;
	
	}
	for(j=1;j<=i;j++)
	{
		if(i==j*j)
			break;
	}
	length=j;
	i=0;
	for(m=0;m<j;m++)
		for(n=0;n<j;n++)
		{
			array[m][n]=stall[i];
			i++;
		}
}
void square::print()
{
	int m,n;
		for(m=0;m<length;m++)
		{
			for(n=0;n<length;n++)
			{
				cout<<array[m][n]<<" ";
			}
			cout<<endl;
		}
}
void square::judge()
{
	int m,n,total=0,i=0,j;
	for(m=0;m<length;m++)
	{
		for(n=0;n<length;n++)
		{
			total+=array[m][n];
		}
		stall[i]=total;
		cout<<total<<endl;
		i++;
		total=0;
	}
	for(n=0;n<length;n++)
	{
		for(m=0;m<length;m++)
		{
			total+=array[m][n];
		}
		stall[i]=total;
		cout<<total<<endl;
		i++;
		total=0;
	}
	for(m=0;m<length;m++)
	{
		total+=array[m][m];
	}
	cout<<total<<endl;
	stall[i]=total;
	i++;
	total=0;
	for(m=length-1;m>=0;m--)
	{
		total+=array[m][length-1-m];
	}
	stall[i]=total;
	i++;
	cout<<total<<endl;
	total=0;
	for(j=1;j<=length*length;j++)
	{
		total+=j;
	}
	total/=length;
	cout<<total<<endl;
	for(j=0;j<i;j++)
	{
		if(stall[j]!=total)
		{
			cout<<"No!"<<endl;
			break;
		}
		else if(j==i-1)
			cout<<"Yes!"<<endl;
	}
}








		
