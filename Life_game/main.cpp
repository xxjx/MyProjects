#include<iostream>
#include<string>
using namespace std;
#include"Life.h"
void instruction()
{
	cout<<"ÓÎÏ·¹æÔò"<<endl;
}
bool user_say()
{
    string m;
	cin>>m;
	if(m=="y")
		return 1;
	else
		return 0;
}
int main()
{
	Life configuration;
	instruction();
	configuration.initialize();
	configuration.print();
	cout<<"continue?"<<endl;
	while(user_say())
	{
		configuration.update();
		configuration.print();
		cout<<"continue?"<<endl;
	}
	int i;
for(i=0;i<60;i++)
   cout<<"-";
	return 0;
}

  
