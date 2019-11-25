#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define LIST_INT_SIZE 100
#define LISTNCREMENT 10

typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

int InitList(SqList* L);
int DestroyList(SqList* L);
int ClearList(SqList* L);
int ListEmpty(SqList* L);
int ListLength(SqList* L);
int GetElem(SqList* L, int i);
int LocateElem(SqList* L, ElemType e);
int compare(ElemType a, ElemType b);
int PriorElem(SqList* L, ElemType cur_e);
int NextElem(SqList* L, ElemType cur_e);
int ListInsert(SqList* L, int i, ElemType e);
ElemType ListDelete(SqList* L, int i);
int ListTraverse(SqList* L);
int visit(ElemType a);
int ListInvert(SqList* L);

int main() {
	int loop = TRUE;
	int choice;
	SqList* L = (SqList*)malloc(sizeof(SqList));
	int i;
	ElemType e;
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
		printf("12：依次对L的每个数据元素调用函数visit()。\n");
		printf("13：就地逆转线性表\n");
		printf("\n您要进行的操作是：");
		scanf_s("%d", &choice);
		printf("\n");
		switch (choice) {
		   case 1:
			   InitList(L);
			   break;
		   case 2:
			   DestroyList(L);
			   break;
		   case 3:
			   ClearList(L);
			   break;
		   case 4:
			   if (ListEmpty(L)) {
				   printf("\nTRUE\n");
			   }
			   else {
				   printf("\nFALSE\n");
			   }
			   break;
		   case 5:
			   ListLength(L);
			   break;
		   case 6:
			   printf("\n您要得到第几个元素的值：");
			   scanf_s("%d", &i);
			   printf("\n");
			   GetElem(L, i);
			   break;
		   case 7:
			   printf("\n您要比较的元素e是：");
			   scanf_s("%d", &e);
			   printf("\n");
			   LocateElem(L, e);
			   break;
		   case 8:
			   printf("\n您要比较的元素cur_e是：");
			   scanf_s("%d", &e);
			   printf("\n");
			   PriorElem(L, e);
			   break;
		   case 9:
			   printf("\n您要比较的元素cur_e是：");
			   scanf_s("%d", &e);
			   printf("\n");
			   NextElem(L, e);
			   break;
		   case 10:
			   printf("\n您要插入的位置i是：");
			   scanf_s("%d", &i);
			   printf("\n");
			   printf("\n您要插入的元素e是：");
			   scanf_s("%d", &e);
			   printf("\n");
			   ListInsert(L, i, e);
			   break;
		   case 11:
			   printf("\n您要删除的位置i是：");
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

int InitList(SqList* L) {
	L->elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L->elem) {
		printf("\n空间不足，创建线性表失败\n");
		exit(FALSE);
	}
	printf("\n创建线性表成功\n");
	L->length = 0;
	L->listsize = LIST_INT_SIZE;
	return TRUE;
}

int DestroyList(SqList* L) {
	free(L->elem);
	printf("\n销毁线性表成功\n");
	return TRUE;
}

int ClearList(SqList* L) {
	L->length = 0;
	printf("\n重置线性表成功\n");
	return TRUE;
}

int ListEmpty(SqList* L) {
	if (L->length == 0) {
		printf("\nL是空表\n");
		return TRUE;
	}
	else {
		printf("\nL不是空表\n");
		return FALSE;
	}
}

int ListLength(SqList* L) {
	printf("\n线性表有%d个元素\n",L->length);
	return L->length;
}

int GetElem(SqList* L,int i) {
	ElemType e;
	if (i<1 && i - 1 > L->length) {
		printf("i值不合法");
		exit(FALSE);
	}
	else {
		e = L->elem[i - 1];
		printf("\n第%d个元素是%d\n", i, e);
		return e;
	}
}

int LocateElem(SqList* L, ElemType e) {
	int i;
	for (i = 0; i <= L->length; i++) {
		if (compare(L->elem[i], e)) {
			printf("\nL中第一个与e满足compare()的数据元素位数是%d\n", i + 1);
			return i + 1;
		}
	}
	printf("\n这样的数据元素不存在\n");
	return 0;
}

int compare(ElemType a, ElemType b) {
	if (a > b) {
		return 1;
	}
	else {
		return 0;
	}
}

int PriorElem(SqList* L, ElemType cur_e) {
	int i;
	ElemType pre_e;
	for (i = 0; i <= L->length; i++) {
		if (cur_e == L->elem[i]&&i!=0) {
			pre_e = L->elem[i - 1];
			printf("\n%d的前驱是%d\n", cur_e, pre_e);
			return pre_e;
		}
	}
	printf("\n操作失败\n");
	exit(FALSE);
}

int NextElem(SqList* L, ElemType cur_e) {
	int i;
	ElemType next_e;
	for (i = 0; i <= L->length; i++) {
		if (cur_e == L->elem[i] && i != L->length) {
			next_e = L->elem[i + 1];
			printf("\n%d的后继是%d\n", cur_e, next_e);
			return next_e;
		}
	}
	printf("\n操作失败\n");
	exit(FALSE);
}

int ListInsert(SqList* L, int i, ElemType e) {
	if (i<1 || i - 1 > L->length) {
		printf("i值不合法");
		exit(FALSE);
	}
	if (L->length > L->listsize) {
		ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTNCREMENT) * sizeof(ElemType));
		if (!newbase) {
			printf("\n内存分配失败\n");
			exit(FALSE);
		}
		L->elem = newbase;
		L->listsize += LISTNCREMENT;
	}
	ElemType* q = &(L->elem[i - 1]);
	for (ElemType* p = &(L->elem[L->length - 1]); p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	++L->length;
	return TRUE;
}

ElemType ListDelete(SqList* L, int i) {
	if (i<1 || i  > L->length) {
		printf("i值不合法");
		exit(FALSE);
	}
	ElemType* p = &(L->elem[i - 1]);
	ElemType e = *p;
	ElemType* q = &(L->elem[L->length - 1]);
	for (++p; p <= q; ++p) {
		*(p - 1) = *p;
	}
	--L->length;
	printf("\n删掉的元素e=%d\n", e);
	return e;
}

int ListTraverse(SqList* L) {
	int i;
	for (i = 0; i <= L->length-1; i++) {
		visit(L->elem[i]);
	}
	return TRUE;
}

int visit(ElemType a) {
	printf("  %d  ", a);
	printf("\n");
	return a;
}

int ListInvert(SqList* L) {
	ElemType* p = &(L->elem[0]);
	ElemType* q = &(L->elem[L->length - 1]);
	ElemType e ;
	while (p<q) {
		e = *p;
		*p = *q;
		*q = e;
		p++;
		q--;
	}
	printf("\n就地逆转成功\n");
	return TRUE;
}

