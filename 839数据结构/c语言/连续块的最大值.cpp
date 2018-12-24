/*
	Name: 
	Copyright: 
	Author: malic�� 
	Date: 06/12/18 09:50
	Description: 
*/
#include <stdio.h>

int dfs(int *a,int h,int w,int x,int y)
{
    int nx,ny,k,count=1;
    int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    *(a+w*x+y)=0;/*��ɷ��ʱ�ǣ�����������ʹ��ģ�������*/
    for(k=0;k<4;k++){/*��4����������ڽ���̽��*/
        nx=x+directions[k][0];
        ny=y+directions[k][1];
        if(nx<h && nx>=0  && ny<w && ny>=0)/*���ڵ�������*/
        {
            if(*(a+w*nx+ny)==1)/*�õ�Ϊ1*/
                count+=dfs(a,h,w,nx,ny);/*������һ��Ԫ��*/
        }
	}
    return count;
}

int maxBlock(int **a,int h,int w)
{
    int i,j,maxCount=-1,currCount=-1;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(*((int *)a+i*w+j)==1){

                currCount=dfs((int *)a,h,w,i,j);
                if(currCount>maxCount)
                    maxCount=currCount;
            }
            }
    }

    return maxCount;
}

int main()
{
    int a[5][10] = {
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    };
    printf("%d\n",maxBlock((int **)a, 5, 10));/*c++��c�Ĳ�ͬ��cֱ����a���ɣ�������ʾ��ת��*/
    return 0;
}
