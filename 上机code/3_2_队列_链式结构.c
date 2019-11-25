#include <stdio.h>
#include<stdlib.h>

typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode;

typedef struct {
	QNode* front;
	QNode* rear;
}LinkQueue;

void InitQueue(LinkQueue* Q);
void DestoryQueue(LinkQueue* Q);
void ClearQueue(LinkQueue* Q);
int QueueEmpty(LinkQueue* Q);
int QueueLength(LinkQueue* Q);
QElemType GetHead(LinkQueue* Q);
void EnQueue(LinkQueue* Q, QElemType e);
QElemType DeQueue(LinkQueue* Q);
void QueueTraverse(LinkQueue* Q);
void visit(QNode* p);

int main() {
	int loop = 1;
	int choice;
	LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	int i;
	QElemType e;
	while (loop) {
		printf("\n=================================================================================================\n");
		printf("1������һ���յĶ���Q\n");
		printf("2�����ٶ���Q\n");
		printf("3����Q��Ϊ�ն���\n");
		printf("4����QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE\n");
		printf("5������Q��Ԫ�صĸ����������еĳ���\n");
		printf("6�������в��գ�����e����Q�Ķ�ͷԪ��\n");
		printf("7������Ԫ��eΪ�µĶ�βԪ��\n");
		printf("8����ջ���в��գ�ɾ��Q�Ķ�ͷԪ�أ�����e������ֵ\n");
		printf("9�����ζ�Q��ÿ��Ԫ�ص��ú���visit()\n");
		printf("\n��Ҫ���еĲ����ǣ�");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			InitQueue(Q);
			break;
		case 2:
			DestoryQueue(Q);
			break;
		case 3:
			ClearQueue(Q);
			break;
		case 4:
			QueueEmpty(Q);
			break;
		case 5:
			QueueLength(Q);
			break;
		case 6:
			GetHead(Q);
			break;
		case 7:
			printf("\n��Ҫ�����Ԫ���ǣ�\n");
			scanf_s("%d", &e);
			EnQueue(Q, e);
			break;
		case 8:
			DeQueue(Q);
			break;
		case 9:
			QueueTraverse(Q);
			break;
		default:
			printf("\n�ò���������\n\n");
			break;
		}
	}

	return 0;
}

void InitQueue(LinkQueue* Q) {
	Q->front = (QNode*)malloc(sizeof(QNode));
	if (!Q->front) {
		printf("\n����ռ�ʧ��\n");
		exit(0);
	}
	Q->front->next = NULL;
	Q->front->data = 0;
	Q->rear = Q->front;
}

void DestoryQueue(LinkQueue* Q) {
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->rear);
		Q->front = Q->rear;
	}
}

void ClearQueue(LinkQueue* Q) {
	QNode* p=Q->front->next;
	QNode* del = NULL;
	while (p) {
		del = p;
		p = p->next;
		free(del);
	}
	Q->rear = Q->front;
}

int QueueEmpty(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		printf("\nTRUE\n");
		return 1;
	}
	else {
		printf("\nFALSE\n");
		return 0;
	}
}

int QueueLength(LinkQueue* Q) {
	int len = 0;
	QNode* p = Q->front;
	while (p != Q->rear) {
		len++;
		p = p->next;
	}
	printf("\n���еĳ����ǣ�%d\n", len);
	return len;
}

QElemType GetHead(LinkQueue* Q) {
	QNode* p = Q->front->next;
	if (Q->front == Q->rear) {
		printf("\nERROR\n");
		return 0;
	}
	else {
		printf("\n��ͷԪ���ǣ�%d\n",p->data);
		printf("\nOK\n");
		return p->data;
	}
}

void EnQueue(LinkQueue* Q, QElemType e) {
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p) {
		printf("\n����ռ�ʧ��\n");
		exit(0);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

QElemType DeQueue(LinkQueue* Q) {
	if (Q->front == Q->rear) {
		printf("\nERROR\n");
		return 0;
	}
	else {
		QNode* p = Q->front->next;
		QElemType e;
		printf("\nɾ���Ķ�ͷԪ���ǣ�%d\n", p->data);
		printf("\nOK\n");
		QNode* del=p;
		e = p->data;
		Q->front->next = p->next;
		free(del);
		return e;
	}
}

void QueueTraverse(LinkQueue* Q) {
	QNode* p = Q->front->next;
	while (p) {
		visit(p);
		p = p->next;
	}
}

void visit(QNode* p) {
	printf("\n%d", p->data);
}