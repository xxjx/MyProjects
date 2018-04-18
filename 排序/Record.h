#include"Key.h"
class Record{
public:

	Record(char s[]="");
	operator Key();
	char *the_key()const;
private:
	char str[key_size];
};


Record::Record(char s[]){
	for(int i=0;i<=strlen(s);i++)
		str[i]=s[i];
}
Record::operator Key(){
	Key tmp(str);

}

char *Record::the_key()const{
	return (char *)str;
}
ostream&operator<<(ostream&output,Record&x);