enum Error_code{underflow, overflow, success, not_present, duplicate_error};
#include<string>
#include"Record.h"
using namespace std;
const int hash_size=500;
class Hash_table{
public:
	Hash_table();
	Error_code insert(const Record &data);
	Error_code remove(const string &data);
	Error_code retrieve(const string &data);
	int hash(const Record&data);
	int hash(const string&data);
private:       
	Record table[hash_size];
};




