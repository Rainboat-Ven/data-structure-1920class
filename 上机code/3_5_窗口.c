#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int n;
	int x1;
	int x2;
	int y1;
	int y2;
	struct LNode* next;
}LNode;

int main() {
	int n, m;
	scanf_s("%d%d", &n, &m);
	int i = 0;
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	LNode* p = NULL;
	for (i = 0; i < n; i++) {
		p = (LNode*)malloc(sizeof(LNode));
		p->next = head->next;
		p->n = i + 1;
		scanf_s("%d%d%d%d", &p->x1, &p->y1, &p->x2, &p->y2);
		head->next = p;
	}
	int x[10] = { 0 };
	int y[10] = { 0 };
	int f = 0;
	LNode* q;
	for (i = 0; i < m; i++) {
		scanf_s("%d%d", &x[i], &y[i]);
	}
	for (i = 0; i < m; i++) {
		p = head;
		f = 0;
		while (p->next != NULL && f == 0) {
			if (x[i] >= p->next->x1 && x[i] <= p->next->x2 && y[i] <= p->next->y2 && y[i] >= p->next->y1) {
				printf("%d\n", p->next->n);
				q = p->next;
				p->next = p->next->next;
				q->next = head->next;
				head->next = q;
				f = 1;
			}
			else {
				p = p->next;
			}
		}
		if (f == 0) {
			printf("IGNORED\n");
		}
	}
	while (head) {
		p = head;
		head = head->next;
		free(p);
	}
	return 0;
}