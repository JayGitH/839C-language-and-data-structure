/*
	Name: ���x���������Ƚ�� 
	Copyright: 
	Author: 11¥ 
	Date: 15/12/18 20:00
	Description: ������һ���޸� 
*/
typedef struct Tree {
	int data;
	Tree *lchild;
	Tree *rchild;
}Tree;

int IsAnce(Tree *t,int x) {
	if (t) {
		if (t->data == x)
			return 1;
		else
			return IsAnce(t->lchild, x) || IsAnce(t->rchild, x);
	}
	return 0;
}

void OutX(Tree *t,int x) {
	if (IsAnce(t,x))
		printf("%d", t->data);/*��һ���ǵݹ����*/
	OutX(t->lchild, x);
	OutX(t->rchild, x);
}
