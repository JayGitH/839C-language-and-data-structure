/*keytab.h*/
#define NKEYS ( sizeof keytab / sizeof(struct key))
/*�ṹ��ʼ��*/
/*�������Ϊ�ⲿ����*/
struct key {
	char *word;
	int count;
} keytab[] ={
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"main", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0,
};/*����*/
