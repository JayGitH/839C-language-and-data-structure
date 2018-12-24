/*
	Name: �ļ���д���ṹ������ 
	Copyright: 
	Author: lingr7
	Date: 15/12/18 21:22
	Description: �����Ŀ���ڳ������ѣ����ļ��������ṹ�����飬�鲢������д���ļ� 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 200
struct stuNode
{
    char stuID[20];
    char name[20];
    int score;
};
typedef struct stuNode stuType;


int myCompare(stuType m,stuType n)
{
    if(m.score!=n.score)
        return n.score-m.score;
    else
        return strcmp(m.stuID,n.stuID);
}

int cmp(const void *a,const void *b)
{
    stuType m=*(stuType*)a, n=*(stuType*)b;
    return myCompare(m,n);
}
/*�������������������*/
int cmp2(const void *a,const void *b)
{
	stuType *m, *n;
	m=(stuType*)a;
	n=(stuType*)b;
	if(m->score != n->score)
        return n->score - m->score;
    else
        return strcmp(m->stuID,n->stuID);
}
void loadData(FILE* fp, stuType *m)
{
    int i=0;
    while(fscanf(fp,"%s", m[i].stuID)!=EOF)
    {
        fscanf(fp,"%s%d", m[i].name, &m[i].score);
        i++;
    }
    qsort(m,i,sizeof(stuType),cmp);
    m[i].score=-1; // set -1 as bounderһ���ڱ��������������һ���ĺ���һ��������Ϊ1 
}

void merge(stuType *a,stuType *b)
{
    stuType tmp[MAXN];
    int i=0,j=0,index=0;
    while(a[i].score>0 && b[j].score>0)/*�ڱ�����յ�*/
    {
        if(myCompare(a[i],b[j])<0)
            tmp[index++]=a[i++];
        else
            tmp[index++]=b[j++];
    }
    while(a[i].score>0)
        tmp[index++]=a[i++];
    while(a[i].score>0)
        tmp[index++]=b[j++];
    tmp[index].score=-1;
    for(i=0;i<index;i++)
        a[i]=tmp[i];/*���鲢������������a*/
}

int main(int argc,char* argv[])
{
    stuType a[MAXN],b[MAXN];
    FILE *fin1,*fin2,*fout;
    int i;
    fin1=fopen(argv[1],"r");
    fin2=fopen(argv[2],"r");
    fout=fopen(argv[3],"w");

    loadData(fin1,a);
    loadData(fin2,b);

    merge(a,b);
    for(i=0;a[i].score>0;i++)
    {
        fprintf(fout,"%s %s %d\n", a[i].stuID, a[i].name, a[i].score);
    }
	fclose(fin1);
	fclose(fin2);
	fclose(fout);
    return 0;
}
