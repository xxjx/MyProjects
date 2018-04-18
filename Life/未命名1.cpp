#include<iostream>
using namespace std;
int main()
{
	int m,n;
    int **a=new int* [30];  
for(int i=0;i<30;i++)  
      a[i]=new int[30];  
for(int i=0;i<30;i++)
{
	a[i]=0;
}
for(m=0;m<30;m++)
{
	for(n=0;n<30;n++)
	cout<<a[m][n];
	cout<<endl;
}
for(int i=0;i<30;i++)  
      delete [](a[i]);  
delete  []a;  
return 0;
}
