#include<stdio.h>

int main() {
	int n;
	int i=0;
	int a[999];
	scanf_s("%d", &n);
	int s = 0;
	while (i < n) {
		scanf_s("%d", &a[i]);
		i++;
	}
	for (i = 1; i < n - 1; i++) {
		if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) {
			s++;
		}
	}
	printf("%d", s);
	return 0;
}