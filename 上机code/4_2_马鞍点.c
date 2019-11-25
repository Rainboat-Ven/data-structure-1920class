#include<stdio.h>

#define IMAX 100
#define JMAX 100
#define RANDMAX 100

int main() {
	int m, n;
	printf("\n输入矩阵行数和列数：\n");
	scanf_s("%d%d", &m, &n);
	int T[IMAX][JMAX] = { 0 };
	int TF[IMAX][JMAX] = { 0 };
	int i, j;
	printf("\n依次输入元素：\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf_s("%d", &(T[i][j]));
		}
	}
	//打印矩阵
	printf("\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("  %d ", T[i][j]);
		}
		printf("\n");
	}
	//判断鞍点
	int x, y;
	int min, max;
	for (i = 0; i < m; i++) {
		//找一行的最小值
		min = T[i][0];
		for (j = 0; j < n; j++) {
			if (T[i][j] < min) {
				min = T[i][j];
			}
		}
		//给每行最小值的标记加一
		for (j = 0; j < n; j++) {
			if (T[i][j] == min) {
				TF[i][j]++;
			}
		}
	}
	for (j = 0; j < n; j++) {
		//找一列的最大值
		max = T[0][j];
		for (i = 0; i < m; i++) {
			if (T[i][j] >max) {
				max = T[i][j];
			}
		}
		//给每列最大值的标记加一
		for (i = 0; i < m; i++) {
			if (T[i][j] == max) {
				TF[i][j]++;
			}
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (TF[i][j] == 2) {
				printf("\n第%d行第%d列是鞍点，值是%d", i+1, j+1, T[i][j]);
			}
		}
	}
	return 0;
}