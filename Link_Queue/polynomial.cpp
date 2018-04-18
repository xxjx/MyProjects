#include"polynomial.h"
#include<iostream>
using namespace std;
polynomial::polynomial()
{
	rear=NULL;
	front=NULL;
}
void polynomial::operator =(const polynomial&original)
{
	while(!empty())
		serve();
	SmallNode *original_node=original.front;
	if(original.front==NULL)
		front=rear=NULL;
	else
	{
		front=rear=new SmallNode(original_node->entry);
		while(original_node!=NULL)
		{
			rear=new SmallNode(original_node->entry);
			original_node=original_node->next;
			rear=rear->next;
		}
	}
}
void polynomial::print()const
{
	SmallNode*print_node=front;
	bool first_term=true;

	while(print_node!=0)
	{
		Term &print_term=print_node->entry;
		if(first_term)
		{
			first_term=false;
			if(print_term.coefficient<0)
				cout<<"-";
		}
		else if(print_term.coefficient<0)
			cout<<"-";
		else
			cout<<"+";
		double r=(print_term.coefficient>=0)?print_term.coefficient:-(print_term.coefficient);
		if(r!=1)cout<<r;
		if(print_term.degree>1)cout<<"X^"<<print_term.degree;
		if(print_term.degree==1)cout<<"X";
		if(r==1&&print_term.degree==0)cout<<"1";
		print_node=print_node->next;
	}
		if(first_term)
		cout<<"0"<<endl;
}
polynomial::polynomial(const polynomial&original)
{
	SmallNode*original_node=original.front;
	if(original.front==NULL)
		front=rear=NULL;
	else
	{
		front=rear=new SmallNode(original_node->entry);
		while(original_node!=NULL)
		{
			rear=new SmallNode(original_node->entry);
			rear=rear->next;
			original_node=original_node->next;			
		}
	}
}
void polynomial::read()
{
	clear();
	double coefficient;
	int degree1,degree2;
	bool first_term=true;
	cout<<"Enter the coefficients and exponents for the polynomian,one pair per line"<<endl
		<<"Exponents must be in desending order"<<endl
		<<"Enter a coefficient of 0 or an exponent of 0 to terminate."<<endl;
	cout<<"coefficient?"<<endl;
	cin>>coefficient;
	if(coefficient!=0.0){
		cout<<"degree?"<<endl;
		cin>>degree1;
	}
	while(coefficient!=0.0)
	{
		if(!first_term&&degree2<=degree1||degree1<0)
		{
			degree1=0;
			cout<<"Bad degree"<<endl;
		}
		else
		{
			Term new_term(degree1,coefficient);
			append(new_term);
			first_term=false;
		}
		degree2=degree1;
		cout<<"coefficient?"<<endl;
		cin>>coefficient;
	if(coefficient!=0.0){
		cout<<"degree?"<<endl;
		cin>>degree1;
	}
	}
}

			

