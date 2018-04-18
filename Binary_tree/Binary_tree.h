enum Error_code{not_present, success};
template <class Entry>
class Binary_tree{
	public:
		Binary_tree();
		bool empty()const;
		void preorder(void(*visit)(Entry&));
		void inorder(void(*visit)(Entry&));
		void postorder(void(*visit)(Entry&));
		int size()const;
		void clear();
		int height()const;
		void insert(const Entry&);
		Error_code tree_search(Entry &target)const;
		Error_code insert(const Entry &new_data);
		Error_code remove(const Entry &old_data);
		Binary_tree(const Binary_tree<Entry>&original);
		~Binary_tree();
		Binary_tree(const Binary_tree<Entry>&original);
		Binary_tree<Entry>& operator=(const Binary_tree<Entry>&original);
		void recursive_copy(Binary_node<Entry>*& old_one,Binary_node<Entry>*&sub_root);
		void interchange();
	protected:
		Binary_node<Entry>*root;
		Error_code search_and_destroy(Binary_node<Entry>*&sub_root,const Entry &target);
		Error_code remove_root(Binary_node<Entry>*&sub_root)
};