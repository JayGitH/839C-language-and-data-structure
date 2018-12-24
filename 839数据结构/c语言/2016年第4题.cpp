/*
	Name: �����ڲ���ʹ����ʱ�Ľ�㻺���� 
	Copyright: 
	Author: 
	Date: 15/12/18 21:44
	Description: 
	�ġ�д��������
���庯��sortLinkedList(h)��
�佫h��ָ��һ����������
���սڵ��д�ŵ��ַ���ֵ���ֵ���������
����ָ�������ĵ�һ���ڵ��ָ�롣
����ʹ����ʱ�Ľ�㻺������
����ԭ��Ϊ��NODE* sortLinkedList(char *data;struct Node *next;)NODE;
����dataָ�򲻵ȳ����ַ������ʾ���ַ�����
*/

typedef struct Node{
    char *data;
    struct Node *next;
}Node;

Node* sortLinkedList(Node *h)
{
    if(!h->next)
    {
        return h;
    }
    Node *node = h, *l = NULL, *r = NULL, *rnode = NULL, *lnode = NULL, *hr = h;
    /*��ͷ���С�ķ�����������ķ���������*/
    while(node->next)
    {
        if(*h->data - *node->next->data > 0)//- -ȡָ����
        {
            if(!l)
            {
                l = lnode = node->next;//��ʼ������ͷ���͹����ڵ�
            }
            else
            {
                lnode->next = node->next;
                lnode = lnode->next;
            }
            node = node->next;
        }
        else if(*h->data - *node->next->data == 0)
        {
            hr->next = node->next;
            hr = hr->next;
            node = node->next;
        }
        else
        {
            if(!r)
            {
                r = rnode = node->next;
            }
            else
            {
                rnode->next = node->next;
                rnode = rnode->next;
            }
            node = node->next;
        }
    }
    lnode->next = NULL;//�ض�������
    rnode->next = NULL;
    /*�ݹ���������������ԭͷ���*/
    if(l)
    {
        l = sortLinkedList(l);
        lnode = l;
        while(lnode->next)
        {
            lnode = lnode->next;
        }
        lnode->next = h;
    }
    else
    {
        l = h;
    }
    if(r)
    {
        r = sortLinkedList(r);
    }
    hr->next = r;
    return l;
}

void PrintList(Node *h)
{
    while(h)
    {
        printf("%c", *h->data);
        h = h->next;
    }
    putchar('\n');
}

Node* newNode()
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = (char*)malloc(sizeof(char));//dataҲ��ָ��ҲҪ�����ڴ���ܸ�ֵ
    node->next = NULL;
    return node;
}

char getChar()
{
    char c;
    while((c = (char)getchar()) <= ' ');
    return c;
}

Node* CreateLinkedList()
{
    Node *prenode = newNode();
    Node *h = prenode, *node = NULL;
    int n;
    scanf("%d", &n);
    *prenode->data = getChar();
    for (int i = 1; i<n; ++i)
    {
        node = newNode();
        *node->data = getChar();
        prenode->next = node;
        prenode = node;
        node = node->next;
    }
    return h;
}

int main()
{
    Node* h = CreateLinkedList();
    PrintList(h);
    h = sortLinkedList(h);
    PrintList(h);
}
//5 d b a c e
