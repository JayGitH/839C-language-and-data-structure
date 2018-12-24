/*�۰����*/
/*2018��10��20��
lingr7*/
/* binsearch���� ����v[0] <= v[1] <= v[2]<= ... <=v[n-1]�в���x */
int binsearch(int x, int v[], int n){
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (high+low) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else 	/*�ҵ���ƥ���ֵ*/
			return mid; 
	}
	return -1;	/*û��ƥ���ֵ*/
}
