#include<iostream>
#include<string>
using namespace std;
int alphabetic_sum(string word)
{
	int i=0;
	const char *one=word.c_str();
	char c=one[i];
	int sum=0;
	int m;
	while(c!='\0')
	{
		i++;
		m=c;
		sum=sum+m;
		c=one[i];
	}
	return sum;
}

int main()
{
	string c;
	cin>>c;
	cout<<alphabetic_sum(c);
	return 0;
}