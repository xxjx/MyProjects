template<class Record>//Ƶ�����ֵķ������棬���ҷ�����ڹ��С�
class Splay_tree:public Search_tree<Record>{
	public:
		Error_code splay(const Record&target);
	private:
		void link_right(Binary_node<Record>*&current,Binary_node<Record>*&first_large);
	    void link_left(Binary_node<Record>*&current,Binary_node<Record>*&first_large);
		void Splay_tree<Record> rotate_left(Binary_node<Record> *&current);
		void Splay_tree<Record> rotate_right(Binary_node<Record> *&current);
};