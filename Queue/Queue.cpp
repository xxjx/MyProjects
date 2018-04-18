#include<iostream>
#include"Queue.h"
using namespace std;
template<class entry>
Queue<entry>::Queue()
{
	count=0;
	front=0;
	rear=maxqueue-1;
}
template<class entry>
bool Queue<entry>::empty() const
{
	return count==0;
}
template<class entry>
Error_code Queue<entry>::append(const entry&x)
{
	Error_code outcomme=success;
	if(count>=maxqueue)
		outcome=overflow;
	else 
	{
		if (rear==maxqueue-1)
			rear=0;
		else
			rear++;
		array[rear]=x;
		count++;
	}
	return outcome;
}
template<class entry>
Error_code Queue<entry>::serve()
{
	Error_code outcome=success;
	if(count==maxqueue)
		outcome=underflow;
	else 
	{
		if(front==maxqueue-1)
			front=0;
		else
			front++;
		count--;
	}
}
template<class entry>
Error_code Queue<entry>::retrieve(entry&x)const
{
	Error_code outcome=success;
	if(count==0)
	{
		outcome=underflow;
	}
	else
		x=array[front];
	return outcome;
}
template<class entry>
bool Queue<entry>::full() const
{
	return (count==maxqueue);
}
template <class entry>
int Queue<entry>::size() const
{
	return count;
}
template <class entry>
void Queue<entry>::clear()
{
	count=0;
	front=0;
	rear=maxqueue-1;
}
template <class entry>
Error_code Queue<entry>::serve_and_retrive(entry &item)
{
	outcome =success;
	if(count==0)
		outcome=underflow;
	else
	{		
		item=array[front];
		count--;
		if(front==maxqueue-1)
			front=0;
		else
			front++;
	}
}
