#include "Binary_tree.h"

#include"Binary_node.cpp"

#include "MyStack.cpp"

#include  "MyQueue.cpp"

template <class Entry>

Binary_tree<Entry> :: Binary_tree( )

/* Post: An empty binary tree has been created. */

{

	root = NULL;

	count = 0;

}



template <class Entry>

bool Binary_tree<Entry> :: empty( ) const

/* Post: A result oftrue is returned if the binary tree is empty. Otherwise,false is

returned. */

{

	return root == NULL;

}



template <class Entry>

void Binary_tree<Entry> :: preorder(void (*visit)(Entry &))

{

	recursive_preorder(root, visit);

}



template <class Entry>

void Binary_tree<Entry> :: recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))

{

	if (sub_root != NULL) {

		(*visit)(sub_root->data);

		recursive_preorder(sub_root->left, visit);

		recursive_preorder(sub_root->right, visit);

	} 

}



template <class Entry>

void Binary_tree<Entry> :: inorder(void (*visit)(Entry &))

/* Post: The tree has been been traversed in infix order sequence.

Uses: The function recursive_inorder */

{

	recursive_inorder(root, visit);

}



template <class Entry>

void Binary_tree<Entry> :: recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))

/* Pre: sub_root is either NULL or points to a subtree of the Binary tree .

Post: The subtree has been traversed in inorder sequence.

Uses: The function recursive inorder_recursively */

{

	if (sub_root != NULL) {

		recursive_inorder(sub_root->left, visit);

		(*visit)(sub_root->data);

		recursive_inorder(sub_root->right, visit);

	} 

}



template <class Entry>

void Binary_tree<Entry> :: postorder(void (*visit)(Entry &))

{

	recursive_postorder(root, visit);

}



template <class Entry>

void Binary_tree<Entry> :: recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))

{

	if (sub_root != NULL) {

		recursive_postorder(sub_root->left, visit);

		recursive_postorder(sub_root->right, visit);

		(*visit)(sub_root->data);

	} 

}



template <class Entry>

int Binary_tree<Entry> :: size( ) const

{

	return count;

}



template <class Entry>

int Binary_tree<Entry> :: height( ) const

{

	int count=size();

	if(count==0)return 0;

	int tmp=1;

	for(int i=-1; tmp<=count; i++)tmp*=2;

	return i;

}



template <class Entry>

void Binary_tree<Entry> :: insert(Entry &x)

{

	if(empty()){

		root=new Binary_node<Entry>(x);

		count++;

		return;

	}

	MyStack<int> numbers;

	int item=0;

    int tmpcount=size();

    while(tmpcount>0){

		int a=(tmpcount-1)/2;

 	    int b=(tmpcount-2)/2;

	    if(tmpcount>1 && a==b){//the node is right child

		   numbers.push(2);//2 stand for right child

		} 

	    else{//the node is left child

		   numbers.push(1);//1 stand for left child

		} 

	    tmpcount=(tmpcount-1)/2;//get to the parent

	}

	Binary_node<Entry> *current=root;

	while (numbers.size()>1) {

		numbers.top(item); 

        if(item==1)current=current->left;

		if(item==2)current=current->right;

        numbers.pop();

	} 

	numbers.top(item);

	if(item==1)current->left=new Binary_node<Entry>(x);

	if(item==2)current->right=new Binary_node<Entry>(x);

	count++;

}

template<class Entry>

void Binary_tree<Entry>::level_order()
{

	Binary_node<Entry>* temp;

	MyQueue<Binary_node<Entry>*> first;


	if(root!=0)

	first.append(root);

	while(!first.empty()){
	
		first.retrieve(temp);
		
		cout<<temp->data;
		
		first.serve();
	
		if(temp->left!=0)

			first.append(temp->left);
		
		if(temp->right!=0)
		
			first.append(temp->right);
		
	}

}

template<class Entry>

void Binary_tree<Entry>::interchange()
{

    interchange_in(root);

}

template<class Entry>

void Binary_tree<Entry>::interchange_in(Binary_node<Entry>* &sub_node)
{
	if(sub_node!=0){
		Binary_node<Entry>* temp;
		temp=sub_node->left;
		sub_node->left=sub_node->right;
		sub_node->right=temp;
		interchange_in(sub_node->right);
		interchange_in(sub_node->left);
	}
}

template<class Entry>
Binary_tree<Entry>::Binary_tree(const Binary_tree<Entry>&original)
{
	recursive_copy(root,original.root);
}

template<class Entry>
Binary_tree<Entry>& Binary_tree<Entry>::operator =(const Binary_tree<Entry>&original)
{
	if(root==original.root)
		break;
	else
		clear();
	recursive(root,original.root);
	return *this
}

template<class Entry>
void Binary_tree<Entry>::recursive_copy(Binary_node<Entry>*&old_one,Binary_node<Entry> *sub_root)
{
	if(sub_root==0)
		old_one=0;
	else{

		old_one=new Binary_node(sub_root->data);
		
		recursive_copy(old_one->left,sub_root->left);
		
		recursive_copy(old_one->right,sub_root->right);
	}
}
