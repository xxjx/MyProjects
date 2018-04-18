#include<iostream>
#include"Extended_stack.h"
using namespace std;
template<class entry>
Extended_stack<entry>::Extended_stack()
{
	count=0;
}
template<class entry>
bool Extended_stack<entry>::empty()const
{
	bool outcome=true;
	if (count>0)
		outcome=false;
	return outcome;
}
template<class entry>
Error_code Extended_stack<entry>::push (const entry&item)
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
Error_code Extended_stack<entry>::top(entry &item)const
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
Error_code Extended_stack<entry>::pop()
{
	Error_code outcome=success;
	if(count<=0)
		outcome=underflow;
	else

		count--;

	return outcome;
}
template <class entry>
void Extended_stack<entry>::clear()
{
	count=0;
}
template <class entry>
bool Extended_stack<entry>::full()const
{
	bool outcome=ture;
	if(count!=maxstack)
		outcome=false;
	return outcome;
}
template <class entry>
int Extended_stack<entry>::size()const
{
	return count;
}






