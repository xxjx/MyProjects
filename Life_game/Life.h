const int mrow=20,mline=60;
class Life
{
public:
	void print();
	void initialize();
	void update();
private:
	int grid[mrow+2][mline+2];
	int neighbor_count(int row,int line);
};
