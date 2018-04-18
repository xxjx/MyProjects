template<class Node_entry>
struct Node
{
public:
	Node_entry entry; 
	Node *next;
	Node *back;
	Node();
	Node(Node_entry item, Node<Node_entry>*t_next=0, Node<Node_entry>*t_back=0)
};

Node::Node()
{
	next=0;
	back=0;
}
Node(Node_entry item, Node<Node_entry>*t_next, Node<Node_entry>*t_back)
{
	next=t_next;
	back=t_back;
}