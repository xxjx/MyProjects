#include <iostream>
using namespace std;
int Pascal(int n,int k)
{
	int i,j;
	int **array=new int*[n+1];
	for (i=0;i<n+1;i++)
		array[i]=new int[n+1];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0)
				array[i][j]=1;
			else if(i==j)
				array[i][j]=1;
			else if(j==1||i==j+1)
				array[i][j]=i;
			else array[i][j]=array[i-1][j-1]+array[i-1][j];
		}

	}
	int p=array[n][k];
	for(i=0;i<=n;i++)
		delete[](array[i]);
	delete[]array;
	return p;
}
int main()
{
	int m;
	cin>>m;
	cout<<Pascal(m,2);
	return 0;
}


