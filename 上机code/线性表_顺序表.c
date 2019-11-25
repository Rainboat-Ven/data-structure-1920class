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
		printf("1������һ���յ����Ա�L\n");
		printf("2���������Ա�L\n");
		printf("3����L����Ϊ�ձ�\n");
		printf("4����LΪ�ձ��򷵻�TRUE�����򷵻�FALSE\n");
		printf("5������L������Ԫ�صĸ���\n");
		printf("6����e����L�е�i������Ԫ�ص�ֵ\n");
		printf("7������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0\n");
		printf("8����cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���\n");
		printf("9����cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���\n");
		printf("10����L�е�i��λ�ò����µ�����Ԫ��e��L�ĳ��ȼ�1\n");
		printf("11��ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1\n");
		printf("12�����ζ�L��ÿ������Ԫ�ص��ú���visit()��\n");
		printf("13���͵���ת���Ա�\n");
		printf("\n��Ҫ���еĲ����ǣ�");
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
			   printf("\n��Ҫ�õ��ڼ���Ԫ�ص�ֵ��");
			   scanf_s("%d", &i);
			   printf("\n");
			   GetElem(L, i);
			   break;
		   case 7:
			   printf("\n��Ҫ�Ƚϵ�Ԫ��e�ǣ�");
			   scanf_s("%d", &e);
			   printf("\n");
			   LocateElem(L, e);
			   break;
		   case 8:
			   printf("\n��Ҫ�Ƚϵ�Ԫ��cur_e�ǣ�");
			   scanf_s("%d", &e);
			   printf("\n");
			   PriorElem(L, e);
			   break;
		   case 9:
			   printf("\n��Ҫ�Ƚϵ�Ԫ��cur_e�ǣ�");
			   scanf_s("%d", &e);
			   printf("\n");
			   NextElem(L, e);
			   break;
		   case 10:
			   printf("\n��Ҫ�����λ��i�ǣ�");
			   scanf_s("%d", &i);
			   printf("\n");
			   printf("\n��Ҫ�����Ԫ��e�ǣ�");
			   scanf_s("%d", &e);
			   printf("\n");
			   ListInsert(L, i, e);
			   break;
		   case 11:
			   printf("\n��Ҫɾ����λ��i�ǣ�");
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
			   printf("\n�ò���������\n\n");
			   break;
		}
	}

	return 0;
}

int InitList(SqList* L) {
	L->elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L->elem) {
		printf("\n�ռ䲻�㣬�������Ա�ʧ��\n");
		exit(FALSE);
	}
	printf("\n�������Ա�ɹ�\n");
	L->length = 0;
	L->listsize = LIST_INT_SIZE;
	return TRUE;
}

int DestroyList(SqList* L) {
	free(L->elem);
	printf("\n�������Ա�ɹ�\n");
	return TRUE;
}

int ClearList(SqList* L) {
	L->length = 0;
	printf("\n�������Ա�ɹ�\n");
	return TRUE;
}

int ListEmpty(SqList* L) {
	if (L->length == 0) {
		printf("\nL�ǿձ�\n");
		return TRUE;
	}
	else {
		printf("\nL���ǿձ�\n");
		return FALSE;
	}
}

int ListLength(SqList* L) {
	printf("\n���Ա���%d��Ԫ��\n",L->length);
	return L->length;
}

int GetElem(SqList* L,int i) {
	ElemType e;
	if (i<1 && i - 1 > L->length) {
		printf("iֵ���Ϸ�");
		exit(FALSE);
	}
	else {
		e = L->elem[i - 1];
		printf("\n��%d��Ԫ����%d\n", i, e);
		return e;
	}
}

int LocateElem(SqList* L, ElemType e) {
	int i;
	for (i = 0; i <= L->length; i++) {
		if (compare(L->elem[i], e)) {
			printf("\nL�е�һ����e����compare()������Ԫ��λ����%d\n", i + 1);
			return i + 1;
		}
	}
	printf("\n����������Ԫ�ز�����\n");
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
			printf("\n%d��ǰ����%d\n", cur_e, pre_e);
			return pre_e;
		}
	}
	printf("\n����ʧ��\n");
	exit(FALSE);
}

int NextElem(SqList* L, ElemType cur_e) {
	int i;
	ElemType next_e;
	for (i = 0; i <= L->length; i++) {
		if (cur_e == L->elem[i] && i != L->length) {
			next_e = L->elem[i + 1];
			printf("\n%d�ĺ����%d\n", cur_e, next_e);
			return next_e;
		}
	}
	printf("\n����ʧ��\n");
	exit(FALSE);
}

int ListInsert(SqList* L, int i, ElemType e) {
	if (i<1 || i - 1 > L->length) {
		printf("iֵ���Ϸ�");
		exit(FALSE);
	}
	if (L->length > L->listsize) {
		ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTNCREMENT) * sizeof(ElemType));
		if (!newbase) {
			printf("\n�ڴ����ʧ��\n");
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
		printf("iֵ���Ϸ�");
		exit(FALSE);
	}
	ElemType* p = &(L->elem[i - 1]);
	ElemType e = *p;
	ElemType* q = &(L->elem[L->length - 1]);
	for (++p; p <= q; ++p) {
		*(p - 1) = *p;
	}
	--L->length;
	printf("\nɾ����Ԫ��e=%d\n", e);
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
	printf("\n�͵���ת�ɹ�\n");
	return TRUE;
}

