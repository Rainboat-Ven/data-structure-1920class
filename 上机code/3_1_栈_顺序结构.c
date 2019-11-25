#include <stdio.h>
#include<stdlib.h>

#define STACK_INT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

void InitStack(SqStack* S);
void DestroyStack(SqStack* S);
void ClearStack(SqStack* S);
int StackEmpty(SqStack* S);
int StackLength(SqStack* S);
SElemType GetTop(SqStack* S);
SElemType Push(SqStack* S, SElemType e);
SElemType Pop(SqStack* S);
void StackTraverse(SqStack* S);
void visit(SElemType e);


int main() {
	int loop = 1;
	int choice;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	int i;
	SElemType e;
	while (loop) {
		printf("\n=================================================================================================\n");
		printf("1������һ���յ�ջS\n");
		printf("2������ջS\n");
		printf("3����S��Ϊ��ջ\n");
		printf("4����SΪ��ջ���򷵻�TRUE�����򷵻�FALSE\n");
		printf("5������S��Ԫ�صĸ�������ջ�ĳ���\n");
		printf("6����ջ���գ�����e����S��ջ��Ԫ��\n");
		printf("7������Ԫ��eΪ�µ�ջ��Ԫ��\n");
		printf("8����ջ���գ�ɾ��S��ջ��Ԫ�أ�����e������ֵ\n");
		printf("9�����ζ�S��ÿ��Ԫ�ص��ú���visit()\n");
		printf("\n��Ҫ���еĲ����ǣ�");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			InitStack(S);
			break;
		case 2:
			DestroyStack(S);
			break;
		case 3:
			ClearStack(S);
			break;
		case 4:
			if (StackEmpty(S)) {
				printf("\nTRUE\n");
			}
			else {
				printf("\nFALSE\n");
			}
			break;
		case 5:
			printf("\nS��Ԫ�ظ����ǣ�%d\n", StackLength(S));
			break;
		case 6:
			GetTop(S);
			break;
		case 7:
			printf("\nҪ�����Ԫ���ǣ�");
			scanf_s("%d", &e);
			Push(S, e);
			break;
		case 8:
			if (S->base == S->top) {
				printf("\nERROR\n");
			}
			else {
				Pop(S);
				printf("\nOK\n");
			}
			break;
		case 9:
			StackTraverse(S);
			break;
		default:
			printf("\n�ò���������\n\n");
			break;
		}
	}

	return 0;
}

void InitStack(SqStack* S) {
	S->top = (SElemType*)malloc(STACK_INT_SIZE * sizeof(SElemType));
	if (!S->top) {
		printf("\n�ռ䲻�㣬����ջʧ��\n");
		exit(0);
	}
	printf("\n����ջ�ɹ�\n");
	S->base = S->top;
	S->stacksize = STACK_INT_SIZE;
}

void DestroyStack(SqStack* S) {
	S->top = S->base;
	free(S->base);
	S->stacksize = 0;
	printf("\n����ջ�ɹ�\n");
}

void ClearStack(SqStack* S) {
	S->top = S->base;
	printf("\n��ջ��Ϊ��ջ�ɹ�\n");
}

int StackEmpty(SqStack* S) {
	return (S->base == S->top) ? 1 : 0;
}

int StackLength(SqStack* S) {
	return S->top - S->base;
}

SElemType GetTop(SqStack* S) {
	SElemType* p = S->top - 1;
	SElemType e=*p;
	if (S->base == S->top) {
		printf("\nջΪ��\n");
		return 0;
	}
	else {
		printf("\nջ��Ԫ��Ϊ%d\n", e);
		return e;
	}
}

SElemType Push(SqStack* S, SElemType e) {
	if (StackLength(S) >= S->stacksize) {
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base) {
			return ("\n����ռ�ʧ��\n");
			exit(0);
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top) = e;
	S->top++;
	return e;
}

SElemType Pop(SqStack* S) {
	if (S->top == S->base) {
		printf("\nջΪ��\n");
		return 0;
	}
	else {
		S->top--;
		printf("\nɾ����Ԫ���ǣ�%d\n", *(S->top));
		return *(S->top);
	}
}

void StackTraverse(SqStack* S) {
	SElemType* p = S->base;
	while (p != S->top) {
		visit(*p);
		p++;
	}
}

void visit(SElemType e){
	printf("\n%d", e);
}