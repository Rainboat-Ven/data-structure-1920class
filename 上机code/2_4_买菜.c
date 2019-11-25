#include<stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int* t1 = (int*)malloc(1000000 *sizeof(int) );
	int* t2 = (int*)malloc(1000000 * sizeof(int));
	
	int i,j;
	int time1, time2;
	int s=0;
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &time1,&time2);
		for (j = time1; j < time2; j++) {
			t1[j] = 1;
		}
	}for (i = 0; i < n; i++) {
		scanf_s("%d%d", &time1, &time2);
		for (j = time1; j < time2; j++) {
			t2[j] = 1;
		}
	}
	for (i = 0; i < 1000000; i++) {
		if (t1[i]==1&&t2[i]==1) {
			s++;
		}
	}

	free(t1);
	free(t2);
	printf("%d", s);

	return 0;
}




