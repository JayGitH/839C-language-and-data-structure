/**
**  @author:hushunfeng
**    
*/
#include<stdio.h>

int main() {

    int a[2][3] = {{1,2,3},{4,5,6}};

    int **p = a;
    
    printf("\n");
    printf("a[0][0]�ĵ�ַ:%x\n",&a[0][0]);
    printf("a[0][0]�ĵ�ַ:%x\n", *p);
    
    printf("p+1֮ǰ��%d\n",p);
    p++;
    printf("p+1֮��%d\n",p);

}
