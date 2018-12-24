/*
	Name: ͳ�ƹؼ��ֳ��ִ�����ʹ��ָ��ʵ�ֵİ汾 
	Copyright: 
	Author: ligr7
	Date: 04/11/18 17:29
	Description: 
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

int getword(char *, int);
struct key *binsearch(char *, struct key *,int);

/* ͳ�ƹؼ��ֳ��ֵĴ���������ָ�뷽ʽʵ�ֵİ汾 */
main(){
	char word[MAXWORD];
	struct key *p;
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])
			if (isalpha(word[0])) 
				if ((p=binsearch(word, keytab, NKEYS)) != NULL)
					p->count++;
	for (p = keytab; p < keytab + NKEYS; p++){
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
} 
/* binsearch��������tab[0]...tab[n-1]�в�������뵥��ƥ���Ԫ�� */
struct key *binsearch(char *word, struct key *tab, int n){
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;
	
	while (low < high) {
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return NULL;
} 
