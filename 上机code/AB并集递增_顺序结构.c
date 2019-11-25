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
int ListInsert(SqList* L, int n);
int ListSelectSort(SqList* L);
int ListUnion(SqList* A, SqList* B);
int ListDelSam(SqList* L);
ElemType ListDelete(SqList* L, int i);

int main() {
	printf("请输入随机生成线性表A的长度：");
	int na;
	scanf_s("%d", &na);
	printf("\n请输入随机生成线性表B的长度：");
	int nb;
	scanf_s("%d", &nb);
	
	//构造空的线性表AB
	SqList* A = (SqList*)malloc(sizeof(SqList));
	A->elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	SqList* B = (SqList*)malloc(sizeof(SqList));
	B->elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if ((!A->elem)||(!B->elem)) {
		printf("\n空间不足，创建线性表失败\n");
		exit(0);
	}
	printf("\n创建线性表成功\n");
	A->length = 0;
	A->listsize = LIST_INT_SIZE;
	B->length = 0;
	B->listsize = LIST_INT_SIZE;

	//插入n个随机整数
	ListInsert(A, na);
	ListInsert(B, nb);

	//选择排序
	ListSelectSort(A);
	ListSelectSort(B);

	//打印排序后的线性表
	printf("\n线性表A是：\n");
	ListTraverse(A);
	printf("\n线性表B是：\n");
	ListTraverse(B);

	//求并集
	ListUnion(A, B);

	//删除相同值
	ListDelSam(A);

	//打印合并线性表C
	printf("\n线性表C是：\n");
	ListTraverse(A);

	//销毁线性表
	free(A);
	free(B);

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

int ListInsert(SqList* L, int n) {
	int i = 1;
	while (i <= n) {
		if (i<1 || i - 1 > L->length) {
			printf("i值不合法");
			exit(0);
		}
		if (L->length >= L->listsize) {
			ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTNCREMENT) * sizeof(ElemType));
			if (!newbase) {
				printf("\n内存分配失败\n");
				exit(0);
			}
			L->elem = newbase;
			L->listsize += LISTNCREMENT;
		}
		ElemType* q = &(L->elem[i - 1]);
		*q = rand() % RANDMAX;
		++L->length;
		i++;
	}

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
			if (L->elem[j] < p) {
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

int ListUnion(SqList* A, SqList* B) {
	int ia = A->length, ib = 0;
	while (A->length+B->length >= A->listsize) {
		ElemType* newbase = (ElemType*)realloc(A->elem, (A->listsize + LISTNCREMENT) * sizeof(ElemType));
		if (!newbase) {
			printf("\n内存分配失败\n");
			exit(0);
		}
		A->elem = newbase;
		A->listsize += LISTNCREMENT;
	}
	while (ib < B->length) {
		A->elem[ia] = B->elem[ib];
		ia++;
		ib++;
		A->length++;
	}
	ListSelectSort(A);

	return 0;
}

int ListDelSam(SqList* L) {
	int i = 0;
	while (i < L->length-1) {
		if (L->elem[i] == L->elem[i + 1]) {
			ListDelete(L, i);
		}
		else {
			i++;
		}
	}
	return 0;
}

ElemType ListDelete(SqList* L, int i) {
	if (i<1 || i  > L->length) {
		printf("i值不合法");
		exit(0);
	}
	ElemType* p = &(L->elem[i - 1]);
	ElemType e = *p;
	ElemType* q = &(L->elem[L->length - 1]);
	for (++p; p <= q; ++p) {
		*(p - 1) = *p;
	}
	--L->length;
	return e;
}
