/*
	Name: ��׼�������Ƿ���������� 
	Copyright: 
	Author: lingr7
	Date: 15/12/18 16:34
	Description: ���Ƚ���׼�洢�Ķ�������ͨ���������ת��Ϊ�ѳ��õ�һά������ʽ������������Ϊ����
	 ��n�����Ķ����������������±�0λ����㣬������λ�õ���������ѵ�������δ������������ѵ���������kΪ��ǣ�
	 ������ֵkΪ1������������������Ϊ0�������������� 
	2017��ĵھ��⣬��һ���汾����Ŀ���������˼·����һ��û������������һ�����������⣬��������д����Ҳֵ�ˡ� 
*/	 
struct TreeNode{
	int data;
	Node *lchild;
	Node *rchild;
};
typedef TreeNode Node;
int Judge_Heap(Node *t, int n)
{
	int heap[100];
	int head;
	int tail;
	int i;
	Node *p, *q[100];
	q[0] = t;
	head = 0;
	tail = 1;
	i = 0;
	heap[0] = t->data;
	while(head < tail){
		p = q[++head];
		if(p->lchild != NULL){
			q[++tail] = p->lchild;
			heap[++i] = p->lchild->data;
		}	
		if(p->rchild != NULL){
			q[++tail] = p->rchild; 
			heap[++i] = p->rchild->data;
		}	
	}
	i = 0;
	int j, k;
	k = 0;
	t = a[i];
	while((j = 2*i +1) < n){
		if (j < n-1 && a[j] < a[j+1])
			j++;
		if (t < a[j]){
			a[(j-1)/2] = a[j];
			i = j;
			k = 1;
		}
		else break;
	}
	a[(j-1)/2] = t;
	return k;
}
/*���õĴ𰸣�����ע�⵽�ж��Ƿ���ȫ�����������Ҿ��öѲ��Ǳ�������ȫ��������*/
int estimate_stack(Node *t,int *n)
{
	int a = 1,b = 1;//��־λ
	int n1 = 0,n2 = 0;
	if(t)
    {
//������������������ж�ֵ�Ƿ�������������������ٵݹ��ж��������Ƿ����������������յĽ��&&����
		if(t->lc)
			a = (t->data >= t->lc->data) && estimate_stack(t->lc,&n1);
//����������Ѿ��������ˣ����ü����ݹ���������
        if(t->rc && a)
			b = (t->data >= t->rc->data) && estimate_stack(t->rc,&n2);
//����������������������������٣�������ȫ������ 
        if(n1 < n2)
			a = b = 0;
//����������1Ϊ�Լ���ǰ�Ľڵ����
        *n = n1 + n2 + 1;
	}
	else
		*n = 0;
//���Ϊ�գ����ʾ����ڵ����㶨��
    return a && b;
}
/*�򻯰汾Ҳ�������հ汾*/
int estimate_stack(Node *t)
{
	int a = 1,b = 1;//��־λ
	if(t)
    {
//������������������ж�ֵ�Ƿ�������������������ٵݹ��ж��������Ƿ����������������յĽ��&&����
		if(t->lc)
			a = (t->data >= t->lc->data) && estimate_stack(t->lc);
//����������Ѿ��������ˣ����ü����ݹ���������
        if(t->rc && a)
			b = (t->data >= t->rc->data) && estimate_stack(t->rc);
	}
//���Ϊ�գ����ʾ����ڵ����㶨��
    return a && b;
}
