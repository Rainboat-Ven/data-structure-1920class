#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int flag[10000] = {0};
	int i;
	int num;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &num);
		flag[num] = 1;
	}
	num = 0;
	for (i = 0; i < 10000; i++) {
		if (flag[i] && flag[i + 1]) {
			num++;
		}
	}
	printf("%d", num);
	return 0;
}