#include"Binary_node.h"
template<class Entry>
Binary_node<Entry>::Binary_node()
{
	left=0;
	right=0;
}
Binary_node<Entry>::Binary_node(const Entry &x)
{
	left=0;
	right=0;
	data=x;
}

