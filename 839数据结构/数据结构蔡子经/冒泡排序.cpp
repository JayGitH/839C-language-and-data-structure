void bubble_sort(int a[], int n){
	int i , j;
	int t;
	n--;
	while(n > 0){
		j = 0;
		for(i = 0; i < n; i++){/*һ��ð��*/
			if(a[i] > a[i+1]){
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
				j = i;
			}
		}/*j����a[0],a[1]...��a[j]��û��ȷ������j+1����������Ѿ���������*/
		n = j;
	}
}
