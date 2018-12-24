/*����ͷ���Ļ���˫������*/
/*�ڴ���ͷ���Ļ��������� 
insert:��ֵΪy�Ľ�����ֵΪx�Ľ�����
delete:ɾ��ֵΪx�Ľ��*/
#include <stdio.h>
struct node{
	char data;
	struct node *llink, *rlink;
}; 
typedef struct node NODE;
NODE *head;
int insert_d_l(NODE *head, char x, char y){
	NODE *p, *q;
	p = head->rlink;
	while(p != head && p->data !=x)
		p = p->rlink;
	if (p == head)
		return 1;
	q = (NODE*)malloc(sizeof(NODE));
	q->data = y;
	q->rlink = p->rlink;
	p->rlink = q;
	q->rlink->llink = q;
	q->llink = p;
	return 0; 
}
int delete_d_l(NODE *head, char x){
	NODE *p;
	p = head->rlink;
	while(p != head && p->data != x)
		p = p->rlink;
	if(p == head)
		return 1;
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	free(p);
	return 0;
}
