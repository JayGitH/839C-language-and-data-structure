char* ui2hex(unsigned n, char *s)
{
        int i=0,tmp,N;
        while(n>0)
        {
                tmp = n%16;
                if(tmp<10)
                        s[i]=tmp+'0';/*����Ľ�����תΪ�����ַ�*/
                else
                        s[i]=tmp-10+'A';/*����Ľ�����תΪ��ĸ�ַ�*/
                n/=16;
                i++;/*��������Ԫ�ظ���*/
        }
        s[i]=0;
        N=i;/*����Ԫ�ظ���*/
        /*�ߵ�����*/
        for(i=0;i<N/2;i++)
        {
                tmp = s[i];
                s[i] = s[N-i-1];
                s[N-i-1] = tmp;
        }
        return s;
}
