#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode;

typedef struct LinkList {
	int length;
	struct LNode* head;
}LinkList;

int main() {
	int m, n;
	printf("人数m：");
	scanf_s("%d", &m);
	printf("\n\nn为：");
	scanf_s("%d", &n);

	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	if (!L) {
		printf("\n创建线性表失败\n");
		exit(0);
	}
	L->length = m;
	L->head = NULL;

	int i = m;
	LNode* new_p;
	for (i; i >= 1; i--) {
		new_p = (LNode*)malloc(sizeof(LNode));
		if (!new_p) {
			printf("\n创建线性表失败\n");
			exit(0);
		}
		new_p->next = L->head;
		new_p->data = i;
		L->head = new_p;
	}

	int num = 1;
	LNode* p = L->head;
	LNode* del;
	while (L->length) {
		printf("\n第%d个人报%d", p->data, num);
		i = p->data;
		if (num == n) {
			p = L->head;
			if (p->data == i) {
				del = L->head;
				L->head = p->next;
				free(del);
				printf("\n第%d个人出列\n\n", i);
				p = L->head;
				L->length--;
			}
			else {
				p = L->head;
				while (p->next->data != i) {
					p = p->next;
				}
				del = p->next;
				p->next = p->next->next;
				free(del);
				printf("\n第%d个人出列\n\n", i);
				L->length--;
				if (p->next == NULL) {
					p = L->head;
				}
				else {
					p = p->next;
				}
			}
		}
		else{
			if (p->next == NULL) {
				p = L->head;
			}
			else {
				p = p->next;
			}
		}
		num = num % n + 1;
	}
		
	free(L);
	return 0;
}