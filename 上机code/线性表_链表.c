#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode;

typedef struct LinkList {
	int length;
	struct LNode* head;
}LinkList;

LinkList* InitList();
int DestroyList(LinkList* L);
int ClearList(LinkList* L);
int ListEmpty(LinkList* L);
int ListLength(LinkList* L);
ElemType GetElem(LinkList* L,int i);
int LocateElem(LinkList* L, ElemType e);
int compare(ElemType a, ElemType b);
ElemType PriorElem(LinkList* L, ElemType cur_e);
ElemType NextElem(LinkList* L, ElemType cur_e);
int ListInsert(LinkList* L, int i, ElemType e);
ElemType ListDelete(LinkList* L, int i);
int ListTraverse(LinkList* L);
int visit(ElemType a);
int ListInvert(LinkList* L);

int main() {
	int loop = TRUE;
	int choice;
	int i;
	ElemType e;
	LinkList* L=NULL;
	while (loop) {
		printf("\n=================================================================================================\n");
		printf("1：构造一个空的线性表L\n");
		printf("2：销毁线性表L\n");
		printf("3：将L重置为空表\n");
		printf("4：若L为空表，则返回TRUE，否则返回FALSE\n");
		printf("5：返回L中数据元素的个数\n");
		printf("6：用e返回L中第i个数据元素的值\n");
		printf("7：返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0\n");
		printf("8：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义\n");
		printf("9：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义\n");
		printf("10：在L中第i个位置插入新的数据元素e，L的长度加1\n");
		printf("11：删除L的第i个数据元素，并用e返回其值，L的长度减1\n");
		printf("12：依次对L的每个数据元素调用函数visit()\n");
		printf("13：就地逆置线性表\n");
		printf("\n您要进行的操作是：");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			L = InitList();
			break;
		case 2:
			DestroyList(L);
			break;
		case 3:
			ClearList(L);
			break;
		case 4:
			ListEmpty(L);
			break;
		case 5:
			ListLength(L);
			break;
		case 6:
			printf("\n要返回第几个元素的值：");
			scanf_s("%d", &i);
			printf("\n");
			GetElem(L, i);
			break;
		case 7:
			printf("\n要与哪个数据比较：");
			scanf_s("%d", &e);
			printf("\n");
			LocateElem(L, e);
			break;
		case 8:
			printf("\n要返回哪个元素的前驱：");
			scanf_s("%d", &e);
			printf("\n");
			PriorElem(L, e);
			break;
		case 9:
			printf("\n要返回哪个元素的后继：");
			scanf_s("%d", &e);
			printf("\n");
			NextElem(L, e);
			break;
		case 10:
			printf("\n要在哪个位置插入元素：");
			scanf_s("%d", &i);
			printf("\n");
			printf("\n要插入的元素是：");
			scanf_s("%d", &e);
			printf("\n");
			ListInsert(L, i, e);
			break;
		case 11:
			printf("\n要在哪个位置删除元素：");
			scanf_s("%d", &i);
			printf("\n");
			ListDelete(L, i);
			break;
		case 12:
			ListTraverse(L);
			break;
		case 13:
			ListInvert(L);
			break;
		default:
			printf("\n该操作不存在\n\n");
			break;
		}
	}

	return 0;
}

LinkList* InitList() {
	LinkList* L= (LinkList*)malloc(sizeof(LinkList));
	if (!L) {
		printf("\n创建线性表失败\n");
		exit(FALSE);
	}
	L->length = 0;
	L->head = NULL;
	printf("\n创建线性表成功\n");
	return L;
}

int DestroyList(LinkList* L) {
	ClearList(L);
	free(L);
	L = NULL;
	printf("\n销毁线性表成功\n");
	return TRUE;
}

int ClearList(LinkList* L) {
	LNode* p;
	LNode* q;
	p = L->head;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	};
	L->length = 0;
	printf("\n清空线性表成功\n");
	return  TRUE;
}

int ListEmpty(LinkList* L) {
	if (L->length == 0) {
		printf("\nTRUE\n");
		return TRUE;
	}
	else {
		printf("\nFALSE\n");
		return FALSE;
	}
}

int ListLength(LinkList* L) {
	printf("\n线性表有%d个元素\n",L->length);
	return L->length;
}

ElemType GetElem(LinkList* L,int i) {
	LNode* p = L->head;
	if (i <= 0||i>L->length) {
		printf("\n操作失败\n");
		exit(FALSE);
	}
	for (i; i-1 > 0; i--) {
		p = p->next;
	}
	printf("\n第%d个元素是%d\n", i, p->data);
	return p->data;
}

int LocateElem(LinkList* L, ElemType e) {
	LNode* p = L->head;
	int i=1;
	while (p) {
		if (compare(p->data,e)) {
			printf("\n第一个与e满足compare()的数据元素的位序是%d\n", i);
			return i;
		}
		p = p->next;
		i++;
	}
	printf("\n这样的数据元素不存在\n");
	return 0;
}

int compare(ElemType a, ElemType b) {
	return a > b ? 1 : 0;
}

ElemType PriorElem(LinkList* L, ElemType cur_e) {
	LNode* p = L->head;
	LNode* pre;
	if (p->data == cur_e) {
		printf("\n操作失败\n");
		exit(FALSE);
	}
	pre = p;
	p = p->next;
	while (p) {
		if (p->data == cur_e) {
			printf("\n%d的前驱是%d\n", cur_e, pre->data);
			return pre->data;
		}
	}
	printf("\n操作失败\n");
	exit(FALSE);
}

ElemType NextElem(LinkList* L, ElemType cur_e) {
	LNode* p = L->head;
	while (p->next) {
		if (p->data == cur_e) {
			printf("\n%d的后继是%d\n", cur_e, p->next->data);
			return p->next->data;
		}
	}
	printf("\n操作失败\n");
	exit(FALSE);
}

int ListInsert(LinkList* L, int i, ElemType e) {
	LNode* p = L->head;
	if (i<1 || i>L->length + 1) {
		printf("\n操作失败\n");
		exit(FALSE);
	}
	L->length++;
	LNode* new_p;
	if (i == 1) {
		new_p = (LNode*)malloc(sizeof(LNode));
		if (!new_p) {
			printf("\n操作失败\n");
			exit(FALSE);
		}
		new_p->data = e;
		new_p->next = p;
		L->head = new_p;
	}
	else{
		while (i > 2) {
			p = p->next;
			i--;
		}
		new_p = (LNode*)malloc(sizeof(LNode));
		if (!new_p) {
			printf("\n操作失败\n");
			exit(FALSE);
		}
		new_p->data = e;
		new_p->next = p->next;
		p->next = new_p;
	}
	printf("\n插入元素成功\n");
	return TRUE;
}

ElemType ListDelete(LinkList* L, int i) {
	LNode* p = L->head;
	ElemType e;
	LNode* q = NULL;
	if (i<1 || i>L->length) {
		printf("\n操作失败\n");
		exit(FALSE);
	}
	L->length--;
	if (i == 1) {
		L->head = p->next;
		e = p->data;
		free(p);
		printf("\n成功删除元素%d\n", e);
		return e;
	}
	else {
		while (i > 2) {
			p = p->next;
			i--;
		}
		q = p->next;
		p->next = q->next;
		e = q->data;
		free(q);
		printf("\n成功删除元素%d\n", e);
		return e;
	}
}

int ListTraverse(LinkList* L) {
	LNode* p = L->head;
	if (L->length == 0) {
		printf("\nL为空表\n");
		return FALSE;
	}
	while (p) {
		visit(p->data);
		p = p->next;
	}
	return TRUE;
}

int visit(ElemType a) {
	printf("\n    %d", a);
	return TRUE;
}

int ListInvert(LinkList* L){
	LNode* p = L->head;
	if (L->head == NULL||L->head->next==NULL) {
		printf("\n就地逆置成功\n");
		return TRUE;
	}
	LNode* q = p->next;
	p->next = NULL;
	LNode* e;
	while (q->next) {
		e = q->next;
		q->next = p;
		p = q;
		q = e;
	}
	q->next = p;
	L->head = q;
	printf("\n就地逆置成功\n");
	return TRUE;
	return 0;
}