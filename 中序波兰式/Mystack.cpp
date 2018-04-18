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
