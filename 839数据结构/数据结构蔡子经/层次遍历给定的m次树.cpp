/*
	Name: ��α���������m���� 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 21:40
	Description: ʹ��˳��洢�Ķ��д�Ż�û�д���������ĸ����ĵ�ַ��
	�������еĽ��ֵ���ַ�������׼��ʽ�洢����������
	���������ʹ�õĶ��в�����ֶ�������������
	ע�⣬����Ķ��׺Ͷ�βָ��ֱ�ָ����׽����´ν��ӽ��Ĵ��λ�á� 
*/
void levorder(NODE *t, int m)
{
	NODE *q[100], *p;
	int head, tail, i;
	q[0] = t;
	head = 0;
	tail = 1;
	while (head < tail)
	{
		p = q[head+1];
		printf("%c", p->data);
		for (i = 0; i < m; i++)
		{
			if (p->child[i] != NULL)
				q[tail++] = p->child[i]; 
		} 
	}
}
