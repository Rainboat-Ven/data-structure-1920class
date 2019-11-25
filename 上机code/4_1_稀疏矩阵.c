#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 12500

typedef int ElemType;
typedef struct {
	int i, j;
	ElemType e;
}Triple;
typedef struct {
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;

//��ӡϡ�����
void PrintSMaxtrix(TSMatrix* T) {
	printf(" \n�к�  �к�  Ԫ��ֵ\n");
	for (int i = 0; i < T->tu; i++) {
		printf(" %d     %d     %d \n", T->data[i].i, T->data[i].j, T->data[i].e);
	}
}
//ϵ�������ת��
void FastTransposeSMaxtrix(TSMatrix* T, TSMatrix* M) {
	M->mu = T->nu;
	M->nu = T->mu;
	M->tu = T->tu;
	int num[MAXSIZE] = { 0 };
	int cpot[MAXSIZE] = { 0 };
	if (M->tu) {
		for (int col = 0; col < T->nu; col++) {
			num[col] = 0;
		}
		for (int t = 0; t < T->tu; t++) {
			num[T->data[t].j]++;
		}
		cpot[0] = 0;
		for (int col = 1; col < T->nu; col++) {
			cpot[col] = cpot[col - 1] + num[col - 1];
		}
		int col, q;
		for (int p = 0; p < T->tu; p++) {
			col = T->data[p].j;
			q = cpot[col];
			M->data[q].i = T->data[p].j;
			M->data[q].j = T->data[p].i;
			M->data[q].e = T->data[p].e;
			cpot[col]++;
		}
	}
}

int main() {
	TSMatrix* T = (TSMatrix*)malloc(sizeof(TSMatrix));
	printf("\n����ϡ�����������");
	scanf_s("%d", &T->mu);
	printf("\n����ϡ�����������");
	scanf_s("%d", &T->nu);
	printf("\n����ϡ�����Ԫ�ظ�����");
	scanf_s("%d", &T->tu);
	printf("\n��˳����������Ԫ�أ�\n");
	for (int n = 0; n < T->tu; n++) {
		scanf_s("%d%d%d", &(T->data[n].i), &(T->data[n].j), &(T->data[n].e));
		if (T->data[n].i > T->mu || T->data[n].j > T->nu) {
			printf("\n����������Ϸ�\n");
			exit(0);
		}
	}
	PrintSMaxtrix(T);
	TSMatrix* M= (TSMatrix*)malloc(sizeof(TSMatrix));
	FastTransposeSMaxtrix(T, M);
	PrintSMaxtrix(M);
	free(M);
	free(T);
	return 0;
}