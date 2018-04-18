#include "Binary_node.cpp"

template <class Entry>

class Binary_tree {

public:

	Binary_tree( );

	bool empty( ) const;

	void preorder(void (*visit)(Entry &));

	void inorder(void (*visit)(Entry &));

	void postorder(void (*visit)(Entry &));

	int size( ) const;

	int height( ) const;

	void insert(Entry &);

	void level_order();

	void interchange();

	Binary_tree(const Binary_tree<Entry>&original);

	Binary_tree& operator=(const Binary_tree<Entry>&original);

	void recursive_copy(Binary_node<Entry>*& old_one,Binary_node<Entry>*sub_root);

protected:

// Add auxiliary function prototypes here.

	void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

	void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

	void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

	void interchange_in(Binary_node<Entry>* &sub_node);

	Binary_node<Entry> *root;

	int count;

};

