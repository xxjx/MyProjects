#include"Stack.h"
#include<iostream>
using namespace std;
Stack::Stack()
{
	top_node=0;
}
bool Stack::empty()const
{
	return (top_node==0)
}
Error_code Stack::push(const Node_entry&item)
{

