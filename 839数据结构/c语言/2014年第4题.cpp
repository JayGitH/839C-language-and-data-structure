/*
	Name: 
	Copyright: 
	Author:����Ŀ���ڻ����⣬7-6�����6�� 
	Date: 16/12/18 20:17
	Description: 
*/
/*�����⣬��Ҫ��дsplit����

���split����3��������*string�Ǵ��ָ���ַ�����key�Ƿָ�����a[][]��Ŀ������
index��¼�ܹ��ָ�Ĵ��������ָ������Ϊsplit�ķ���ֵ*/

#include <stdio.h>
int split(char* string,char key,char a[100][100])
{
    int i,index=0,k=0;

    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]!=key)
        {
            a[index][k]=string[i];
            ++k;
        }
        else
        {
            a[index][k]=0;
            index++;
            k=0;
        }
    }
    return index;
}
