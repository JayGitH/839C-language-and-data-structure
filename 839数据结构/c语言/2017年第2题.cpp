/*
	Name: 
	Copyright: 
	Author: 
	Date: 18/12/18 15:00
	Description: ֻ��ȡ�����ұ�һλ����ø���������ʽ 
	32λ�汾 
*/
#include <stdio.h>
void print_b(int n);
unsigned int invert(int x , int p , int n)/*�ض�λȡ��*/
{
    unsigned int mask= (~(~0<<n)<<(p-n));/*��ȷ���*/
    /*~(~(~0<<n)<<(p+1-n))*/
	return x^mask;
}
unsigned int invert2(int x , int p , int n)/*�ִ�*/
{
    unsigned int mask= ~(~(~0<<n)<<(p+1-n));
	return x^mask;
}
void print_b(int n){/*����з��������Ķ�����λ��ʽ*/
	int a[32];
	int i = 0;
	while(i<32){
		a[i] = n & 1;
		n >>= 1;
		i++; 
	}
	for(i = 31; i >= 0; i--){
		printf("%d", a[i]);
	}
	printf("\n");
}
int main(){
	print_b(1);
	print_b(invert(1, 5 ,2));
	//print_b(invert2(1, 5 ,2));
	/* p==5, n==2���ұ�����pλ����������nλ*/
	/*���5λ���4λȡ��*/
	print_b(0^1);/*���1*/
	print_b(1^1); /*���0*/
	/*��1��򼴿�ȡ��*/
	return 0;
}
