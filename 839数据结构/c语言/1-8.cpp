#include <stdio.h>
main(){
	int c, n1, n2, n3;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	while((c = getchar()) != EOF){
		if(c == 32)//�ո� ' '
			n1++;
		else if(c == 9)//�Ʊ��'\t'
			n2++;
		else if(c == 10) //���з�'\n'
			n3++;	
	} 
	printf("%d %d %d\n", n1, n2, n3); 
}
