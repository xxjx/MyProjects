#include<iostream>
#include "square.h"
using namespace std;
int main()
{
	square one;
	one.initialize();
	one.judge();
	cout<<endl;
	one.create();
	one.print();
	return 0;
}

