#include <stdio.h>
#include<stdlib.h>

#define RANDMAX 100

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode;

int ListSelectSort(LNode* head);

int main() {
	printf("请输入随机生成线性表的长度：");
	int n;
	scanf_s("%d", &n);

	//构造空的线性表
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (!head) {
		printf("\n创建线性表失败\n");
		exit(0);
	}
	head->data = n;
	head->next = NULL;
	printf("\n创建线性表成功\n");

	//插入n个随机整数
	int i = 0;
	LNode* p = head;
	LNode* q = NULL;
	while (i < n) {
		q = (LNode*)malloc(sizeof(LNode));
		if (!q) {
			printf("\n创建线性表失败\n");
			exit(0);
		}
		q->next = NULL;
		q->data = rand() % RANDMAX;
		p->next = q;
		p = p->next;
		i++;
	}

	//打印排序前的线性表
	printf("\n排序前的线性表是:\n");
	p = head->next;
	while (p) {
		printf("  %d  ", p->data);
		p = p->next;
	}

	//选择排序
	ListSelectSort(head);

	//打印排序后的线性表
	printf("\n排序后的线性表是:\n");
	p = head->next;
	while (p) {
		printf("  %d  ", p->data);
		p = p->next;
	}

	//销毁线性表
	p = head;
	q = p;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}

	return 0;
}

int ListSelectSort(LNode* head) {
	LNode* p = head->next;
	LNode* q = p;
	LNode* max;
	ElemType e;
	while (p) {
		q = p;
		max = q;
		e = q->data;
		while (q) {
			if (q->data > e) {
				max = q;
				e = q->data;
			}
			q = q->next;
		}
		e = max->data;
		max->data = p->data;
		p->data = e;
		p = p->next;
	}

	return 0;
}