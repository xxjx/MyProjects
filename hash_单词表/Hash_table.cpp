#include"Hash_table.h"
#include"Record.h"
#include<string>
#include<iostream>
using namespace std;
bool operator==(const Record&x,const Record&y)
{
	return x.key==y.key;
}
bool operator!=(const Record&x,const Record&y)
{
	return x.key!=y.key;
}
int alphabetic_sum(string word)
{
	int i=0;
	const char *one=word.c_str();
	char c=one[i];
	int sum=0;
	int m;
	while(c!='\0')
	{
		i++;
		if(('a'<=c&&c<='z')||('A'<=c)&&(c<='Z'))
			m=c;
		else
			m=123;
		sum=sum+m;
		c=one[i];
	}
	return sum;
}	
Hash_table::Hash_table(){
	int i;
	Record m;
	for(i=0;i<hash_size;i++)
		table[i]=m;
}
int Hash_table::hash(const Record &data)
{
	int value;
	value=alphabetic_sum(data.key)%hash_size;
	return value;
}
int Hash_table::hash(const string &data)
{
	int value;
	value=alphabetic_sum(data)%hash_size;
	return value;
}
Error_code Hash_table::insert(const Record&data)
{
	Record m;
	int probe_count, increment, probe;
	probe=hash(data);
	probe_count=0;
	increment=1;
	while(table[probe]!=m&&probe_count<(hash_size+1)/2)
	{
		probe_count++;
		probe=(probe+increment)%hash_size;
		increment+=2;
	}
	if(table[probe]==m)
	{
		table[probe]=data;
		return success;
	}
	else if(table[probe]==data) 
		return  duplicate_error;
	else return overflow;
}
Error_code Hash_table::retrieve(const string&data)
{
	int probe_count, increment, probe;
	probe=hash(data);
	probe_count=0;
	increment=1;
	Record m;
	while(table[probe].key!=data||table[probe]!=m&&probe_count<(hash_size+1)/2){
		probe_count++;
		probe=(probe+increment)%hash_size;
		increment+=2;
	}
	if(table[probe].key==data)
	{
		cout<<table[probe].key<<" "<<table[probe].info<<endl;
		return success;
	}
	else{
		cout<<"not founded"<<endl;
		return not_present;
	}
}
Error_code Hash_table::remove(const string &data)
{
	int probe_count, increment, probe;
	probe=hash(data);
	probe_count=0;
	increment=1;
	Record m;
	while(table[probe].key!=data||table[probe]!=m&&probe_count<(hash_size+1)/2){
		probe_count++;
		probe=(probe+increment)%hash_size;
		increment+=2;
	}
	if(table[probe].key==data)
	{
		table[probe]=m;
		return success;
	}
	else
		return not_present;
}







	