#include<string>
#include<iostream>
#include"Record.h"
using namespace std;
Record::Record(string ci,string exp)
{
	key=ci;
	info=exp;
}
Record::Record()
{
	key="0";
	info="0";
}
