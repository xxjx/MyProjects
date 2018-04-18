#include"Sortable.h"
#include<iostream>
using namespace std;
template<class s_entry>
void Sortable::insert_heap(s_entry current,int low, int high)
{
	int large=low*2-1;
	while(large<=high){
		if(entry[large]<entry[large+1])
			large++;
		if(entry[large]<current)
			break;
		else
		{
			entry[low]=entry[large];
			low=large;
			large=2*low+1;
		}
	}
	entry[low]=current;
}
void Sortable::insert(s_entry)
{

	s_entry temp;
	entry[count]=s_entry;
	count++;
	int last_entry=count;
	low=(count-1)/2;
	while(low>=0){
		if(entry[last_entry]>entry[low])
		{
			temp=entry[low];
			entry[low]=entry[last_entry];
			entry[last_entry]=temp;
			last_entry=low;
			low=(last_entry-1)/2;
		}
		if(entry[last_entry<=entry[low]])
			break;
}
void Sortable<s_entry>::build_heap()
{
	int low;
	for(low=count/2-1;low>0;low--)
	{
		s_entry current=entry[low];
		insert_heap(current,low,count-1);
	}
}
void Sortable::remove()
{
	s_entry current;
	int the_last=count-1;
	current=entry[the_last];
	insert_heap(current,0,the_last-1);
	count--;
}
void Sortable::radix_sort()
{
	Record data;
	MyQueue<Record>queues[max_chars];//key_size?
	for(int position=key_size-1;position>=0;position--){
		while(remove(0,data)==success){//remove dui yu myqueue;
			int queue_number=alphabetic_order(data.key_letter(position));//shu ru xia biao fan hui shu zi.
			queues[queue_number].append(data);
		}
		rethread(queues);
	}
}
int alphabetic_order(char c)
{
	if(c==''||c=='\0')return 0;
	if('a'<=c&&c<='z')return c-'a'+1;
	if('A'<=c&&c<='Z')return c-'A'+1;
	return 27;
}
void Sortable::rethread(Queue queue[])//×é³Élist£»
{
	Record data;
	for(int i=0;i<max_chars;i++)
		while(!queues[i].empty()){
			queues[i].retrieve(data);
			insert(size(),data);
			queues[i].serve();
		}
}

