#pragma once
#include"List.cpp"
#include"Record.h"
#include<string>
using namespace std;
class Ordered_search:public List<Record>{
public:
	Error_code insert(const Record&data);
	Error_code Delete(const string&data);
	Error_code print(const string&data);
	void now_ordered();
protected:
	Error_code find(const string&data,int&position);
};
