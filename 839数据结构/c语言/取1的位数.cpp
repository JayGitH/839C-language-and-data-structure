/*
	Name: 
	Copyright: 
	Author: 
	Date: 18/12/18 14:59
	Description: 
	https://blog.csdn.net/xhfight/article/details/51534666
*/
#include <stdio.h>
#include <stdlib.h>
 
 
 
int NumberOfOne(int n)
{
 int count = 0;
 /*����1�����˼· δ�����������
 while(n)
 {
  if((n&1) == 1)
  {
   count++;
  }
  n>>=1;
 }*/
/*����2���Ľ�1  32λ����Ҫѭ��32��
 unsigned int flag = 1;
 while(flag)
 {
  if(flag & n)
   count++;
  flag <<= 1;
 }*/
 
 
 //����3���ռ����� �Ż��˷���2���ж���1��ѭ�����ٴ�
	while(n)
	{
		n &= (n-1);
		count++;
	}
 
 	return count;
}
int main()
{
 	int num = -10;
 
//-10���ڴ��еĴ洢����-10�Ĳ���
 
//10000000 00000000 00000000 00001010  ->10
//11111111 11111111 11111111 11110101  ->ȡ��
 //11111111 11111111 11111111 11110110  -��+1
	int ret = NumberOfOne(num);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
 

