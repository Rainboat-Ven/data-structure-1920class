#include<stdio.h>

#define IMAX 100
#define JMAX 100
#define RANDMAX 100

int main() {
	int m, n;
	printf("\n�������������������\n");
	scanf_s("%d%d", &m, &n);
	int T[IMAX][JMAX] = { 0 };
	int TF[IMAX][JMAX] = { 0 };
	int i, j;
	printf("\n��������Ԫ�أ�\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf_s("%d", &(T[i][j]));
		}
	}
	//��ӡ����
	printf("\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("  %d ", T[i][j]);
		}
		printf("\n");
	}
	//�жϰ���
	int x, y;
	int min, max;
	for (i = 0; i < m; i++) {
		//��һ�е���Сֵ
		min = T[i][0];
		for (j = 0; j < n; j++) {
			if (T[i][j] < min) {
				min = T[i][j];
			}
		}
		//��ÿ����Сֵ�ı�Ǽ�һ
		for (j = 0; j < n; j++) {
			if (T[i][j] == min) {
				TF[i][j]++;
			}
		}
	}
	for (j = 0; j < n; j++) {
		//��һ�е����ֵ
		max = T[0][j];
		for (i = 0; i < m; i++) {
			if (T[i][j] >max) {
				max = T[i][j];
			}
		}
		//��ÿ�����ֵ�ı�Ǽ�һ
		for (i = 0; i < m; i++) {
			if (T[i][j] == max) {
				TF[i][j]++;
			}
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (TF[i][j] == 2) {
				printf("\n��%d�е�%d���ǰ��㣬ֵ��%d", i+1, j+1, T[i][j]);
			}
		}
	}
	return 0;
}