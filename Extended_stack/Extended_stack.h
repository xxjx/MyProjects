enum Error_code{underflow,overflow,success};
const int maxstack=10;
template<class entry>
class Extended_stack
{
	public:
		Extended_stack();
		Error_code push(const entry &item);
		Error_code top(entry &item)const;
		Error_code pop();	
		bool empty()const;
		void clear();
		bool full()const;
		int size()const;
	private:
		int count;
		entry array[maxstack];
};

