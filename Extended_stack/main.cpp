#include<iostream>
#include"Extended_stack.cpp"
using namespace std;
int main()
{
	int n,x;
	int m;
	int item;
	Extended_stack<int>s;
	cout<<"Type in the numbers that you want to put in"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>item;
		if(i==0)
			s.push(item);
		else
		{	s.top(m);
			if(m<item)	
		    	s.push(item);		
		}
	}
	x=s.size();
	for(i=0;i<x;i++)
	{
		s.top(item);
		cout<<item<<" ";
		s.pop();
	}
	return 0;
}
