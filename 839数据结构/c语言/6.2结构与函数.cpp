/*2018��10��10��(������)
lingr7
2018��10��20��21:05:25
2018��10��20�� ������*/
middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
				   (screen.pt1.y + screen.pt2.y)/2);
/* addpoint�����������������*/
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}
/*�ṹ���͵Ĳ���Ҳ��ͨ��ֵ���ݵ�*/
/* ptinrect�����������p�ھ���r�ڣ��򷵻�1�����򷵻�0*/
int ptinrect(struct point p, struct rect r){
	return p.x >=r.pt1.x && p.x < r.pt2.x
	    && p.y >=r.pt1.y && p.y < r.pt2.y; 
}
/*����һ���淶��ʽ�ľ��εĺ���*/
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b)) 
/*��׼��ʽ������pt1����С��pt2����*/
/*canonrect����������������淶��*/
struct rect canonrect(struct rect r){
	struct rect temp;
	
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r,pt2.y);
	return temp;
} 
/*���ݸ������Ľṹ�ܴ�ʹ��ָ�뷽ʽ��Ч��ͨ���ȸ��������ṹ��Ч��Ҫ��*/
struct point *pp;
/*ppΪһָ��struct point���Ͷ����ָ�롣*/
struct point origin, *pp;

pp = &origin;
printf("origin is (%d,%d)\n", (*pp).x, (*pp).y); /*.�����ȼ�Ҫ����**/
/*�ṹָ��ʹ��Ƶ�ʺܸߣ�Ϊ��ʹ�÷��㣬c�����ṩ����һ�ּ�д��ʽ���ٶ�pp��һ��ָ��ṹ��ָ��*/
/*p->�ṹ��Ա*/
printf("origin is (%d,%d)\n", pp->x, pp->y);
/*  
*p->str ��ȡָ��str��ָ��Ķ����ֵ��
*p->str++ �ȶ�ȡָ��strָ��Ķ����ֵ��Ȼ���ٽ�str+1;
(*p->str)++
*p++->str�ȶ�ȡָ��strָ���ֵ��Ȼ���ٽ�p��1 
*/
char *keyword[NKEYS];
int keycount[NKEYS];

/*�ṹ����ʵ�ַ�ʽ*/
struct key {
	char *word;
	int count;
}keytab[NKEYS]; 

struct key {
	char *word;
	int count;
}; 
struct key keytab[NKEYS];

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
	/* ... */
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0 
} ;/*����*/
/*���и���ȷ����������ÿһ�У���ÿ���ṹ�ĳ�ֵ�������ڻ�������*/
	{"auto", 0},
	{"break", 0},
	{"case", 0},
