#include"Node.h"
template<class List_entry>
class List{
public:
	List();
protected:
	int count;
	mutable int current_position;
	mutable Node<List_entry>*current;
	void set_position(int position)const;

	