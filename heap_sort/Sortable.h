const maxqueue=20;
template<class s_entry>
class Sortable{
public:
	void insert_heap(s_entry currrnt,int low,int high);
	void remove(s_entry current,int low,int high);
	void insert(s_entry);
	void radix_sort();
private:
	List<s_entry> entry[maxqueue];
	void build_heap();
	void rethread(MyQueue<Record>queues[]);
};
int alphabetic_order(char c);