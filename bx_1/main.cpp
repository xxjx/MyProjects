#include<iostream>
#include<pthread>
int thread_count;//�м����̣߳�
int m;
int y[5];
int x[3];
int A[5][3];
void* Pth_mat_vect(void* rank){/*void* ����˼������һ��ָ�룬
	������ں����н����ָ��ת��Ϊ�κ�һ�����ݽṹ��ָ�롣*/
	long my_rank=(long)rank;//���ڼ����߳�,��0��ʼ
	int i,j;
	int local_m=m/thread_count;//m:һ����Ԫ�ظ�����local_m��ÿ���̷ֵ߳�������
	int my_first_row=my_rank*local_m;//��ʼ��λ��
	int my_last_row=(my_rank+1)*local_m-1;//���һλ
	for(i=my_first_row;i<=my_last_row;i++){//�����˵ڼ���
		y[i]=0.0;//�ͣ���i����ֵ
		for(j=0;j<3;j++)
			y[i]+=A[i][j]*x[j];
	}
	return NULL;
}
int main()
{
	(long)rank=5;
