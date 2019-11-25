#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int k;
	int t;
	struct LNode* next;
}LNode;

int main() {
	int r, y, g;
	scanf_s("%d%d%d", &r, &y, &g);
	int n;
	scanf_s("%d", &n);
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->k = 0;
	head->t = 0;
	head->next = NULL;
	LNode* L = head;
	LNode* p;
	while (n>0) {
		p = (LNode*)malloc(sizeof(LNode));
		scanf_s("%d%d", &(p->k), &(p->t));
		p->next = L->next;
		L->next = p;
		L = p;
		n--;
	}

	int time = 0;
	p = head->next;
	while (p) {
		switch (p->k) {
		case 0:
			time = time + p->t;
			break;
		case 1:
			time = time + p->t;
			break;
		case 2:
			time = time + p->t + r;
			break;
		case 3:
			break;
		}
		p = p->next;
	}
	printf("%d", time);

	p = head;
	while (p) {
		L = p;
		p = p->next;
		free(L);
	}
	return 0;
}
