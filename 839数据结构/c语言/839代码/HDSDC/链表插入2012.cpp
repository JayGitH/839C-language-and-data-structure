#include<stdio.h>
#include<malloc.h>
typedef struct LNode{
int data;
struct LNode *next;
}NODE;
NODE *Insert(NODE *head,NODE *p){
 	if(head==NULL){
 		p->next=NULL;
 		return p;
	 }
	NODE *q=head,*r=head->next;
	if(q->data>p->data){
		p->next=q;
		head=p;
		return head;
	}
	while(p->data>r->data&&r!=NULL){
		 q=r;
		 r=r->next;		 	
	}
 	q->next=p;
 	p->next=r;
	return head;
 
}
struct LNode *creat(int n){
	int i;
	struct LNode *head,*p1,*p2;
	int a;
	head=NULL;
	for(i=1;i<=n;i++){
	p1=(struct LNode *)malloc(sizeof(struct LNode));
	printf("�����������еĵ�%d������",i);
	
	scanf("%d",&a);
	p1->data=a;
	if(head==NULL){
       head=p1;
       p2=p1;
    }
    else{
	p2->next=p1;
	p2=p1;
	}
	p2->next=NULL; 
	}
    return head; 
}
int main(){
	int n;
	struct LNode *q,*r,*m;
	int a;
	printf("����������ĳ��ȣ�\n(��ȫ��������������\n��������sb)");
	scanf("%d",&n);
	if(!(n>0&&n<9)) {printf("����sb");return 0; }
	printf("������Ҫ�������:\n");
	scanf("%d",&a);
	q=creat(n); 
	r=(struct LNode *)malloc(sizeof(struct LNode));
	r->data=a; 
	m=Insert(q,r);
	printf("\n�����е����ݣ�\n");
	while(m){
	printf("%d ",m->data);/*�������е�ֵ*/
	m=m->next;/*ָ����һ�����*/
	}
return 0;
}
