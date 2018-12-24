#include <stdio.h>  
#include <stdlib.h>  
#include<malloc.h>
typedef struct Node  
{  
    int data;  
    struct Node *pNext;  
    struct Node *pPre;  
}NODE, *pNODE;  
 
//����˫��ѭ������  
pNODE Create(void)  
{  
    int i, length = 0, data = 0;  
    pNODE p_new = NULL, pTail = NULL;  
    pNODE pHead = (pNODE)malloc(sizeof(NODE));  
  
    if (NULL == pHead)  
    {  
        printf("�ڴ����ʧ�ܣ�\n");  
        exit(1);  
    }  
    pHead->data = 0;  
    pHead->pNext = pHead;  
    pHead->pPre = pHead;  
    pTail = pHead;  
  
    printf("��������Ҫ��������ĳ��ȣ�");  
    scanf("%d", &length);  
  
    for (i=1; i<length+1; i++)  
    {  
        p_new = (pNODE)malloc(sizeof(NODE));  
  
        if (NULL == p_new)  
        {  
            printf("�ڴ����ʧ�ܣ�\n");  
            exit(1);  
        }  
  
        printf("�������%d���ڵ�Ԫ��ֵ��", i);  
        scanf("%d", &data);  
  
        p_new->data = data;  
        p_new->pPre = pTail;  
        p_new->pNext = pHead;  
        pTail->pNext = p_new;  
        pHead->pPre = p_new;  
        pTail = p_new;  
    }  
    return pHead;  
} 
void TraverList(pNODE pHead)  
{  
    pNODE pt = pHead->pNext;  
  
    printf("�����ӡ�磺");  
    while (pt != pHead)  
    {  
        printf("%d ", pt->data);  
        pt = pt->pNext;  
    }  
    putchar('\n');  
}  
int  Judge(pNODE L){
	Node *p=L->pNext,*q=L->pPre;
	while(p!=q&&p->pNext!=q){
		if(p->data!=q->data) return 0;
		p=p->pNext;q=q->pPre;
	}
	return 1;
}
int main(){
	Node *p;int n;
	p=Create();
	n=Judge(p);
	if(n)  printf("\n��");
	else printf("\n����");
	return 0;
}
