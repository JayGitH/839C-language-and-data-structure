/*
	Name: �ļ���д 
	Copyright: 
	Author: malic�� 
	Date: 15/12/18 21:45
	Description: ��Ŀ��֪��
	����Ʒ��������ͬƷ������Ʒ�����ڣ�
	��������Ҫ��hash�� 
	ÿ����һ�о�����һ�е���Ʒ����ȣ�
	���һ�����ۼ����룬
	��һ����Ͱ���һ����Ʒ������ļ����ٿ�ʼ����һ����Ʒ�����ۼơ�
�����ж�����brand[2][82]���ڱ�����Ʒ����
Ҳ������brand[0]��brand[1]����char���飬
��ǰ��Ʒ�����±�Ϊkʱ��
��һ����Ʒ��Ϊ1-k��
����ʡȥ�����Ķ��ַ����ĸ��Ʋ����Ŀ�����
����������ն�������Ʒ���͵�ǰ��������Ʒ��һ�£�
��ӵ��ۼӣ�����һ���������ǰ����Ʒ��brand[k]��
���ѵ�ǰ��������Ʒ������Ϊk=1-k��
�����ļ���EOF������
��ǰ�������ļ��϶����������������ѭ������Ҫ���������һ�β�������Ʒ��Ϣ������ļ����С�

�������ж�ȡ��˼·�ܰ�����Լ��Դ������oj��Ŀ�Ĳ����ֶΣ�ֻ�����ɱ�׼�������������Ϊ�ļ���д��*/


#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    FILE *fin,*fout;
    char brand[2][82];
    double sum,price;
    int k=0;

    fin=fopen(argv[1],"r");
    fout=fopen(argv[2],"w");

    fscanf(fin,"%s%lf",brand[k],&price);
    sum=price;
    
    while(fscanf(fin,"%s%lf",brand[1-k],&price)!=EOF)
    {
        if(strcmp(brand[0],brand[1])==0)
        {
            sum+=price;
        }
        else
        {
            
            fprintf(fout,"%s %.2f\n",brand[k],sum);
            sum=price;
            k=1-k;
        }
    }
    fprintf(fout,"%s %.2f\n",brand[k],sum);
    fclose(fin);
    fclose(fout);
    return 0;
}
