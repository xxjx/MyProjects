#include<iostream>
#include"queue.cpp"
using namespace std;
int main()
{
	int m;
	int s;
	cin>>s;
	queue <int> x;
	x.append(s);
	x.retrive(m);
	cout<<m<<endl;
	cout<<x.size();
	return 0;
}
