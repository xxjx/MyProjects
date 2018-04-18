#include<iostream>
#include<pthread>
int thread_count;//有几个线程；
int m;
int y[5];
int x[3];
int A[5][3];
void* Pth_mat_vect(void* rank){/*void* 的意思是这是一个指针，
	你可以在函数中将这个指针转换为任何一个数据结构的指针。*/
	long my_rank=(long)rank;//数第几个线程,从0开始
	int i,j;
	int local_m=m/thread_count;//m:一共的元素个数。local_m：每个线程分到几个；
	int my_first_row=my_rank*local_m;//开始的位数
	int my_last_row=(my_rank+1)*local_m-1;//最后一位
	for(i=my_first_row;i<=my_last_row;i++){//加上了第几个
		y[i]=0.0;//和，第i个的值
		for(j=0;j<3;j++)
			y[i]+=A[i][j]*x[j];
	}
	return NULL;
}
int main()
{
	(long)rank=5;
