template <class Entry>

struct Binary_node {

// data members:

	Entry data;

	Binary_node<Entry> *left;

	Binary_node<Entry> *right;

// constructors:

	Binary_node( );

	Binary_node(const Entry &x);

};