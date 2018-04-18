#include<iostream>
#include"Node.h"
using namespace std;
template<class List_entry>
Node<List_entry>::Node()
{
	next=NULL;
}
template<class List_entry>
Node<List_entry>::Node(List_entry m,Node<List_entry>*add_on)
{
	next=add_on;
	number=m;
}