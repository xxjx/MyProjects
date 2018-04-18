#include<iostream>
#incl ude"Board.h"
#include"Mystack.cpp"
int look_ahead(const Board&game, int depth ,Move&recommended)
{
	if(game.done()||depth==0)
		return game.evaluate();
	else 
	{
		Mystack<move>moves;
		int value,best_value=game.worst_case();
		game.legal_moves(moves);
		while(!moves.empty())
		{
			Move try_it,reply;
			moves.top(try_it);
			game.play(try_it);
			Board new_game=game;
			value=look_ahead(new_game,depth-1,reply);
			if(game.better(value,new_value))
			{
				new_value=value;
				recommended=try_it;
			}
			moves.pop();
		}
		return new_value;
}
void main(){
	Board game;
	Move recommended;
	int x,y;
	int i=9;
	game.instructions();
	while(!game.done()){
		cout<<"Your turn :"<<endl;
		cout<<"X:";
		cin>>x;
		cout<<"Y:";
		cin>>y;
		Move me(x,y);
		game.play(me);
		game.print();
		if(game.done())break;
		look_ahead(game,i-1,recommended);
		game.play(recommended);
		cout<<"Computer1:"<<endl;
		game.print();
		i--;
	}
	if(game.the_winner()==2)cout<<"Game over with computer win"<<endl;
	else if(game.the_winner()==1)cout<<"Game over with you win"<<endl;
	else cout<<"Game over with a draw"<<endl;
}