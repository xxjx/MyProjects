#include "iostream.h"

#include "Binary_tree.cpp"

#include "Record.h"

template <class Entry>

void print(Entry &x){

	cout<<x;	

}



void main(){

	Binary_tree<Record> mytree;

	Binary_tree<Record> youtree(mytree);

	for(int i=0; i<10; i++)mytree.insert(Record(i));

	cout<<"Tree size is: "<<mytree.size()<<endl;

	cout<<"Tree height is: "<<mytree.height()<<endl;

	cout<<"Preorder:"<<endl;

	mytree.preorder(print);

	cout<<endl;

	cout<<"inorder:"<<endl;

	mytree.inorder(print);

	cout<<endl;

	cout<<"Postorder:"<<endl;

	mytree.postorder(print);

	cout<<endl;

	cout<<"level"<<endl;

	mytree.level_order();

	cout<<endl;

	mytree.interchange();

	cout<<"level"<<endl;
	
	mytree.level_order();

	youtree.level_order();
}