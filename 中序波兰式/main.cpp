enum Error_code{underflow,overflow,success};
const int maxstack=10;
template<class entry>
class Mystack
{
	public:
		Error_code push(const entry &item);
		Error_code top(entry &item);
		Error_code pop();
		Mystack();
		bool empty()const;
	private:
		int count;
		entry array[maxstack];
};


#include<iostream>
#include"Mystack.h"
using namespace std;
template<class entry>
Mystack<entry>::Mystack()
{
	count=0;
}
template<class entry>
bool Mystack<entry>::empty()const
{
	bool outcome=true;
	if (count>0)
		outcome=false;
	return outcome;
}
template<class entry>
Error_code Mystack<entry>::push (const entry&item)
{
	Error_code outcome=success;
	if(count>=maxstack)
		outcome=overflow;
	else
	{
		array[count]=item;
		count++;
	}

	return outcome;
}
template<class entry>
Error_code Mystack<entry>::top(entry &item)
{
	Error_code outcome=success;
	if(count<=0)
		outcome=underflow;
	else
	{
		item=array[count-1];
	}	
	return outcome;
}
template<class entry>
Error_code Mystack<entry>::pop()
{
	Error_code outcome=success;
	if(count<=0)
		outcome=underflow;
	else

		count--;

	return outcome;
}



#include<iostream>
#include<cctype>
#include"Mystack.cpp"
using namespace std;
bool do_command (char command,Mystack<int> &numbers)
{
	int p,q;	
	switch(command)
	{
	case'+':
		{
			if(numbers.top(p)==underflow)
				cout<<"The stack is empty"<<endl;
			else
			{
				numbers.pop();
				if(numbers.top(q)==underflow)
				{
					cout<<"The stack lack a number"<<endl;
					numbers.push(p);
				}
				else
				numbers.pop();
				numbers.push(p+q);
			}
			break;
		}
	case'-':
		{
			if(numbers.top(p)==underflow)
				cout<<"The stack is empty"<<endl;
			else
			{
				numbers.pop();
				if(numbers.top(q)==underflow)
				{
					cout<<"The stack lack a number"<<endl;
					numbers.push(p);
				}
				else
				numbers.pop();
				numbers.push(p-q);
			}
			break;
		}
	case'*':
		{
			if(numbers.top(p)==underflow)
				cout<<"The stack is empty"<<endl;
			else
			{
				numbers.pop();
				if(numbers.top(q)==underflow)
				{
					cout<<"The stack lack a number"<<endl;
					numbers.push(p);
				}
				else
				numbers.pop();
				numbers.push(p*q);
			}
			break;
		}
	case '/':
	{
			if(numbers.top(p)==underflow)
				cout<<"The stack is empty"<<endl;
			else
			{
				numbers.pop();
				if(numbers.top(q)==underflow)
				{
					cout<<"The stack lack a number"<<endl;
					numbers.push(p);
				}
				else
				numbers.pop();
				numbers.push(p/q);
			}
			break;
	}
	case '\n':
		{
			if(numbers.top(p)==underflow)
				cout<<"This is a empty stack"<<endl;
			else
				cout<<p<<endl;
				break;
		}
	case'q':
		return false;	
	}
		return true;
}

char get_co()
{
	bool wait=true;
	char co;
	while(wait)
	{
		cin.get(co);
		if(co>='0'&&co<='9'||co=='+'||co=='-'||co=='*'||co=='/'||co=='\n'||co=='q')
		{
			wait=false;
		}
		else
		{
			cout<<"Please enter a valid command:"<<endl
				<<"The numbers need to be in the range of 0~9"<<endl
				<<"[+][-][*][/] are arithmetic operations"<<endl
				<<"[Q]uit ."<<endl;
		}
	}
	return co;
}


bool do_co (char co, Mystack<int>&s2,Mystack<char>&s1)
{
	int m;
	char x='0';	
	s1.top(x);
	if(co>='0'&&co<='9')
	{
		m=co-'0';
		s2.push(m);
	}
	else if(s1.top(x)==underflow)
	{
		s1.push(co);
	
	}
	else if((x=='+'||x=='-')&&(co=='+'||co=='-'))
	{
		
		do_command (x,s2);
			s1.pop();
			s1.push(co);
		}
	else if((x=='+'||x=='-')&&(co=='*'||co=='/'))
		{
			s1.push(co);
		}
	else if((x=='*'||x=='/')&&(co=='+'||co=='-'))
		{
			while(!s1.empty())
			{
				do_command (x,s2);
				s1.pop();
				s1.top(x);
			}
			s1.push(co);
		}
	else if((x=='*'||x=='/')&&(co=='*'||co=='/'))
		{
			do_command (x,s2);
			s1.pop();
			s1.push(co);

		} 
		 if(co=='\n')
		{
			while(!s1.empty())
			{
				do_command(x,s2);
				s1.pop();
				s1.top(x);
			}
				do_command (co,s2);
		}
	 if(x=='q')
		return false;
	return true;
}


void introduction()
{
	cout<<"Select command and press <Enter>:"<<endl;
}


void main()
{
	Mystack <int>stored_numbers;
	Mystack <char>stored_fu;
	introduction();
	while(do_co(get_co(),stored_numbers,stored_fu));
}	