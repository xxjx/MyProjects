#include "utility.h"

const int maxqueue = 200; //  small value for testing



template<class Queue_entry>

class MyQueue {

public:

   MyQueue();

   bool empty() const;

   Error_code serve();

   Error_code append(const Queue_entry &item);

   Error_code retrieve(Queue_entry &item) const;

   bool full() const;

   int size() const;

   void clear();

   Error_code serve_and_retrieve(Queue_entry &item);

private:

   int count;

   int front, rear;

   Queue_entry entry[maxqueue];

};