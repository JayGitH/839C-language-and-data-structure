/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/11/18 22:30
	Description: ����֤����ά�������������ֵ����һ�е�ֵ����һ�е�һ�еĵ�ַ��ͬ���Ķ��� 
    ������a+1���ƶ�����һ������������ָ����һ����������ͬʱָ����������ĵ�һ��Ԫ�� 
*/
#include<stdio.h>

int main() {

    int a[2][3] = {{1,2,3},{4,5,6}};

    printf("\n");
    printf("a[0]��ֵ:%x\n",a[0]);
    printf("a[0][0]�ĵ�ַ:%x\n",&a[0][0]);
    printf("a��ֵ:%x\n",a);

    printf("\n");
    printf("a[1]��ֵ:%x\n",a[1]);
    printf("a[1][0]�ĵ�ַ:%x\n",&a[1][0]);
    printf("a+1��ֵ:%x\n",a+1);

}
