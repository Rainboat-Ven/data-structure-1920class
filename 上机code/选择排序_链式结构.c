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
	printf("����������������Ա�ĳ��ȣ�");
	int n;
	scanf_s("%d", &n);

	//����յ����Ա�
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (!head) {
		printf("\n�������Ա�ʧ��\n");
		exit(0);
	}
	head->data = n;
	head->next = NULL;
	printf("\n�������Ա�ɹ�\n");

	//����n���������
	int i = 0;
	LNode* p = head;
	LNode* q = NULL;
	while (i < n) {
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

	//��ӡ����ǰ�����Ա�
	printf("\n����ǰ�����Ա���:\n");
	p = head->next;
	while (p) {
		printf("  %d  ", p->data);
		p = p->next;
	}

	//ѡ������
	ListSelectSort(head);

	//��ӡ���������Ա�
	printf("\n���������Ա���:\n");
	p = head->next;
	while (p) {
		printf("  %d  ", p->data);
		p = p->next;
	}

	//�������Ա�
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