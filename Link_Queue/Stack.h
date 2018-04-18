#include"polynomial.h"
typedef polynomial Node_entry;
enum Error_code{underflow,overflow,success}
class Stack
{
public:
	Stack();
	Error_code pop();
	Error_code top(const Node_entry&item);
	Error_code push(Node_entry item)const;
	Stack();
	bool empty();
	~Stack();
private:
	Node *top_node;
};