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
		printf("1：构造一个空的栈S\n");
		printf("2：销毁栈S\n");
		printf("3：将S置为空栈\n");
		printf("4：若S为空栈，则返回TRUE，否则返回FALSE\n");
		printf("5：返回S中元素的个数，即栈的长度\n");
		printf("6：若栈不空，则用e返回S的栈顶元素\n");
		printf("7：插入元素e为新的栈顶元素\n");
		printf("8：若栈不空，删除S的栈顶元素，并用e返回其值\n");
		printf("9：依次对S的每个元素调用函数visit()\n");
		printf("\n您要进行的操作是：");
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
			printf("\nS的元素个数是：%d\n", StackLength(S));
			break;
		case 6:
			GetTop(S);
			break;
		case 7:
			printf("\n要插入的元素是：");
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
			printf("\n该操作不存在\n\n");
			break;
		}
	}

	return 0;
}

void InitStack(SqStack* S) {
	S->top = (SElemType*)malloc(STACK_INT_SIZE * sizeof(SElemType));
	if (!S->top) {
		printf("\n空间不足，创建栈失败\n");
		exit(0);
	}
	printf("\n创建栈成功\n");
	S->base = S->top;
	S->stacksize = STACK_INT_SIZE;
}

void DestroyStack(SqStack* S) {
	S->top = S->base;
	free(S->base);
	S->stacksize = 0;
	printf("\n销毁栈成功\n");
}

void ClearStack(SqStack* S) {
	S->top = S->base;
	printf("\n将栈置为空栈成功\n");
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
		printf("\n栈为空\n");
		return 0;
	}
	else {
		printf("\n栈顶元素为%d\n", e);
		return e;
	}
}

SElemType Push(SqStack* S, SElemType e) {
	if (StackLength(S) >= S->stacksize) {
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base) {
			return ("\n分配空间失败\n");
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
		printf("\n栈为空\n");
		return 0;
	}
	else {
		S->top--;
		printf("\n删除的元素是：%d\n", *(S->top));
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