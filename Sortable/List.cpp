#include"List.h"

template <class List_entry>

List<List_entry> :: List()

{

	count = 0;

	head = NULL;

	current_position = 0;

	current = NULL;

}



template <class List_entry>

List<List_entry> :: List(const List<List_entry> &copy)

{

	count = 0;

	head = NULL;

	current_position = 0;

	current = NULL;

	Node<List_entry> *q = copy.head;

	int i=0;

	while(q){

		insert(i,q->entry);

		q=q->next;

		i++;

	}

/*	//Another method

	count = 0;

	current_position = 0;

	current = NULL;

	Node<List_entry> *new_copy, *p_copy = copy.head;

    if (p_copy == NULL) head = NULL;

    else {                         //  Duplicate the linked nodes using base method.

      head = new_copy = new Node<List_entry>(p_copy->entry);

	  count++;

      while (p_copy->next) {

         p_copy = p_copy->next;

         new_copy->next = new Node<List_entry>(p_copy->entry);

		 count++;

         new_copy = new_copy->next;

	  }

    }

*/

}



template <class List_entry>

void List<List_entry> :: operator = (const List<List_entry> &copy)

{

	List_entry x;

	while(!empty())remove(0,x);

	Node<List_entry> *q = copy.head;

	int i=0;

	while(q){

		insert(i,q->entry);

		q=q->next;

		i++;

	}



}



template <class List_entry>

List<List_entry> :: ~List( )

{

	List_entry x;

	while(!empty())remove(0,x);

}



template <class List_entry>

void List<List_entry> :: set_position(int position) const

/* Pre: position is a valid position in the List : 0 <= position < count .

Post: The current Node pointer references the Node at position . */

{

	if (position < current_position) { // must start over at head of list

		current_position = 0;

		current = head;

	}



	for (; current_position != position; current_position++)

		current = current->next;

}





template <class List_entry>

int List<List_entry> :: size() const

{

	return count;

}



template <class List_entry>

bool List<List_entry> :: full() const

{

	Node<List_entry> *new_node;

	new_node = new Node<List_entry>;

	if (new_node == NULL)return true;

	else {

		delete new_node;

		return false;

	}

}



template <class List_entry>

bool List<List_entry> :: empty() const

{

	return count==0;

}



template <class List_entry>

void List<List_entry> :: clear()

{

	List_entry x;

	while(!empty())remove(0,x);

}



template <class List_entry>

void List<List_entry> :: traverse(void (*visit)(List_entry &))

{

	Node<List_entry> *p_node=head;

	while(p_node){

		(*visit)(p_node->entry);

		p_node=p_node->next;

	}

}



template <class List_entry>

Error_code List<List_entry> :: retrieve(int position, List_entry &x) const

{

	if (position < 0 || position >= count)

		return range_error;

	Node<List_entry> *p_node;

	set_position(position);

	x=current->entry;

	return success;

}



template <class List_entry>

Error_code List<List_entry> :: replace(int position, const List_entry &x)

{

	if (position < 0 || position >= count)

		return range_error;

	Node<List_entry> *p_node;

	set_position(position);

	current->entry=x;

	return success;

}



template <class List_entry>

Error_code List<List_entry> :: remove(int position, List_entry &x)

{

	if (position < 0 || position >= count)

		return range_error;

	Node<List_entry> *previous, *following;

	if (position > 0) {

		set_position(position - 1);

		previous = current;

		following = previous->next;

		previous->next=following->next;

	}

	else{

		following = head;

		head = head->next;

		//should be added

		current_position = 0;

		current = head;

	}

	delete following;

    count--;

	return success;

}



template <class List_entry>

Error_code List<List_entry> :: insert(int position, const List_entry &x)

/* Post: If the List is not full and 0 <= position <= n , where n is the number of

entries in the List , the function succeeds: Any entry formerly at position and

all later entries have their position numbers increased by 1, and x is inserted at

position of the List .

Else: The function fails with a diagnostic error code. */

{

	if (position < 0 || position > count)

		return range_error;

	Node<List_entry> *new_node, *previous, *following;

	if (position > 0) {

		set_position(position - 1);

		previous = current;

		following = previous->next;

	}

	else following = head;

	new_node = new Node<List_entry>(x, following);

	if (new_node == NULL)

		return overflow;

	if (position == 0){

		head = new_node;

		//should be added

		current_position = 0;

		current = head;

	}

	else{

		previous->next = new_node;

		//should be added

		set_position(position);

	}

	count++;

	return success;

}

