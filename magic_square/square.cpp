#include<iostream>
#include"square.h"
using namespace std;
void square::initialize()
{
	cout<<"Please put the line you want to write"<<endl;
	cin>>length;
	p=new int *[length];
	int m,n,k;
	for(m=0;m<length;m++)
	{
		p[m]=new int [length];
	}
	for(m=0;m<length;m++)
	{
		for(n=0;n<length;n++)
		{
			cin>>k;
		   p[m][n]=k;
		}
	}
}
void square::judge()
{
	int m,n,total=0,i=0,j;
	int *stall;
	stall=new int[2*length+2];
	for(m=0;m<length;m++)
	{
		for(n=0;n<length;n++)
			total+=p[m][n];
		stall[i]=total;
		i++;
			total=0;
	}
	total=0;
	for(n=0;n<length;n++)
	{
		for(m=0;m<length;m++)
			total+=p[m][n];
		stall[i]=total;
		i++;
			total=0;
	}
	total=0;
	for(m=0;m<length;m++)
	{
		total+=p[m][m];
	}
	stall[i]=total;
	i++;
	total=0;
	
	for(m=length-1;m>=0;m--)
	{
		total+=p[m][length-1-m];	
	}
	stall[i]=total;
	total=0;
	for(j=1;j<=length*length;j++)
	{
		total+=j;
	}
	total/=length;
	for(j=0;j<=i;j++)
	{
		if(stall[j]!=total)
		{
			cout<<"No! It is not."<<endl;
			break;
		}
		else if(j==i)
			cout<<"Yes! It is a magic square."<<endl;
	}
	delete[]stall;
}
void square::create()
{
	int i,j,x;
	cout<<"Please put the row that you want to create;"<<endl;
	cout<<"Attention:the row need to be odd!"<<endl;
	cin>>length;
	p=new int *[length];
	for(i=0;i<length;i++)
	{
		p[i]=new int [length];

	}
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			p[i][j]=0;
		}
	}
	i=0, x=1;
	j=(length-1)/2;
	p[i][j]=x;
	for(x=2;x<=length*length;x++)
	{
		if(i-1<0&&j+1<length)
		{
			i=length-1; j+=1;
			p[i][j]=x;
		} 
	    else if(i-1>=0&&j+1==length)
		{
			j=0; i--;
			p[i][j]=x;
		}
		else if(i-1>=0&&j+1<length)
		{
			i--;j++;
			if(p[i][j]!=0)
			{
				i+=2;j--;
				p[i][j]=x;
			}
			else
				p[i][j]=x;
		}
		else if(i-1<0&&j+1==length)
		{
			i++;
			p[i][j]=x;
		}
	}

}
void square::print()
{
	int m,n;
	for(m=0;m<length;m++)
	{
		for(n=0;n<length;n++)
			cout<<p[m][n]<<" ";
		cout<<endl;
	}
}
 square::~square()
{	
	int i;
	for(i=0;i<length;i++)
	{
		delete[]p[i];
	}
	delete[]p;
	cout<<"Bye!";
}

			

	









		

