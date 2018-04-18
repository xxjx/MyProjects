#include <iostream>

using namespace std;

int main()
{
	int row,col;
	cout<<"How many rows the square have"<<endl;
	cin>>row;
	while(row%2==0)
	{
		cout<<"please input an odd number"<<endl;
		cin>>row;
	}
	col=row;
	int **grid=new int*[row];
	for(int i=0;i<row;i++)
		grid[i]=new int[col];
	for(int a=0;a<row;a++)
	{
		for(int b=0;b<row;b++)
		grid[a][b]=0;
	} 
	int m=0,n=(row-1)/2;
	for(int c=1;c<=(row*row);c++)
	{		
		if(grid[m][n]==0)
		{
			grid[m][n]=c;
		}
		else
		{
			m=m-2,n=n-1;
			grid[m][n]=c;
		}
		if(m==0&&n==row-1)
			m++;
		else
		{
			if(m==0)
				m=row-1,n=n+1;
			else if(n!=row-1)
				m--,n++;
			else 
				m--,n=0;
		}

	}
    for(int d=0;d<row;d++)
	{
		for(int f=0;f<row;f++)
			cout<<grid[d][f];
		cout<<endl;
	}
	for(int e=0;e<row;e++)
	{
		delete [](grid[e]);
	}
	delete []grid;
	return 0;

}
