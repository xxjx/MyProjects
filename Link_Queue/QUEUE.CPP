#include"Queue.h"
#include<iostream>
using namespace std;
SmallNode::SmallNode(SmallNode_entry number,SmallNode*add)
{
	entry=number;
	next=add;
}
SmallNode::SmallNode()
{
	next=NULL;
}
Queue::Queue()
{
	front=rear=NULL;
}
Error_code Queue::append(const Queue_entry&item)
{		
	if(rear==NULL)
		front=rear=new SmallNode(item);
	else
	{
		rear->next=new SmallNode(item);
		rear=rear->next;
	}
	return success;
}
Error_code Queue::serve()
{
	if(front==NULL)
		return underflow;
	else
	{
		SmallNode*m=front;
		if(front->next!=NULL)
		{
			front=front->next;
			delete m;
			m=NULL;
		}
		else
		{
			delete front;
			front=rear=NULL;
		}
	}
	return success;
}
Error_code Queue::retrieve(Queue_entry&sth)const
{
	if(front==NULL)
		return underflow;
	else
	{
		sth.degree=front->entry.degree;
		sth.coefficient=front->entry.coefficient;
	return success;
	}
}
bool Queue::empty()const
{
	if(front==NULL)
		return true;
	else
		return false;
}
Queue::~Queue()
{
	SmallNode*n;
	while(!empty())
	{
		n=front;
		front=front->next;
		delete n;
	}
	rear=n=NULL;
}
int Extended_Queue::size()const
{
	SmallNode *k=NULL;
	int i=0;
	k=front;
	while(k!=NULL)
	{
		i++;
		k=k->next;
	}
	return i;
}
void Extended_Queue::clear()
{
	while(!empty())
		serve();
}
Error_code Extended_Queue::serve_and_retrieve(Queue_entry&item)
{
	if(front==NULL)
		return underflow;
	else
	{
		SmallNode *m=front;
		item.coefficient=front->entry.coefficient;
		item.degree=front->entry.degree;
		front=front->next;
		delete m;
		if(front==NULL)
		{
			front=rear=NULL;
		}
		return success;
	}
}






		





