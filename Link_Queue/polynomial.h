#include"Queue.h"
class polynomial:protected Extended_Queue
{
public:
	polynomial();
	polynomial::polynomial(const polynomial&original);
	void operator=(const polynomial&original);
	void read();
	void print()const;
	void equals_sum(polynomial p,polynomial q);
	int degree() const;
};

