#include"Splay_tree.h"
template<class Record>
void Splay_tree<Record>::link_right(Binary_node<Record>*&current,Binary_node<Record>*&first_large)
{
	first_large->left=current;
	first_large=current;
	current=current->left;
}
template<class Record>
void Splay_tree<Record>::link_left((Binary_node<Record>*&current,Binary_node<Record>*&rlast_small)
{
	last_small->right=current;
	last_samll=current;
	current=current->right;
}
template<class Record>
void Splay_tree<Record>::rotate_right(Binary_node<Record>* &current)
{
	Binary_node<Record>* left_tree=current->left;
	current->left=left_tree->right;
	left_tree->right=current;
	current=left_tree;
}
template<class Record>
void Splay_tree<Record>::rotate_left(Binary_node<Record>* &current)
{
	Binary_node<Record>* right_tree=current->right;
	current->right=right_tree->left;
	right_tree->left=current;
	crrrent=right_tree;
}
template<class Record>
Error_code Splay_tree<Record>::splay(const Record &target)
{
	Binary_node<Record>*dummy=new Binary_node<Record>;
	Binary_node<Record>*current=root,
		*child,
		*last_small=dummy,
		*first_large=dummy;
	while(current!=0&&current->data!=target){
		if(target<current->data){
			child=current->left;
			if(child==0||target==child->data)
				link_right(current,first_large);
			else if(target<child->data){
				rotate_right(current);
				link_right(current,first_large);
			}
			else{
				link_right(current,first_large);
				link_left(current,last_small);
			}
		}
		else{
			child=current->right;
			if(child->data==target||child==0){
				link_left(current,last_small);
				else if(target<child->data){
					link_left(current,last_small);
					link_right(current,first_large);
				}
				else
				{
					rotate_left(current);
					link_left(current,last_small);
				}
			}
		}
		Error_code result;
		if(current==0){
			current=new Binary_node<Record>(target);
			result=entry_inserted;
			last_small->right=first_large->left=0;
		}
		else
		{
			result=entry_founded;
			last_small->right=current->left;
			first_large->left=current->right;
		}
		root=current;
		root->left=dummy->right;
		root->right=dummy->left;
		delete dummy;
		return result;
	}
}







