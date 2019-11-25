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
	printf("����m��");
	scanf_s("%d", &m);
	printf("\n\nnΪ��");
	scanf_s("%d", &n);

	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	if (!L) {
		printf("\n�������Ա�ʧ��\n");
		exit(0);
	}
	L->length = m;
	L->head = NULL;

	int i = m;
	LNode* new_p;
	for (i; i >= 1; i--) {
		new_p = (LNode*)malloc(sizeof(LNode));
		if (!new_p) {
			printf("\n�������Ա�ʧ��\n");
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
		printf("\n��%d���˱�%d", p->data, num);
		i = p->data;
		if (num == n) {
			p = L->head;
			if (p->data == i) {
				del = L->head;
				L->head = p->next;
				free(del);
				printf("\n��%d���˳���\n\n", i);
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
				printf("\n��%d���˳���\n\n", i);
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