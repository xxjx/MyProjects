template<class Record>
class AVL_tree{
	public:
		Error_code avl_insert(root,new_data,taller);
		Error_code insert(const Record&new_data);
		void right_balance(Binary_node<Record>*& sub_root);
		void rotate_left(Binary_node<Record>*& sub_root);
		void rotate_right(Binary_node<Record>*& sub_root);
		void left_balance(Binary_node<Record>* &sub_root);
		Error_code avl_remove(Binary_node<Record>* &sub_root,Record &new_data,bool&shorter);
		bool right_balance2(Binary_node<Record>*&sub_root);
		bool left_balance2(Binary_node<Record>*&sub_root);
