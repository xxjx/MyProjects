#include<iostream>
#include"life.h"
using namespace std;

void life::initialize()
{
	

	int row,line;
	for(row=0;row<=maxrow+1;row++)
		for(line=0;line<=maxline+1;line++)
			gr[row][line]=0;
		cin>>row>>line;
		while(row!=-1&&line!=-1)
		{	
			gr[row][line]=1;
			cin>>row>>line;
		}
}
int life::neighbor_count(int row,int line)
{
	int g,f;
	int total=0;
	for(g=row-1;g<=row+1;g++)
		for(f=line-1;f<=line+1;f++)
			total+=gr[g][f];
	 	total-=gr[row][line];
		return total;
}
void life::update()
{
	int row,line;
	int new_gr[maxrow+2][maxline+2];
	for(row=1;row<=mrow;row++)
	{
		for(line=1;line<=mline;line++)
		{
			if(neighbor_count( row,line)==2)
				new_gr[row][line]=grid[row][line];
			else if(neighbor_count( row,line)==3)
				new_gr[row][line]=1;
			else
				new_gr[row][line]=0;
		}
	}
	int g=0,f;
	for(g=0;g<maxrow;g++)
		for(f=0;f<maxline;f++)
			gr[g][f]=new_gr[g][f];
}
void Life::print()
{ 
	   	int i,j;
	for(i=1;i<=maxrow;i++)
	{
		for(j=1;j<=maxline;j++)
	
			if(gr[i][j]==0)
				cout<<'-';
			else
				cout<<'*';
	
		cout<<endl;
	}
   cout << endl;

  
}
