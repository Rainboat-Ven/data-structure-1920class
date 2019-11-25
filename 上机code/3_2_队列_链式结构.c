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
		printf("1：构造一个空的队列Q\n");
		printf("2：销毁队列Q\n");
		printf("3：将Q置为空队列\n");
		printf("4：若Q为空队列，则返回TRUE，否则返回FALSE\n");
		printf("5：返回Q中元素的个数，即队列的长度\n");
		printf("6：若队列不空，则用e返回Q的队头元素\n");
		printf("7：插入元素e为新的队尾元素\n");
		printf("8：若栈队列不空，删除Q的对头元素，并用e返回其值\n");
		printf("9：依次对Q的每个元素调用函数visit()\n");
		printf("\n您要进行的操作是：");
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
			printf("\n你要插入的元素是：\n");
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
			printf("\n该操作不存在\n\n");
			break;
		}
	}

	return 0;
}

void InitQueue(LinkQueue* Q) {
	Q->front = (QNode*)malloc(sizeof(QNode));
	if (!Q->front) {
		printf("\n分配空间失败\n");
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
	printf("\n队列的长度是：%d\n", len);
	return len;
}

QElemType GetHead(LinkQueue* Q) {
	QNode* p = Q->front->next;
	if (Q->front == Q->rear) {
		printf("\nERROR\n");
		return 0;
	}
	else {
		printf("\n队头元素是：%d\n",p->data);
		printf("\nOK\n");
		return p->data;
	}
}

void EnQueue(LinkQueue* Q, QElemType e) {
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p) {
		printf("\n分配空间失败\n");
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
		printf("\n删除的队头元素是：%d\n", p->data);
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