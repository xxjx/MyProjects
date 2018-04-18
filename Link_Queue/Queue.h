enum Error_code{underflow,overflow,success};
#include"Term.h"
typedef Term SmallNode_entry;
typedef Term Queue_entry;
class SmallNode{
public:
	SmallNode_entry entry;
	SmallNode *next;
	SmallNode();
	SmallNode(SmallNode_entry number,SmallNode*add=0);
};
class Queue
{
public:
	Queue();
	Error_code append(const Queue_entry&item);
	Error_code serve();
	Error_code retrieve(Queue_entry&sth)const;
	bool empty()const;
	~Queue();
protected:
	SmallNode*front;
	SmallNode*rear;
};
class Extended_Queue:public Queue
{
public:
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry&item);
};

	