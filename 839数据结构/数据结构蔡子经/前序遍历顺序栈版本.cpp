/*
	Name: ǰ�������ջ�汾 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 21:11
	Description: ʵ��ǰ���������ջ��ʵ�ֵݹ��Ч����
	ʹ��˳��洢��ջs[100],ջ��ָ����top,ջԪ�������100����
	���費�����ջ���������� 
*/
void s_preorder(NODE *t, int m)
{
	NODE *s[100];
	int top, i;
	if (t == NULL)
		return;
	s[0] = t;
	top = 1;
	while (top > 0)
	{
		t = s[--top];
		printf("%c", t->data);
		for(i = m-1; i>=0; i--)
		{
			if (t->child[i] != NULL)
				s[top++] = t->child[i];
		}
	 } 
}
