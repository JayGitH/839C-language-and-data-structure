/*
	Name: 
	Copyright: 
	Author: malic�� 
	Date: 17/12/18 08:31
	Description: ��������Ѷȣ����������ʱ�ѣ���ʱ��û����ô�� 
	�ؼ����ڲ���ֻ��0-9���������������������������������롣 
*/
/*�塢�ļ��д����N2*N2(3<N<6)��С�ľ���,
����Ԫ�ؾ�Ϊ[1,N2]��������
����д�����ж��ļ��б���ľ����Ƿ�����������Ҫ��*/

    
#include <stdio.h>
#define MAXN 6
#define MAXRANGE 36
int main(void)
{
    FILE *fp;
    int RANGE,ORDER;
    int i,j,k1,k2;
    int judgeFlag=1;
    int sudoku[MAXRANGE][MAXRANGE];
    char bucket[MAXN*MAXN];

    fp=fopen("dataIN","r");
    fscanf(fp,"%d",&ORDER);
    RANGE=ORDER*ORDER;
    for(i=0;i<RANGE;i++)
        for(j=0;j<RANGE;j++)
            fscanf(fp,"%d",&sudoku[i][j]);/*��ά����洢*/

    for(i=0;judgeFlag==1 && i<RANGE;i++)/*����һ�ξ�����ѭ��*/
    {
        for(j=0;j<=RANGE;j++)
            bucket[j]=0;/*������Ϊһ�г��ֵ�ÿ��������Ҫ�з��ʴ����ı��*/
        for(j=0;j<RANGE;j++)
            bucket[sudoku[i][j]]+=1;/*����*/
        for(j=1;j<=RANGE;j++)
            if(bucket[j]!=1){/*���ֲ�ֹһ��*/
                judgeFlag=0;
                break;
            }
    }

    for(j=0;judgeFlag==1 && j<RANGE;j++)/*����˼·����*/
    {
        for(i=0;i<RANGE+1;i++)
            bucket[i]=0;
        for(i=0;i<RANGE;i++)
            bucket[sudoku[i][j]]+=1;/*�����ƺ����԰�*/
        for(i=1;i<=RANGE;i++)
            if(bucket[i]!=1){
                judgeFlag=0;
                break;
            }
    }

    for(k1=0;judgeFlag==1 && k1<RANGE;k1+=ORDER)
    {
        for(k2=0;judgeFlag==1 && k2<RANGE;k2+=ORDER)
        {
            for(i=0;i<RANGE+1;i++)/*1-n��ƽ������Щ���ı����ʴ���*/
                bucket[i]=0;

            for(i=0;i<ORDER;i++)
                for(j=0;j<ORDER;j++)        
                    bucket[sudoku[k1+i][k2+j]]++;

            for(i=1;i<=RANGE;i++)
                if(bucket[i]!=1)
                {
                    judgeFlag=0;
                    break;
                }
        }
    }
    if(judgeFlag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
