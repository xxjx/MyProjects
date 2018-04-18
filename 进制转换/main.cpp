#include<iostream>
#include"Mystack.cpp"
using namespace std;
int main()
{
	int n;
	int r;
	int item;
	cout<<"put in the number you want to change"<<endl;
	cin>>n;
	cout<<"输入你想转换的进制数"<<endl;
	cin>>r;
	Mystack<int>number;
	while(n!=0)
	{
		number.push(n%r);
		n/=r;
	}
	while(!number.empty())
	{
		
		number.top(item);
		cout<<item;
		number.pop();
	}
	return 0;
}






