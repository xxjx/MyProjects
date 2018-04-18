#include"AVL_tree.h"
#include<iostream>
template<class Record>
Error_code AVL_tree<Record>::insert(const Record&new_data)
{
	bool taller;
	return avl_insert(root,new_data,taller);
}
template<class Record>
Error_code AVL_tree<Record>::avl_insert(Binary_node<Record>*&sub_root,const Record&new_data,bool taller)
{
	Error_code result=success;
	if(sub_root==0){
		sub_root=new AVL_node<Record>(new_data);
		taller=true;
	}
	else if(new_data==sub_root->data){
		result=duplicate_error;
		taller=false;
	}
	else if(new_data<sub_root->data){
		result=avl_insert(sub_root->left,new_data,taller);
		if(taller==true)
			switch(sub_root->get_balance()){
			case left_higher:
				left_balance(sub_root);
				taller=false;
				break;
			case equal_height:
				sub_root->set_balance(left_higher);
				break;
			case right_higher:
				sub_root->set_balance(equal_height);
				taller=false;
				break;
		}
	}
	else
	{
		result=avl_insert(sub_node->right,new_data,taller);
		switch(sub_root->get_balance()){
		case right_higher:
			sub_root(right_balance);
			taller=false;
			break;
		case equal_herght:
			sub_root->set_balance(right_higher);
			break;
		case left_higher:
			sub_root->set_balance(equal_hight);
			taller=false;
			break;
		}
	}
	return result;
}
template<class Record>
void AVL_tree<Record>::right_balance(Binary_node<Record>*sub_root)
{
	Binary_node<Record>*&right_tree=sub_root->right;
	switch(right_tree->get_balance()){
	case right_higher:
		sub_root->set_balance(equal_height);
		right_tree->set_balance(equal_height);
		rotate_left(sub_root);
		break;
	case equal_height:
		cout<<"wrong";
	case left_heigher:
		Binary_node<Record>*sub_tree=right_tree->left;
		switch(sub_root->get_balance()_{
		case equal_height:
			sub_root->set_balance(equal_height);
			right_tree->set_balance(equal_height);
			break;
		case left_higher:
			sub_root->set_balance(equal_hight);
			right_tree(right_higer);
			break;
		case right_higher:
			sub_root->set_balance(left_higher);
			right_tree(equal_height);
			break;
		}
		sub_tree->set_balance(equal_height);
		rotate_right(right_tree);
		rotate_left(sub_root);
		break;
	}
}
template<class Record>
void AVL_tree<Record>::rotate_left(Binary_node<Record>* &sub_root)
{
	if(sub_root==0||sub_root->right==0)
		cout<<"wrong"<<endl;
	else{
		Binary_node<Record>*right_tree=sub_root->right;
		sub_root->right=right_tree->left;
		right_tree->left=sub_root;
		sub_root=right_tree;
	}
}
template<class Record>
void AVL_tree<Record>::rotate_right(Binary_node* &sub_root)
{
	Binary_node<Record> *left_tree=sub_root->left;
	sub_root->left=left_tree->right;
	left_tree->right=sub_root;
	sub_root=left_tree;
}
template<class Record>
void AVL_tree<Record>::left_balance(Binary_node* sub_root)
{
	Binary_node<Record>* left_tree=sub_root->left;
	switch(left_tree->get_balance()){
	case left_higher:
		left_tree->set_balance(equal_balance);
		sub_root->set_balance(equal_balance);
		rotate_right(sub_root);
		break;
	case equal_height:
		cout<<"wrong"<<endl;
	case right_higher:
		Binary_node<Record> *sub_tree=left_tree->right;
		switch(sub_tree->get_balance()){
		case equal_height:
			sub_root->set_balance(equal_height);
			left_tree->set_balance(equal_height);
			break;
		case right_higher:
			sub_root->set_balance(left_higher);
			left_tree->set_balance(equal_height);
			break;
		case left_higher:
			sub_root->set_balance(equal_height);
			left_tree->set_balance(right_higher);
			break;
		}
		sub_tree->set_balance(equal_height);
		rotate_right(left_tree);
		rotate_left(sub_root);
		break;
	}
}
template<class Record>
Error_code AVL_tree<Record>::remove(const Record&old_data)
{
	bool shorter;
	return avl_insert(root,old_data,shorter);
}
template<class Record>
Error_code AVL_tree<Record>::avl_remove(Binary_node<Record>*&sub_root,Record &new_data, bool&shorter)
{
	Error_code result;
	Record sub_record;
	if(sub_root==0){
		shorter=false;
	result= not_present;
	}
	else if(new_data==sub_root->data){
		Binary_node<Record>*to_delete=sub_root;
		if(sub_root->right==0){
			sub_root=sub_root->left;
			shorter=true;
			delete to_delete;
			result= success;
		}
		else if(sub_root->left==0){
			sub_root=sub_root->right;
			shorter=true;
			delete to_delete;
			return success;
		}
		else{
			to_delete=sub_root->left;
			Binary_node<Record>*parent=sub_root;
			while(to_delete->right!=0){
				parent=to_delete;
				to_delete=to_lelete->right;
			}
			new_data=to_delete->data;
			sub_record=new_data;
		}
		if(new_data<sub_root->data){
			result=avl_remove(sub_root->left,new_data,shorter);
			if(sub_root.the_key()!=0)
				sub_root->data=sub_record;
			if(shorter==true)
				switch(sub_root->get_balance()){
				case left_higher:
					sub_root->set_balance(equal_height);
					break;
				case equal_height:
					sub_root->set_balance(right_higher);
					shorter=false;
					break;
				case right_higher:
					shorter=right_balance2(sub_root);
					break;
			}
		}
		if(new_data>sub_root->data){
			result=avl_remove(sub_root->right,new_data,shorter);
			if(sub_record.the_key()!=0)sub_root->data=sub_record;
			if(shorter==true)
				switch(sub_root->get_balance()){
				case left_higher:
					shorter=left_balance2(sub_root);
					break;
				case equal_height:
					sub_root->set_balance(left_higher);
					shorter=false;
					break;
				case right_higher:
					sub_root->set_balance(equal_height);
					break;
			}
		}
		return result;
	}
}
template<class Record>
bool AVL_tree<Record>::right_balance2(Binary_node<Record>*& sub_root)//左边被删除的情况，平衡右边。
{
	bool shorter;
	Binary_node<Record>*& right_tree=sub_root->right;
	switch(right_tree->get_balance()){
	case right_higher:
		sub_root->set_balance(equal_height);
		right_tree->set_balance(equal_height);
		rotate_left(sub_root); 
		shorter = true;
		break;
	case equal_height: 
		right_tree->set_balance(left_higher);
		rotate_left(sub_root); 
		shorter = false;
		break;
	case left_higher: 
		Binary_node<Record> *sub_tree = right_tree->left;
		switch (sub_tree->get_balance( )) {
	case equal_height:
			sub_root->set_balance(equal_height);
			right_tree->set_balance(equal_height); 
			break;
	case left_higher:
			sub_root->set_balance(equal_height);
			right_tree->set_balance(right_higher); 
			break;
	case right_higher:
			sub_root->set_balance(left_higher);
			right_tree->set_balance(equal_height); 
			break;
		} 
		sub_tree->set_balance(equal_height);
		rotate_right(right_tree);
		rotate_left(sub_root); 
		shorter = true;
		break;
	} 
	return shorter;
}
template<class Record>
bool AVL_tree<Record>::left_balance2(Binary_node<Record>*&sub_root)//右边被删除的情况，平衡左边。
{
	bool shorter;
	Binary_node<Record>*& left_tree=sub_root->left;
	switch(left_tree->get_balance()){
	case left_higher:
		rotate_right(sub_root);
		left_tree->set_balance(equal_height);
		sub_root->set_balance(equal_height);
		shorter=true;
	case equal_height:
		sub_root->set_balance(left_higher);
		left_tree->set_balance(right_higher);
		rotata_right(sub_root);
		shoter=false;
		break;
	case right_higher:
		Binary_node<Record>*& sub_tree=left_tree->right;
		switch(sub_tree->get_balance()){
		case equal_height:
			sub_root->set_balance(equal_height);
			left_tree->set_balance(equal_height);
			shorter=false;
			break;
		case left_higher:
			sub_root->set_balance(right_higher);
			right_tree->set_balance(equal_height); 
			break;
		case right_higher:
			sub_root->set_balance(equal_higher);
			right_tree->set_balance(left_height); 
			break;
		}
			rotate_left(left_tree);
			rotate_right(sub_tree);
			sub_tree(equal_height);
			shorter=true;
			break;
	}
		return shorter;
}