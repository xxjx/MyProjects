#include"List.h"
#include<iostream>
using namespace std;
template<class List_entry>
void List<List_entry>::set_position(int position)const
{
	if(current_position<position)
	{
		for(current_position;current_position!=position;current_position++)
			current=current->next;
	}
	else 
	{
		for(current_position;current_position!=position;current_position-)
			current=current->back;
	}
	
}
template<class Type>		
DblListNode<Type>*search(DblListNode<Type>*head, DblListNode<Type>*&p,Type key)
{
	DblListNode<Type> *temp;
	if(temp->entry<key)
		while(temp&&temp->entry!=key)
			temp=temp->next;
	else 
		while(temp&&temp->entry!=key)
			temp=temp->back;
	if(temp==0)
		return temp;
	else
	{
		p=temp;
		return temp;
	}
}
