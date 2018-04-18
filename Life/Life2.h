const mline=60;
class Life
{
public:
	void initialize();
	void update();
	void print();
private:
	int count_neighbor(int line);
	int array[mline+4];
};
  
