class Key {

	int key;

public:

	Key (int x = 0);

	int the_key( ) const;

};



bool operator == (const Key &x, const Key &y);