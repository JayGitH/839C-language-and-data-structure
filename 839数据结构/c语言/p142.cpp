#include <stdio.h>
/*cat���������Ӷ���ļ����汾1*/
int main(){
	FILE *fp;/*ָ��ṹFILE��ָ��*/
	void filecopy(FILE *, FILE *);
	
	if(argv == 1) /*���û�������в��������Ʊ�׼����*/
		filecopy(stdin, stdout);
	else 
		while(--argc > 0)
			if((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1; 
			}else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}
