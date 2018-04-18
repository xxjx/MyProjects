enum Error_code{underflow,overflow,success};
const int maxstack=10;
template<class entry>
class Mystack
{
	public:
		Error_code push(const entry &item);
		Error_code top(entry &item);
		Error_code pop();
		Mystack();
		bool empty()const;
	private:
		int count;
		entry array[maxstack];
};


