/*1.4.2�����������ʾ����ʽ*/
/*
	Name: ����ʽ�ӷ� 
	Copyright: 
	Author: lingr7
	Date: 11/11/18 13:15
	Description: ���ӽ��ռ�Ĵ������ҪС�����⣬
	switch���Զ��ַ�����Ҳ�ǻ�ü� 
*/

/*��ʾ��������ʽ��ӡ�
���е�һ����������һ���µĽ�㣬
��ϵ��Ϊc��ָ��Ϊe,
�����½�����pc��ָ�Ľ��֮��
Ȼ�󷵻��½��ĵ�ַ��
�ڶ�������ʵ������������ah,bh��ʾ����������ʽ��ӣ�
Ϊ�˴����ϵķ��㣬
�ڽ������֮ǰ��
���Ȳ���һ�����ӽ�㣬
�ڵõ��������ʽ����������֮��
��ɾ��������ӽ�㡣*/
include <stdio.h>
struct node{
	int coef;/*���ϵ��*/
	int exp;/*��Ŵ���*/
	struct node *link;/*�����ýṹ�������һ���ַ*/ 
};
typedef struct node NODE;
NODE *ah, *bh, *ch;
NODE *insert(NODE *pc, int c, int e){
	NODE *t;
	t = (NODE*)malloc(sizeof(NODE));
	t->coef = c;
	pc->link = t;
	return t;
}
NODE *polyadd_1(NODE *ah, NODE *bh){
	NODE *pa, *pb, *ch, *pc;
	char c;
	ch = (NODE*)malloc(sizeof(NODE));
	pc = ch;
	pa = ah;
	pb = bh;
	/*����������ʽ�У�������ͬ��ϵ��ȡ�ͣ�
	������ͬʱ��ȡ�����ϸߵ��Ǹ���ϵ����
	��ȡ���Ľ��͹��������ظ�ȡ������һ���*/
	while(pa !=NULL && pb != NULL){
		if (pa->exp == pb->exp)
			c = '=';
		else if(pa->exp > pb->exp)
			c = '>';
		else 
			c = '<';
		switch(c);
		{
			case '=':
				if(pa->coef + pb->coef != 0){
					pc = insert(pc, pa->coef + pb->coef, pa->exp);
				}
				pa = pa->link;
				pb = pb->link;
				break;
			case '>':
				pc = insert(pc, pa->coef, pa->exp);
				pa = pa->link;
				break;
			case '<':
				pc = insert(pc, pb->coef, pb->exp);
				pb = pb->link;
				break; 		
		}
	}
	/*����ah��bhĳһ���Ѿ�ȡ��ģ�ûȡ����Ǹ�����*/
	while (pa != NULL){
		pc = insert(pc, pa->coef, pa->exp);
		pa = pa->link;
	}
	while (pb != NULL){
		pc = insert(pc, pb->coef,pb->exp);
		pb = pb->link;
	}
	pc->link = NULL;/*�������ʽ����ռ����*/
	pc = ch;
	ch = ch->link;/*���ﻹ��return ������ڶ���ʽ������ȥ����һ�����ӽ�㣨���ӽ��coef����expΪ�գ�*/
	free(pc);/*���ڿ����ͷŵ������Ǹ����ӽ��ռ�õĿռ���*/
	return ch;
}
int main(){
	
	
	
	
	
	
	
	return 0;
} 
