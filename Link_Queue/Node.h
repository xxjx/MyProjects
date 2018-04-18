#include"polynomial.h"
typedef polynomial Node_entry;
struct Node
{
public:
	Node_entry entry; 
	Node *next;
	Node();
	Node(Node_entry item, Node*add_on=0)
};

