#include<iostream>
#include"Board.h"
using namespace std;
Move::Move()
{
	row=3;
	col=3;
}
Move::Move(int r,int c)
{
	row=t;
	col=c;
}
Board::Board()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			squares[i][j]=0;
		moves_done=0;
}
bool Board::done()const
{
	if(moves_done==9||the_winner()>0)
		return true;
	else
		return false;
}
void Board::print()const
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<" "<<square[i][j];
		cout<<" "<<endl; 
	}
}
bool Board::better(int value,int old_value)const
{
	if(moves_done%2) return value<old_value;
	else return value>old_value;
}
int Board::the_winner()const
{
	int i;
	for(i=0;i<3;i++){
		if(squares[i][0]&&squares[i][0]==squares[i][1]&&squares[i][0]==squares[i][2])
			return squares[i][0];
	}
	for(i=0;i<3;i++)
	{
		if(squares[0][i]&&squares[0][i]==squares[1][i]&&squares[0][i]==squares[2][i])
			return squares[0][i];
	}
	if(squares[0][0]&&squares[0][0]==square[1][1]&&squares[2][2]==squares[0][0])
		return squares[0][0];
	if(squares[2][0]&&squares[2][0]==squares[1][1]&&squares[2][0]==squares[0][2])
		return squares[2][0];
}
int Board::evaluate()const
{	
	int winner=the_winner();
	if(winner==1)return 10-moves_done;
	else if(winner==2) return moves_done-10;
	else return 0;
}

int worst_case()const
{
	if(moves_done%2)return 1;
	else return -1;
}
int Board::legal_moves(Mystack<Move>&moves)const
{
	int count=0;
	while(!move.empty())moves.pop();
	for(int i=0;i<3;i++)
		for(int j=0; j<3; j++)
			if(squares[i][j]==0){
				Move can_play(i,j);
				move.push(can_play);
				count++;
			}
			return count;
}
void Board::play(Move try_it)
{
	squares[try_it.row][try_it.col]=moves_done%2+1;
	moves_done++;
}

	



