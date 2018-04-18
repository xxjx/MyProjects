#include<iostream>
#include"Node.cpp"
using namespace std;
int pp=1;
template <class List_entry>
void inverse(Node<List_entry>*&h,int p)
{
	Node<List_entry>*m=h;
	Node<List_entry>*n=NULL;
	Node<List_entry>*k=h;
	while(h&&h->next!=NULL)
		h=h->next;
		n=h;
	for(int i=1;i<p;i++)
	{	
		while(m&&m->next!=n)
		{
			m=m->next;
			pp++;
			//cout<<pp++<<endl;
		}
		n->next=m;
		n=m;
		m=k;
	}		
	k->next=NULL;
}
template<class List_entry>
void start(List_entry m,Node<List_entry>*&h)
{
	Node<List_entry> *p=NULL;
	if(h==NULL)
		h=new Node<List_entry>(m);
	else
	{
		p=h;
		while(p&&p->next!=NULL)
		{
			p=p->next;
		}
			p->next=new Node<List_entry>(m);
	}
}
template<class List_entry>
void print(Node<List_entry> *h)
{
	Node<List_entry>*p=h;
	while(p!=NULL)
	{
		cout<<p->number<<" ";
		p=p->next;
	}
}
void main()
{
	Node<int> *h=NULL;
	int m;
	for(int i=0;i<5;i++)
	{
		cin>>m;
		start(m,h);
	}
	print(h);
	cout<<endl;
	inverse(h,5);
	print(h);
	cout<<endl<<pp<<endl;
}







