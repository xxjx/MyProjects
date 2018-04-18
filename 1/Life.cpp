  #include<iostream>
#include"Life.h"
using namespace std;

void Life::initialize()
{
	

	int row,line;
	for(row=0;row<=mrow+1;row++)
		for(line=0;line<=mline+1;line++)
			grid[row][line]=0;
		cin>>row>>line;
		while(row!=-1&&line!=-1)
		{	
			grid[row][line]=1;
			cin>>row>>line;
		}
}
int Life::neighbor_count(int row,int line)
{
	int i,j;
	int total=0;
	for(i=row-1;i<=row+1;i++)
		for(j=line-1;j<=line+1;j++)
			total+=grid[i][j];
	 	total-=grid[row][line];
		return total;
}
void Life::update()
{
	int row,line;
	int new_grid[mrow+2][mline+2];
	for(row=1;row<=mrow;row++)
	{
		for(line=1;line<=mline;line++)
		{
			if(neighbor_count( row,line)==2)
				new_grid[row][line]=grid[row][line];
			else if(neighbor_count( row,line)==3)
				new_grid[row][line]=1;
			else
				new_grid[row][line]=0;
		}
	}
	int i=0,j;
	for(i=0;i<mrow;i++)
		for(j=0;j<mline;j++)
			grid[i][j]=new_grid[i][j];
}
void Life::print()
{ 
	   	int i,j;
	for(i=1;i<=mrow;i++)
	{
		for(j=1;j<=mline;j++)
	
			if(grid[i][j]==0)
				cout<<'-';
			else
				cout<<'*';
	
		cout<<endl;
	}
   cout << endl;

  
}
