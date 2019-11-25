#include <stdio.h>
#include<stdlib.h>

#define LIST_INT_SIZE 100
#define LISTNCREMENT 10
#define RANDMAX 100

typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

int ListTraverse(SqList* L);
int ListSelectSort(SqList* L);

int main() {
	printf("����������������Ա�ĳ��ȣ�");
	int n;
	scanf_s("%d", &n);

	//����յ����Ա�
	SqList* L = (SqList*)malloc(sizeof(SqList));
	L->elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L->elem) {
		printf("\n�ռ䲻�㣬�������Ա�ʧ��\n");
		exit(0);
	}
	printf("\n�������Ա�ɹ�\n");
	L->length = 0;
	L->listsize = LIST_INT_SIZE;

	//����n���������
	int i = 1;
	while (i <= n) {
		if (i<1 || i - 1 > L->length) {
			printf("iֵ���Ϸ�");
			exit(0);
		}
		if (L->length > L->listsize) {
			ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTNCREMENT) * sizeof(ElemType));
			if (!newbase) {
				printf("\n�ڴ����ʧ��\n");
				exit(0);
			}
			L->elem = newbase;
			L->listsize += LISTNCREMENT;
		}
		ElemType* q = &(L->elem[i - 1]);
		*q = rand()%RANDMAX;
		++L->length;
		i++;
	}

	//��ӡ����ǰ�����Ա�
	printf("\n������ɵ����Ա��ǣ�\n");
	ListTraverse(L);

	//ѡ������
	ListSelectSort(L);

	//��ӡ���������Ա�
	printf("\n���������Ա��ǣ�\n");
	ListTraverse(L);

	//�������Ա�
	free(L);

	return 0;
}

int ListTraverse(SqList* L) {
	int i;
	for (i = 0; i <= L->length - 1; i++) {
		printf("  %d  ", L->elem[i]);
	}
	printf("\n");
	return 0;
}

int ListSelectSort(SqList* L) {
	int i = 0, j = 0;
	int max = 0;
	int p;
	for (i = 0; i < L->length; i++) {
		max = i;
		p = L->elem[i];
		for (j = i; j < L->length; j++) {
			if (L->elem[j] > p) {
				max = j;
				p = L->elem[j];
			}
		}
		p = L->elem[i];
		L->elem[i] = L->elem[max];
		L->elem[max] = p;
	}
	return 0;
}