#include<iostream>
#include"Queens.h"
using namespace std;
void solve_from(Queens&configuration)
{
	if(configuration.is_solved()){
		configuration.print();
		cout<<endl;
	}
	else
		for(int col=0;col<configuration.board_size;col++)
			if(configuration.unguarded(col)){
				configuration.insert(col);
				solve_from(configuration);
				configuration.remove(col);
			}
}
void main()
{
	Queens m(8);
    solve_from(m);
}

