/*
	Name: 
	Copyright: 
	Author: 
	Date: 16/12/18 22:19
	Description: ��ʱ����4����Ŀ 
*/
/*�ġ�����һ������ɾ��һ������������ظ��ڵ㣬��ʹ����ʱ������
����ԭ��Ϊ void Remove Duplicates(LINK *head); �Զ���ڵ�����LINK,�ڵ��ŵ���һ����������.*/

    
typedef struct LNode LINK;
struct LNode
{
    int data;
    LINK* Next;
};
void Remove Duplicates(LINK *head)
{
    LINK *curr,*prev,*tmp;
    curr=head;
    while(curr)
    {
        tmp=curr->Next;
        prev=curr;
        whilie(tmp)
        {
            if(tmp->data == curr->data)
            {
                prev->Next=tmp->Next;
                free(tmp);
                tmp=prev;/*free��ָ�ͷŸ�ָ��ָ��Ŀռ䣬Ҳ����˵�ռ䡰��ʧ������ָ��Ҳ����ָ����һ�ռ䣬���Ұָ��*/
            }
            tmp=tmp->Next;
        }
        curr=curr->Next;
    }
}
