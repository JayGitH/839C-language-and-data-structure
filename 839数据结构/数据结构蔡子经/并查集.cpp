/*
	Name: ������ʾ����findӦ���۵����� 
	Copyright: 
	Author: 
	Date: 14/11/18 19:39
	Description: �۵�����·��ѹ����ѭ��
	���ҵ�����㣬Ȼ���·���Ͼ����Ľ�㣬ȫ��ָ�����㣬��ȫ���ĸ��ڵ�Ϊ����� 
*/

int find_set(NODE s[], int i)
{
	int j, k;
	k = i;
	while (s[k].parent>=0)
		k = s[k].parent;
	while (i != k)
		{
			j = s[i].parent;
			s[i].parent = k;
			i = j;
		}
	return k;
}
