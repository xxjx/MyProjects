#include"Ordered_search.h"
#include"Record.h"
#include<string>
#include<iostream>
using namespace std;
bool operator==(const Record&x,const Record&y)
{
	return x.key==y.key;
}
bool operator>(const Record&x,const Record&y)
{
	return x.key>y.key;
}
bool operator<(const Record&x,const Record&y)
{
	return x.key<y.key;
}
bool operator>=(const Record&x,const Record&y)
{
	return x.key>=y.key;
}
bool operator<=(const Record&x,const Record&y)
{
	return x.key<=y.key;
}
bool operator!=(const Record&x,const Record&y)
{
	return x.key!=y.key;
}
Error_code Ordered_search::insert(const Record&data)
{
	int i=size();
	int position=0;
	Record list_data;
	for(position=0;position<i;position++)
	{
		retrieve(position,list_data);
		if(data.key<list_data.key)break;
	}
	return List<Record>::insert(position,data);

}

Error_code Ordered_search::find(const string&data,int&position)
{
	Record list_data; 
	int bottom=0;
	int top=size()-1;
	while(bottom<=top){
		position=(bottom+top)/2;
		retrieve(position,list_data);
		if(list_data.key<data)
			bottom=position+1;
		if(list_data.key==data)
			return success;
		if(list_data.key>data)
			top=position-1;
	}
		return not_present;
}
Error_code Ordered_search::print(const string&data)
{
	int position=0;
	Record list_data;
	if(find(data, position)==success){
		if(retrieve(position,list_data)==success)
		cout<<list_data.key<<" "<<list_data.info<<endl;
	}
	else
		cout<<"not founded"<<endl;
	return find(data,position); 
}
Error_code Ordered_search::Delete(const string&data)
{
	Record list_data;
	int position=0;
	if(find(data,position)==success)
	{
		remove(position,list_data);
	}
	return find(data,position); 

}
void Ordered_search::now_ordered()
{
	int i=0;
	Record x;
		for(i;i<size();i++){
		retrieve(i,x);
		cout<<x.key<<" "<<x.info<<endl;
		}
}
		


		
		

