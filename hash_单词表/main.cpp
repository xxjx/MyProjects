#include<iostream>
#include"fstream"
#include"Hash_table.h"
#include<string>
using namespace std;
int main()
{
	ifstream myfile;
	myfile.open("data.txt");
	if(!myfile)
		cout<<"wrong";
	string temp;
	Hash_table total;
	Record Key;
	while(myfile){
	getline(myfile,temp,',');
	getline(myfile,temp,',');
	Key.key=temp;
	getline(myfile,temp,',');
	getline(myfile,temp);
	Key.info=temp;
	total.insert(Key);
	total.retrieve(Key.key);
	}
	string the_word;
	string the_exp;
	cin>>the_word>>the_exp;
		Key.key=the_word;
		Key.info=the_exp;
		total.insert(Key);
	cout<<endl;
	cin>>the_word;
	total.retrieve(the_word);
	cin>>the_word;
	total.remove(the_word);
	cin>>the_word;
	total.retrieve(the_word);
	return 0;
}
