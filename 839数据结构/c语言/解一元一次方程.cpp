#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float print(int arr[],int n){
    int i=0;
    float sum = 0;
    for(i=0;i<n;i++){
       printf("%d ",arr[i]);
        sum += arr[i];
    }
    printf("\n");
    return sum;
}
// ������ʽ 100a+10=4a-2+123-22a char express[] = "100a+10=4a-2+123-22a";
// ˼·����ÿ������ȫ����ȡ����100a 10 -4a 2 -123 22a
// Ȼ�󽫴����ַ���һ��������
// ������������һ��������
double equation(char express[]){/*�Է��̽��д���*/
    int rightOrleft = 1;/*�����ʽ���ұ��*/
    int next = 1;
    int i=0,m=0,n=0;
    char c = express[i];
    int var[10]; // ��ȡϵ��
    int para[10]; // ���ʵ��
    int top = 0;
    char temp[10];
    if(express[0]=='-'){/*ֻ�в���λ�ÿ��ܻ���ִ����ŵ�-��������һ��*/
        next = -1;
        c = express[++i];
    }
    
    while (c!='\0') {
        if( (c<='9' && c>='0') || (c<='z' && c>='a')){
            //�����ڼ���ı������ߴ����ֻ�������
            temp[top++] = c;
            temp[top] = '\0';//���ں�����ַ���ת����
        } else {
            // ����Ӽ�����
            top--; //��ȥĩβ��'\0'
            if(temp[top]<='z' && temp[top]>='a'){
                //���������Ǳ��� 1a 3a 100a -1a ĩβ�ض�����ĸ
                var[m++] = rightOrleft*next*(temp[0]>='a'?1:atoi(temp));/*����ϵ����ڣ���ϵ��Ϊ1*/
            } else {
                //���������Ǵ�����
                para[n++] = rightOrleft*next*(atoi(temp));
            }
            // ����һ�������������ж�
            if(c=='-'){
                next = -1;
            } else if(c == '+'){
                next = 1;
            }
            // ��������
            top = 0;/*��մ˴���¼������������ĸ*/
        }
        if(c=='='){
            rightOrleft = -1;
        }
        c = express[++i];/*����c*/
    }
    top--;// ��ȥ���һ��'\0'
    // �������һ���������߱���
    if(temp[top]<='z' && temp[top]>='a')
        var[m++] = rightOrleft*next*(atoi(temp));
    else
        para[n++] = rightOrleft*next*(atoi(temp));
    return -print(para, n)/print(var, m);
}

int main()
{
    char express[] = "-5a+10=4a-2+123-22a+22";
	/*����������һ�����Ե��͵�һԪһ�η��̣�ͬʱ���ٵĿռ��СҲ�ɷ��̾���*/
    printf("%s\na = %.5f\n",express,equation(express));
}
