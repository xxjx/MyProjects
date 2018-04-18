#include<iostream>
#include"Mystack.cpp"
using namespace std;
int main()
{
	int n;
	double item;
	Mystack<double>numbers;
	cout<<"Type";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>item;
		numbers.push(item);	
	}
	cout<<endl;
	while(!numbers.empty())
	{
	 	numbers.top(item);
			cout<<item<<" ";
		numbers.pop();
	}
	cout<<endl;
	return 0;
}



