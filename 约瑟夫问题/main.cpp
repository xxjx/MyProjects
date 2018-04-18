#include<iostream>
#include"Node.h"
#include<string>
using namespace std;
Node *head=NULL;
Node *p=NULL;
void insert(int n)
{
	if(head==NULL)
		head=new Node(1);
	else 
	{
		p=head;
		for(int i=2;i<=n-1;i++)
		{
			p->next=new Node(i);
			p=p->next;
		}
		p->next=new Node(n,head);
	}
}//head¸Ä±äÁËÂð£¿
void Delete(int m)
{
	Node *q=head;
	Node *k=NULL;
	while(q->next!=NULL){
		for(int i=1;i<3;i++)
		{
			k=q;
			q=q->next;
		}
		k->next=q->next;
		delete q;
		q=k->next;
	}
	cout<<q->number;
}
void print(int n)
{
	Node *p=head;
	for(int i=0;i<n;i++)
	{
	
		cout<<p->number;
		p=p->next;
	}
}
int main()
{
	int n,m;
	cout<<"put in the the number of people"<<endl;
	cin>>n;
	insert(n);
	print(n);
	return 0;
}

