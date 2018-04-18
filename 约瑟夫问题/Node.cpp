#include<iostream>
#include<string>
#include"Node.h"
using namespace std;
Node::Node()
{
	next=NULL;
}
Node::Node(int nu,Node *add)
{
	number=nu;
	next=add;
}
