#include"AVL_node.h"
template<class Record>
AVL_node<Record>::AVL_node(){
	left=0;
	right=0;
	balance=equal_height;
}
template<class Record>
AVL_node<Record>::AVL_node(const Record&x){
	left=0;
	right=0;
	balance=equal_height;
}
template<class Record>
void AVL_node::set_balance(Balance_factor b){
	balance=b;
}
template<class Record>
Balance_factor AVL_node::get_balance()const{
	return balance;
}

