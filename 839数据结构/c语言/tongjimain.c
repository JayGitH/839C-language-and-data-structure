/*
	Name: ͳ��c���Թؼ��ֳ��ִ��� 
	Copyright: 
	Author: lingr7
	Date: 21/10/18 10:05
	Description: ��ȫ���ݡ�C����������ԡ�K&R�汾6.3�ṹ�������ݱ�д����dev c++5.11�б������гɹ�
	һ����Ŀ�ļ�.dev,�ں�calc.h,getch.c,getop.c,keytab.h,stack.c,tongjimain.c.5�����ļ� 
	�ؼ��ֽṹ������keytab.h�ж��壬���������޸ĸñ���ҩע�⣬���������˳��������ֵ������� 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"
#include "keytab.h"

#define MAXWORD 100

int getword(char *, int);
int binsearch(char *, struct key *, int);
/*ͳ��������c���Թؼ��ֵĳ��ִ���*/
main(){
	int n;
	char word[MAXWORD];
	printf("%s %s %s", keytab[0].word, keytab[1].word, keytab[2].word);
	while (getword(word,MAXWORD) != EOF)/*��ΪEOF�����׵���*/
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",
				keytab[n].count, keytab[n].word);
	return 0;
} 
/*�۰����*/
/*2018��10��20��
lingr7*/
/* binsearch���� ����tab[0]��tab[n-1]�в��ҵ��� */
int binsearch(char *word, struct key tab[], int n){
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (high+low) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else 	/*�ҵ���ƥ���ֵ*/
			return mid; 
	}
	return -1;	/*û��ƥ���ֵ*/
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
