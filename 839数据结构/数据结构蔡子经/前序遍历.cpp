/*
	Name: ǰ������ݹ�汾 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 21:09
	Description: �����ƺ�Ĭ��m��������������m������ 
*/
#include <stdio.h>
#define MAXM 10
struct node {
	char data;
	struct node *child[MAXM];
};
typedef struct node NODE;
int m;
NODE *t;

/*�ݹ麯��ʵ�ֶԸ�����m������ǰ�����*/
void r_preorder(NODE *t, int m)
{
	int i;
	if (t != NULL)
		{
			printf("%c", t->data);
			for (i = 0; i < m; i++)
				r_preorder(t->child[i]);
		}
}
