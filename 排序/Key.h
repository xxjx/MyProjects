class Key{
public:
	Key(char s[]);
	char*the_key()const;
private:
	char str[key_size];
};
Key::Key(char s[]){
	for(int i=0;i<=strlen(s);i++)
		str[i]=s[i];
}
char *Key::the_key()const{
	return (char*)str;
}
bool operator==(const Key&x,const Key&y);
bool operator>(const Key&x,const Key&y);
bool operator<(const Key&x,const Key&y);
bool operator>=(const Key&x,const Key&y);
bool operator>=(const Key&x,const Key&y);
bool operator!=(const Key&x,const Key&y);
