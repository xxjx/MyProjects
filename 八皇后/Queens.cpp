#include"Queens.h"
#include<iostream>
using namespace std;
Queens::Queens(int size)
{
	board_size=size;
	count=0;
	for(int row=0;row<board_size;row++)
		for(int col=0;col<board_size;col++)
			queen_square[row][col]=false;
}
void Queens::insert(int col)//ÐÐÓÉcount¿ØÖÆ
{
	queen_square[count++][col]=true;
}
bool Queens::unguarded(int col)const
{
	int n;
	bool state=true;
	for( n=0;state&&n<count;n++)
		state=!queen_square[n][col];
	for( n=1;state&&count-n>=0&&col-n>=0;n++)
		state=!queen_square[count-n][col-n];
	for( n=1;state&&count-n>=0&&col+n<board_size;n++)
		state=!queen_square[count-n][col+n];
	return state;
}
bool Queens::is_solved()const
{
	return (count==board_size);
}
void Queens::remove(int col)
{
	queen_square[--count][col]=false;
}
void Queens::print()const
{
	for(int i=0;i<board_size;i++)
	{
		for(int j=0;j<board_size;j++)
		{
			if(queen_square[i][j]==true)
				cout<<"*";
			else
				cout<<"-";
		}
		cout<<endl;
	}
}
