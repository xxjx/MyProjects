#include"B_node.h"
#pragma once
enum Error_code{success,not_present};
template<class Record, int order>
class B_tree{
	public:
		Error_code	search_tree(Record &target);
		Error_code insert(const Record&new_entry);
		Error_code remove(const Record&target);
	private:
		Error_code recursive_search_tree(B_node<Record,order>*current,Record &target);
		Error_code search_node(B_node<Record,order>*current,const Record&target,int &position);
		Error_code push_down(B_node<Record,order>*current,const Record&new_entry,Record&median,B_node<Record,order>*&right_branch);
		void push_in(B_node<Record,order>*current, const Record&entry,B_node<Record,order>*right_branch,int position);
		void split_node(B_tree<Record,order>*current,const Record&extra_entry,B_node<Record,order>*extra_branch,int position,B_node<Record,order>*&right_half,Record &median);
		Error_code recursive_remove(B_node<Record,order> *current,const Record &target);
		void remove_data(B_node<Record,order>*current,int position);
		void copy_in_predecessor(B_node<Record,order>*current,int position);
		void restore(B_node<Record,order>*current,int position);
		void move_left(B_node<Record,order>*current,int position);
		void move_right(B_node<Record,order>*current,int position);
		void combine(B_node<Record,order>*current,int position);
};
