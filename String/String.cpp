#include"Srting.h"
String::String()
{
	length=0;
	entries=new char [1];
	entries[0]='\0';
}
const char* String::c_str()const;
{
	return (const char *)entries;//∑µªÿ÷∏’Î£ø
}
String::String(const String&copy)
{
	entries=new char[copy.length+1];
	strcpy(entries, copy.c_str());
	length=copy.length;
}
String::String(List<char>&copy)
{
	length=copy.size();
	entries=new char[copy.length+1];
	for(int i=0;i<length;i++)
		copy.retrive(i,entries[i]);
	entries[length]='\0';
}
void operator=(const String&copy)
{
	return strcmp(c_str(),copy.c_str())==0;
}





