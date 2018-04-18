template<class Entry>
struct Binary_node{
	Entry data;
	Binary_node<Entry>*left;
	Binary_node<Entry>*right;
	Binary_node();
	Binary_node(const Entry&x);
};
Binary_node<Entry>::Binary_node()
{
	left=0;
	right=0;
}
Binary_node<Entry>::Binary_node(const Entry&x)
{
	left=0;
	right=0;
	data=x;
}
