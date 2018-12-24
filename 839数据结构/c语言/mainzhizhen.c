/*
	Name: ͳ�ƹؼ��ֵĳ��ִ���������ָ��ʵ�ֵİ汾 
	Copyright: 
	Author: lingr7
	Date: 04/11/18 19:00
	Description: ָ��ṹ��ָ�� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "keytab.h"
#include "calc.h"
#define MAXWORD 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getword(char *, int);
struct key *binsearch(char *, struct key *,int);

/* ͳ�ƹؼ��ֳ��ֵĴ���������ָ�뷽ʽʵ�ֵİ汾 */
int main(int argc, char *argv[]) {
	char word[MAXWORD];
	struct key *p;
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) 
			if ((p = binsearch(word, keytab, NKEYS)) != NULL)/*keytab�Ǹ��ṹ��ָ��*/ 
				p->count++;
	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}
/* getword�������������ж�ȡ��һ�����ʻ��ַ�*/
int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);/**/ 
            break;
        }
    *w = '\0';
    return word[0];
} 
/* binsearch��������tab[0]...tab[n-1]�в�������뵥��ƥ���Ԫ�� */
struct key *binsearch(char *word, struct key *tab, int n){
	int cond;
	struct key *low = &tab[0];/*���ﲻ��ȡ��ַ�������ұ�ֱ��Ϊtab */
	struct key *high = &tab[n];/*�����粻��ȡ��ַ��������tab+n */
	struct key *mid;
	
	while (low < high) {
		mid = low + (high - low) / 2;/*ͨ��ָ������õ�һ����������ָ�����һ����*/
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return NULL;
}
