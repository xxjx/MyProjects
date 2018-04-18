#include<iostream>
#include"Life.h"
using namespace std;
void Life::initialize()
{
	int i,line;
	for(i=0;i<=mline+3;i++)
		array[i]=0;
	cout<<"put the chess pieces"<<endl;
	cout<<"The game will stop if the integer is -1 "<<endl;
	cin>>line;
	while(line!=-1)
	{
		if(!cin)
		{
			cout<<"The line must be an integer"<<endl;
			cin.ignore(80,'\n');
		}
		if(line>mline||line<1)
		{
			cout<<"The line is out of the range"<<endl;
		}
		array[line+1]=1;
		cin>>line;
	}
}
int Life::count_neighbor(int line)
{
	int i,total=0;
	for(i=line-2;i<=line+2;i++)
		total=total+array[i];
	total-=array[line];
	return total;
}
void Life::update()
{
	int j;
	int new_array[mline+4];
	for(j=2;j<=mline+1;j++)
	{
		if(array[j]==0)
		{
			switch(count_neighbor(j))
			{
				case 2:
					new_array[j]=1;
					break;
				case 3:
					new_array[j]=1;
					break;
				default:
					new_array[j]=array[j];
			}
		}
		if(array[j]==1)
		{
			switch(count_neighbor(j)){
				case 0:
					new_array[j]=0;
					break;
				case 1:
					new_array[j]=0;
					break;
				case 3:
					new_array[j]=0;
					break;
				default:
					new_array[j]=array[j];
			}
		}
	}
	for(j=2;j<=mline+1;j++)
		array[j]=new_array[j];
}
void Life::print()
{
	int i;
	for(i=2;i<mline+1;i++)
	{
		if(array[i]==0)
			cout<<'-';
		else 
			cout<<'*';
	}
	cout<<endl;
}


	