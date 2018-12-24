/*
	Name: ���ǽṹ�������ļ���д 
	Copyright: 
	Author: malic�� 
	Date: 15/12/18 21:43
	Description: 
	�塢�ı��ļ�data.in���У�
	�ж������֣�
	ÿ����4��������x1 y1 x2 y2��
	�ֱ��ʾ���ε����½������ϽǶ������������(x1,y1) (x2,y2).
��������дһ������
����Щ���ν�������
����Ĺ���Ϊ��
�Ȱ����������С��������
��������ͬ��
�����½Ƕ��㵽ԭ��ľ����С��������
�������ͬ�������½Ƕ���ĺ�����x1��С��������
��������������д���ļ�data.out���У�
���Ϊ0�ľ��β����
*/

#include <stdio.h>
#define MAXN 200
struct pNode
{
    double x1,y1;
    double x2,y2;
    double area,distance;
};
typedef struct pNode Point;

int cmp(const void *a,const void *b)
{
    Point m=*(Point*)a,n=*(Point*)b;
    if(m.area!=n.area)
        return m.area-n.area;
    else if(m.distance!=n.distance)
        return m.distance-n.distance;
    else
        return m.x1-n.x1;
}

int main(void)
{
    FILE *fp,*fout;
    int i=0,N;
    Point a[MAXN];

    fp=fopen("data.in","r");
    while(fscanf(fp,"%f",&a[i].x1))
    {
        fscanf(fp,"%f%f%f",&a[i].y1,&a[i].x2,&a[i].y2);
        a[i].area=(a[i].y2-a[i].y1)*(a[i].x2-a[i].x1);
        a[i].distance=a[i].x1*a[i].x1+a[i].y1*a[i].y1;
        i++;
    }
    fclose(fp);

    N=i;
    qsort(a,N,sizeof(a[0]),cmp);

    fout=fopen("data.out","w");
    for(i=0;i<N;i++)
    {
        fprintf(fout,"%f %f %f %f\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2);
    }
    fclose(fout);
    return 0;
}
