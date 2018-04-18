enum Error_code{underflow, overflow, success};
const int maxqueue=5;
template<class	entry>
class Queue{
public:
	Queue();
	bool empty() const;
	Error_code serve();
	Error_code append(const entry&x);
	Error_code retrieve(entry&x)const;
	bool full()const;
	int size()const;
	void clear();
	Error_code serve_and_retrive(entry &item);
private:
	int count;
	int front;
	int rear;
	entry array[maxqueue];
};
	

