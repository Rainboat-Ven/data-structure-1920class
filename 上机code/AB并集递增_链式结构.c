#include <stdio.h>
#include<stdlib.h>

#define RANDMAX 100

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode;

int ListSelectSort(LNode* head);
int ListInsert(LNode* head);
int ListPrintf(LNode* head);
int ListDel(LNode* head);
int ListUnion(LNode* headA, LNode* headB);
int ListDelSam(LNode* head);

int main() {
	printf("����������������Ա�A�ĳ��ȣ�");
	int na;
	scanf_s("%d", &na);
	printf("\n����������������Ա�B�ĳ��ȣ�");
	int nb;
	scanf_s("%d", &nb);

	//����յ����Ա�
	LNode* headA = (LNode*)malloc(sizeof(LNode));
	LNode* headB = (LNode*)malloc(sizeof(LNode));
	if (!headA||!headB) {
		printf("\n�������Ա�ʧ��\n");
		exit(0);
	}
	headA->data = na;
	headA->next = NULL;
	headB->data = nb;
	headB->next = NULL;
	printf("\n�������Ա�ɹ�\n");

	//����n���������
	ListInsert(headA);
	ListInsert(headB);

	//ѡ������
	ListSelectSort(headA);
	ListSelectSort(headB);

	//��ӡ���������Ա�
	printf("\n���Ա�A��:\n");
	ListPrintf(headA);
	printf("\n���Ա�B��:\n");
	ListPrintf(headB);

	//�󲢼�
	ListUnion(headA, headB);

	//ɾ����ֵͬ
	ListDelSam(headA);

	//��ӡ���겢�������Ա�
	printf("\n���Ա�C��:\n");
	ListPrintf(headA);

	//�������Ա�
	ListDel(headA);
	ListDel(headB);

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
			if (q->data < e) {
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

int ListInsert(LNode* head) {
	int i = 0;
	LNode* p = head;
	LNode* q = NULL;
	while (i < head->data) {
		q = (LNode*)malloc(sizeof(LNode));
		if (!q) {
			printf("\n�������Ա�ʧ��\n");
			exit(0);
		}
		q->next = NULL;
		q->data = rand() % RANDMAX;
		p->next = q;
		p = p->next;
		i++;
	}
	return 0;
}

int ListPrintf(LNode* head) {
	LNode*p = head->next;
	while (p) {
		printf("  %d  ", p->data);
		p = p->next;
	}
	return 0;
}

int ListDel(LNode* head) {
	LNode*p = head;
	LNode*q = p;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	return 0;
}

int ListUnion(LNode* headA, LNode* headB) {
	LNode* pA = headA;
	LNode* pB = headB->next;
	LNode* p = NULL;
	while (pB) {
		if ((pA->next == NULL&&pB->data>pA->data)||(pA->next!=NULL&& pB->data < pA->next->data)) {
			p = pB;
			pB = pB->next;
			p->next = pA->next;
			pA->next = p;
			headA->data++;
			headB->data--;
		}//������������
		else {
			pA = pA->next;
		}
	}
	headB->next = NULL;
	ListSelectSort(headA);
	return 0;
}

int ListDelSam(LNode* head) {
	LNode* p = head->next;
	LNode* del = NULL;
	if (p) {
		while (p->next) {
			if (p->data == p->next->data) {
				del = p->next;
				p->next = p->next->next;
				free(del);
			}
			else {
				p = p->next;
			}
		}
	}
	return 0;
}