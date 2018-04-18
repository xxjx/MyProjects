enum Balance_factor{equal_height,left_higher,right_higher};
template<class Record>
struct AVL_node:public Binary_node<Record>{
	AVL_node();
	AVL_node(const Record&x);
	void set_balance(Balance_fator b);
	Balance_factor get_balance()const;
	Balance_factor balance;
};
