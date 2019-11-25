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
	printf("请输入随机生成线性表的长度：");
	int n;
	scanf_s("%d", &n);

	//构造空的线性表
	SqList* L = (SqList*)malloc(sizeof(SqList));
	L->elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L->elem) {
		printf("\n空间不足，创建线性表失败\n");
		exit(0);
	}
	printf("\n创建线性表成功\n");
	L->length = 0;
	L->listsize = LIST_INT_SIZE;

	//插入n个随机整数
	int i = 1;
	while (i <= n) {
		if (i<1 || i - 1 > L->length) {
			printf("i值不合法");
			exit(0);
		}
		if (L->length > L->listsize) {
			ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTNCREMENT) * sizeof(ElemType));
			if (!newbase) {
				printf("\n内存分配失败\n");
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

	//打印排序前的线性表
	printf("\n随机生成的线性表是：\n");
	ListTraverse(L);

	//选择排序
	ListSelectSort(L);

	//打印排序后的线性表
	printf("\n排序后的线性表是：\n");
	ListTraverse(L);

	//销毁线性表
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