enum Error_code{success,underflow,overflow};
const int maxqueue=20;
template<class entry>
class queue
{
public:
	queue();
	bool empty();
	Error_code append(const entry&item);
	Error_code serve();
	Error_code retrive(entry&item)const;
	void clear();
	bool full()const;
	int size()const;
private:
	int count;
	int front,rear;
	entry array[maxqueue];
};