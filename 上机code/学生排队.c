#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int i;
	struct LNode* next;
	struct LNode* prior;
}LNode;

int main() {
	int n;
	scanf_s("%d", &n);
	int m;
	scanf_s("%d", &m);

	LNode* head = (LNode*)malloc(sizeof(LNode));
	LNode* end = (LNode*)malloc(sizeof(LNode));
	head->next = end;
	head->prior = NULL;
	end->next = NULL;
	end->prior = head;
	head->i = 0;
	end->i = 0;

	LNode* pn=head;//从前往后
	LNode* pp=end;//从后往前
	LNode* new_p;
	while (n) {
		new_p = (LNode*)malloc(sizeof(LNode));
		new_p->next = head->next;
		new_p->prior = head;
		new_p->i = n;
		head->next->prior = new_p;
		head->next = new_p;
		n--;
	}
	
	int p, q;
	while (m) {
		scanf_s("%d%d", &p, &q);
		while (p != pn->i) {
			pn = pn->next;
		}
		pp = pn;
		if (q > 0) {
			while (q) {
				pp = pp->next;
				q--;
			}
		}
		else {
			while(q!=0){
				pp = pp->prior;
				q++;
			}
			pp = pp->prior;
		}
		pn->next->prior = pn->prior;
		pn->prior->next = pn->next;
		pn->next = pp->next;
		pn->prior = pp;
		pp->next->prior = pn;
		pp->next = pn;
		pn = head;
		pp = end;
		m--;
	}
	
	pn = head->next;
	while (pn->next) {
		printf("%d ", pn->i);
		pn = pn->next;
	}

	pn = head;
	LNode* del;
	while (pn->next) {
		del = pn;
		pn = pn->next;
		free(del);
	}
	return 0;
}