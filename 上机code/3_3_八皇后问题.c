#include<stdio.h>
#include<stdlib.h>

#define STACK_INT_SIZE 100
#define STACKINCREMENT 10

int sum = 0;

typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;//ջ�ṹ

//����ջ
void InitStack(SqStack* S) {
	S->top = (int*)malloc(STACK_INT_SIZE * sizeof(int));
	if (!S->top) {
		printf("\n�ռ䲻�㣬����ջʧ��\n");
		exit(0);
	}
	S->base = S->top;
	S->stacksize = STACK_INT_SIZE;
}
//����ջ
void DestroyStack(SqStack* S) {
	S->top = S->base;
	free(S->base);
	S->stacksize = 0;
}
//PUSH
int Push(SqStack* S, int e) {
	if (S->top-S->base >= S->stacksize) {
		S->base = (int*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(int));
		if (!S->base) {
			printf ("\n����ռ�ʧ��\n");
			exit(0);
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top) = e;
	S->top++;
	return e;
}
//POP
int Pop(SqStack* S) {
	if (S->top == S->base) {
		printf("\nջΪ��\n");
		return 0;
	}
	else {
		S->top--;
		return *(S->top);
	}
}
//���λ���Ƿ�Ϸ�
int check(SqStack* S) {
	int len = S->top - S->base;
	if (len==0) {
		return 1;
	}
	int x1, y1, x2, y2;
	x1 = len-1;
	y1 = *(S->top - 1);
	for (int i = 0; i < x1; i++) {
		x2 = i;
		y2 = *(S->base + i);
		if ((y1==y2)||(x1+y1==x2+y2)||(x1-y1==x2-y2)) {
			return 0;
		}
	}
	return 1;
}
//��ӡ����
void printfchessboard(SqStack* S) {
	printf("\n\n���ǵ�%d�ֽⷨ\n",sum);
	int* p;
	for (int i = 0; i < 8; i++) {
		p = S->base + i;
		for (int j = 0; j < 8; j++) {
			if (j == *p) {
				printf(" 1 ");
			}
			else {
				printf(" 0 ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
}
//���˻ʺ�
void Queen8(SqStack*S) {
	if (check(S)) {
		if (S->top - S->base == 8) {
			sum++;
			printfchessboard(S);
			return;
		}
		else {
			for (int i = 0; i < 8; i++) {
				Push(S, i);
				Queen8(S);
				Pop(S);
			}
			return;
		}
	}
	else {
		return;
	}
}

int main() {
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitStack(S);

	Queen8(S);
	printf("\n�˻ʺ��ĸ����ǣ�%d\n", sum);

	DestroyStack(S);

	return 0;
}