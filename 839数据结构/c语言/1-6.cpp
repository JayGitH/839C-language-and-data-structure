#include <stdio.h>
/* copy input to output; 1st version */
main()
{
	int c;
	//c = getchar();
	int i = 0;
	while (c = (getchar() != EOF) )
		printf("%d %d\n", c, i++); 
	printf("%d - at EOF\n", c);
}
/*��while�ж��c = ��0ֵ������������������ѭ������c��ֵΪ0����Ϊ�٣��˳�ѭ��*/
