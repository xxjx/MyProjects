#include"Ordered_search.h"
#include"Record.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	ifstream myfile;
	myfile.open("data.txt");
	if(!myfile)
		cout<<"wrong";
	string temp;
	Ordered_search total;
	Record Key;
	while(myfile){
	getline(myfile,temp,',');
	getline(myfile,temp,',');
	Key.key=temp;
	getline(myfile,temp,',');
	getline(myfile,temp);
	Key.info=temp;
	total.insert(Key);
	total.print(Key.key);
	}
	string the_word;
	string the_exp;
	cin>>the_word>>the_exp;
		Key.key=the_word;
		Key.info=the_exp;
		total.insert(Key);
	cout<<endl;
	total.now_ordered();
	cin>>the_word;
	total.print(the_word);
	return 0;
}




