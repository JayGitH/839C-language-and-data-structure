/*
	Name: �鲢�������û����� 
	Copyright: 
	Author: lingr7
	Date: 15/12/18 10:54
	Description: ���򲿷ֲ��룬ʹ�ò��������ѡ�����򶼿��ԣ�����ʹ�ò������� 
*/
void Merge(int *A,int n,int *B,int m){
	int i, j, k;
	for(k = 0; k < m; k++){/*��B�������A����������A����*/
		A[k+n] = B[k];
	}
	for(i = n; i < n+m; i++){/*������A �ڲ����в�������*/
		t = A[i];
		for(j = i; j >= 0 && t < A[j]; j--)
			A[j+1] = A[j];
		A[j+1] = t;
	} 
}
	
