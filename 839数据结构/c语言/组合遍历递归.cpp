/*
	Name: 
	Copyright: 
	Author: malic�� 
	Date: 02/12/18 10:44
	Description: ����ĳ������������Ԫ�ؾ�����ͬ����������
	���Ҫ���N������ѡM���������ϣ�
	M��N������֪����ôдM��ѭ�����б����Ϳ��ԡ�
	������ѭ������M����Ԥ��֪��������ѭ���Ͳ���ʵ�֡�
	��ʱ����ʹ���õݹ飬
	ÿ�εݹ���ý���һ��ѭ����ֱ��ѭ�������ﵽҪ��
	����������
	���������Ե��ԡ� 
*/
#include <stdio.h>
#define MAXN 20
int index[MAXN];
char a[MAXN];

void solve(int n,int m,int level)
{
   int i;
   if(m==level){/*��ʱindex�����Ѿ��������*/
	for(i=0;i<m;i++) printf("%c ",a[index[i]]);
	printf("\n"); 
	}
   else{
	for(i=index[level-1]+1;i<n;i++){
	/*������Է��ĵ�ʹ��i=index[level-1]+1;��һѭ����㣬��Ϊ��56���ֹ���ʱ��
	�����һ��65�������ظ��ˣ�����index�����Ȼ��һ����Ԫ����С�����飬
	index[level]ֻ���ܱ�index[level-1]Ҫ��*/
	   index[level]=i;
	   solve(n,m,level+1);
	}
   }
}

int main()
{
   int i,n,m;
	
   scanf("%d%d",&n,&m);
   scanf("%s",a);/*a��һ���ַ����飬Ҳ���Ե����ַ�������*/
   for(i=0;i<n;i++){/*����*/
	index[0]=i;
	solve(n,m,1);
   }
   return 0;
}
