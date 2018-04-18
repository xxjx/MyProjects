#include"Binary_tree.h"
#include"Binary_node.h"
#include<iostream>
using namespace std;
template<class Entry>
Binary_tree<Entry>::Binary_tree(){
	root=0;
}
template<class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry&))
{
	recursive_inorder(root,visit);
}
template<class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry>*sub_root,void(*visit)(Entry&))//中序
{
	if(sub_root!=0){//终止点。
		recursive_inorder(sub_root->left,visit);//先左边
		(*visit)(sub_root->data);//访问中间元素
		recursive_inorder(sub_root->right,visit);//访问右边
	}
}
template<class Entry>
void Binary_tree<Entry>::postorder((*visit)(Entry &))
{
	recursive_preorder(Binary_node<Entry>*sub_root,void(*visit)(Entry&));
}
template<class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry>*sub_root,void(*visit)(Entry&))
{
	if(sub_root!=0){
		recursive_postorder(sub_root->left,void(*visit)(Entry&));
		recursive_postorder(sub_root->right,void(*visit)(Entry&));
	    (*visit)(sub_root->data);
	}
}
template<class Entry>
bool Binary_tree<Entry>::empty()
{
	return root==0;
}
template<class Entry>
Error_code Binary_tree<Entry>::remove(const Entry&target)
{
	return search_and_destroy(root,target);
}
template<class Entry>
Error_code Binary_tree<Entry>::search_and_destroy(Binary_node<Entry>*&sub_root,const Entry&target)
{
	if(sub_root==0||sub_root->data==target)
		return remove_root(sub_root);
	else
	{
		if(sub_root->data<target)
		return search_and_destroy(sub_root->right,target);
		else
		return search_and_destroy(sub_root->left,target);
	}
}
template<class Entry>
Error_code Binary_tree<Entry>::remove_root(Binary_node<Entry>*&sub_root)
{
	if(sub_root==0)
		return not_present;
	Binary_node<Entry> *to_delete=sub_root;
	if(sub_root->right==0)
		sub_root=sub_root->left;
	else if(sub_root->left==0)
		sub_root=sub_root->right;
	else{
		to_delete=sub_root->left;
		Binary_node<Entry>*parent;
		while(to_delete->right!=0){
			parent=to_delete;
			to_delete=to_delete->right;
		}
		if(parent==sub_root)
			sub_root->left=to_delete->left;
		else
			parent->right=to_delete->left;
	}
	delete to_delete;
}
Binary_tree<Entry>::Binary_tree(const Binary_tree<Entry>&original)
{
	recursive_copy(root,original.root);
}
Binary_tree<Entry>& Binary_tree<Entry>::operator =(const Binary_tree<Entry>&original)
{
	if(root==original.root)
		break;
	else
		clear();
	recursive(root,original.root);
	return *this
}
void Binary_tree<Entry>::recursive_copy(Binary_node<Entry>*&old_one,Binary_node<Entry>*&sub_root)
{
	if(sub_root==0)
		old_one=0;
	else{
		old_one=new Binary_node(sub_root->data);
		recursive_copy(old_one->left=sub_root->right);
		recursive_copy(old_one->right=sub_root->right);
	}
}
template<class Entry>
Error_code Binary_tree<Entry>::insert(const Entry&new_data)
{
	Binary_node<Entry> *found=root;
	while(found!=0){
		if(new_data<found->data)
			found=found->left;
		else
			found=found->right;
	}
	found=new Binary_node(data);
}
template<class Entry>
Error_code Binary_tree<Entry>::tree_search(Entry&target)const//while 循环的
{
	Binary_node<Entry> *found=root;
	while(found!=0||found->data!=target){
		if(target<found->data)
			found=found->left;
		else
			found=found->right;
	}
	if(found==0)
		return not_present;
	else
		target=found->data;
		return success;
}
template<class Entry>
void Binary_tree<Entry>::interchange(Binary_node<Entry>* &sub_node)
{
	if(sub_node!=0){
		Binary_node<Entry>* temp;
		temp=sub_node->left;
		sub_node->left=sub_node->right;
		sub_node->right=temp;
		interchange(sub_node->right);
		interchange(sub_node->left);
	}
}


		
	
	


	
	





		





		
	
