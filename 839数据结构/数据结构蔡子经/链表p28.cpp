/*
	Name: ���� 
	Copyright: 
	Author: lingr7 
	Date: 04/11/18 17:17
	Description: 
*/
#include <stdio.h>
typedef struct node{
	char data;
	struct node *link;//�����ýṹ,link��ָ������͵�ָ�� 
} NODE;//NODE���������͵����֣�ͬʱ��������һ���ṹ����C����������ԡ�K&R�汾��6�½ṹ6.7���� 
NODE *head, *p, *q;//head,p,q����ָ������͵�ָ�� 
head = (NODE * )malloc(sizeof(NODE)); 
NODE *create_link_list(int n){
	int i;
	NODE *head, *p, *q;
	if(n==0)
		return NULL;
	head = (NODE*)malloc(sizeof(NODE));
	p = head;
	for(i = 1; i < n; i++){
		scanf("%c",&(p-data));
		q = (NODE*)malloc(sizeof(NODE));
		p->link = q;
		p = q; 
	}
	scanf("%c", &(p->data));
	getchar();
	p->link=NULL;
	return head;
}

