#include<stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int num[1000] = {0};
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &j);
		num[j]++;
	}
	j = 0;
	for (i = 0; i <= 1000; i++) {
		if (j == n - j - num[i]) {
			printf("%d", i);
			return 0;
		}
		j = j + num[i];
	}
	printf("%d", -1);
	return 0;
}