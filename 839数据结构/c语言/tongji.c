#include <stdio.h>
#include <ctype.h>
#define MAXWORD 100
#define MAXLEN 1000
/*�������ж�ȡ��һ�����ʻ��ַ�*/

char *getword(char *word, int lim);
char getch();
void ungetch(char);
char allocbuf[MAXLEN] = "af"; 
int bufp = 2;

int main()
{
    char word[MAXWORD];
    printf("%s\n", getword(word, MAXWORD));
    return 0;
}
//�������ж�ȡ��һ�����ʻ��ַ������ص�һ���ַ�
char *getword(char *word, int lim)
{
    char c, *p = word;   //, *w = word;  //�˴�������һ��ʼ�Լ��ó���������ĵط�����Ϊ��û�а��տα���д����������

    *w = word; ȫ���붼�Ƕ� word��ַ���в�����������е�ַ++�ȵȣ��������֣�������������Ĵ������ǿս����Ȼ���ҳ�ԭ������������������Ĳ��� *word ���в��������ܱ�����������Ҳ��������������У�ϵͳֻ�ǽ�  char *word����char���͵�word����ʹ�ö��ѣ����ԣ�Ҫ�봢���word�Ĳ����������Ƚ� *w = word ���е�ַ���룬�� *w ��������
    while(isspace(c = getch()))
        ;
    if(c != EOF){
        *word++ = c;
        //w++;
    }
    if(!isalpha(c)){
        *word = '\0';
        return c;
    }
    for(; --lim > 0; word++){

        if(!isalnum(*word = getch())){
            ungetch(*word);
            break;
        }
    }
    *word = '\0';
    return p;
}
//��ȡ�ַ�
char getch()
{
    char c;
    if(bufp == 0)
    {
        printf("��Ҫ�ֶ�����\n");
        c = getchar();
        getchar();  //������ȡ��һ��getchar֮������Ļ��з�����Ȼ�Ļ���������Զ������з�������һ��������ַ���Ȼ����ֹ                             ���� ����ǿα���û�е�һ�д��롣
        return c;
    }
    else
        return allocbuf[--bufp];
    //return (bufp > 0)  allocbuf[--bufp]: getchar();  
}
//�����ַ�
void ungetch(char c)
{
    if(bufp >= MAXLEN)
        printf("the buf is too big.\n");
    else
        allocbuf[bufp++] = c;
}
/* --------------------- 
���ߣ�yjysunshine 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/yjysunshine/article/details/82561340 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ� */
