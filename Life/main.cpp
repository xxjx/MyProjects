#include<iostream>
#include"Life.h"
#include<string>
using namespace std;
void instruction()
{
	cout<<"Welcome to my game of life"<<endl;
	cout<<"This game has the line of"<<mline
		<<"in which each cell can be occupied by an chess or not"<<endl;
	cout<<"PLAY THE GAME"<<endl;
}
bool answer()
{ 
	string ans;
	while(cin>>ans)
	{
		if(ans=="Y"||ans=="y")
		{
			return true;
			break;
		}
	    else if(ans=="N"||ans=="n")
		{
			return false;
			break;
		}
		else 
			cout<<"The answer need to be Y, y , n, N"<<endl;
	}
}
int main()
{
	instruction();
	Life player;
	player.initialize();
	player.print();
	cout<<"Continue?"<<endl;
	while(answer())
	{
		player.update();
		player.print();
		cout<<"Continue?"<<endl;
	}
	cout<<"Bye !"<<endl;
	return 0;
}