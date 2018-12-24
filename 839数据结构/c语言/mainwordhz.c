#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup(char *);
struct tnode {			/*���Ľڵ�*/
	char *word;			/*ָ�򵥴ʵ�ָ��*/
	int count;			/*���ʳ��ֵĴ���*/
	struct tnode *left;	/*���ӽڵ�*/
	struct tnode *right;/*���ӽڵ�*/
};

/* ����Ƶ�ʵ�ͳ�� */
int main(int argc, char *argv[]) {
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) 
			root = addtree(root, word);/*�ݹ��*/
	treeprint(root); 
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


/* addtree����:��p��λ�û�p���·�����һ��w���*/
struct tnode *addtree(struct tnode *p, char *w){
	int cond;
	
	if (p == NULL){   /* �õ�����һ���µ��� */
		p = talloc(); /* ����һ���½ڵ� */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL; 
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;		/*�µ�����ڵ��еĵ���ƥ�� */
	else if(cond < 0)	/*���С�ڸýڵ��еĵ��ʣ������������ */ 
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;	
}
/* treeprint����:�����ӡ��p*/
void treeprint(struct tnode *p){
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* talloc��������һ��tnode*/
struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}
/* ����s��ĳ��λ��*/
char *strdup(char *s){
	char *p;
	
	p = (char *) malloc(strlen(s)+1);/* ִ�м�1������Ϊ���ڽ�β�����ַ� \0*/ 
	if (p != NULL)
		strcpy(p, s);
	return p;
}
