/*
	Name: �ж�����ͼ�Ƿ��л� 
	Copyright: 
	Author: lingr7
	Date: 15/12/18 10:34
	Description: ������������˼�� �����i==n��ô������ͼ���޻� 
	����Ѱ�Ҷ�Ϊ1�Ľ�� 
*/
struct CH_NODE{
	int count;
	struct CH_NODE *head;
};
struct VL_NODE{
	int ver;
	struct VL_NODE *link;
};
CH_NODE ch[6];/*�±�1-5��¼5�������ͷָ��*/
int tpv[100];/*��¼�������*/
int topol_order(CH_NODE ch[5], int n, int tpv[]){
	int i, j, k, head, tail;
	VL_NODE *t;
	head = -1;
	tail = -1;
	int queue[100];/*����*/
	for(i = 1; i <= n; i++){
		if(ch[i].count == 1)
			queue[++tail] = i;/*��Ϊ1�Ķ������*/
	}
	i = 0;
	while(head < tail)/*���в���*/{
		j = queue[++head];/*����*/
		tpv[i++] = j;
		t = ch[j].head;
		while(t != NULL){
			k = t->ver;
			if(--(ch[k].count) == 1)
				queue[++tail] = k; 
			t = t->link;
		} 
	}
	return i;/*i��¼��������ӵĶ�����Ŀ*/
} 
 
