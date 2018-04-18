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
void Mystack::operator =(const Mystack&original)//原结构体，不是指针；
{
	if(this==&original)return;
	while(!empty())
		pop();
	Node *new_top,*new_copy,*original_node=original.top_node;
	if(original_node==NULL)
		new_top=NULL;
	else
	{
		new_top=new_copy=new Node(original_node->entry);
		while(original_node->next!=NULL)
		{
			original_node=original_node->next;
			new_copy->next=new Node(original_node->entry);
			new_copy=new_copy->next;
		}
	}
	top_node=new_top;
}






