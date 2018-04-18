#include"queue.h"
#include<iostream>
using namespace std;
template<class entry>
queue<entry>::queue()
{
	count=0;
	front=0;
	rear=-1;
}
template<class entry>
bool queue<entry>::empty()
{
	return count==0;
}
template<class entry>
Error_code queue<entry>::append(const entry&item)
{
	if(rear<maxqueue-1)
	{
		rear++;
		count++;
		array[rear]=item;
		return success;
	}
	else
		return overflow;
}
template<class entry>
Error_code queue<entry>::serve()
{
	if(count!=0)
	{
		for(int i=0;i<count-1;i++)
		{
			array[i]=array[i+1];
		}
		rear--;
		count--;
		return success;
	}
	else
		return underflow;
}
template<class entry>
Error_code queue<entry>::retrive(entry &item)const
{
	if(front<=rear)
	{
		item=array[front];
		return success;
	}
	else
		return underflow;
}
template<class entry>
void queue<entry>::clear()
{
	count=0;
	front=0;
	rear=-1;
}
template<class entry>
bool queue<entry>::full()const
{
	return (count==maxqueue);
}
template<class entry>
int queue<entry>::size()const
{
	return count;
}

