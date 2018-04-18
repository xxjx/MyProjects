#include"Sortable_list.h"
void Sortable_list::insertion_sort(){
	Node<Record> *last_one,
	*unsorted,
	*front,
	*current;
	if(head!=NULL){
		last_one=head;
	while(last_one->next!=NULL)
	{
		unsorted=last_one->next;
		if(head->entry>unsorted->entry)
		{
			last_one->next=unsorted->next;
			unsorted->next=head;
			head=unsorted;
		}
		else
		{
			front=head;
			current=front->next;
			while(current->entry<unsorted->entry)
			{
				current=current->next;
				front=current;
			}
			if(current==unsorted)
				last_one=unsorted;
			else{
				last_one->next=unsorted->next;
				front->next=unsorted;
				unsorted->next=current;
			}
		}
	}
	}
}

