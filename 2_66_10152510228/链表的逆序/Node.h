template<class List_entry>
struct Node
{
	Node();
	Node(List_entry m,Node<List_entry> *add_on=NULL);
	List_entry number;
	Node<List_entry> *next;
};
	
