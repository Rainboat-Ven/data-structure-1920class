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
		printf("12�����ζ�L��ÿ������Ԫ�ص��ú���visit()\n");
		printf("13���͵��������Ա�\n");
		printf("\n��Ҫ���еĲ����ǣ�");
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
			printf("\nҪ���صڼ���Ԫ�ص�ֵ��");
			scanf_s("%d", &i);
			printf("\n");
			GetElem(L, i);
			break;
		case 7:
			printf("\nҪ���ĸ����ݱȽϣ�");
			scanf_s("%d", &e);
			printf("\n");
			LocateElem(L, e);
			break;
		case 8:
			printf("\nҪ�����ĸ�Ԫ�ص�ǰ����");
			scanf_s("%d", &e);
			printf("\n");
			PriorElem(L, e);
			break;
		case 9:
			printf("\nҪ�����ĸ�Ԫ�صĺ�̣�");
			scanf_s("%d", &e);
			printf("\n");
			NextElem(L, e);
			break;
		case 10:
			printf("\nҪ���ĸ�λ�ò���Ԫ�أ�");
			scanf_s("%d", &i);
			printf("\n");
			printf("\nҪ�����Ԫ���ǣ�");
			scanf_s("%d", &e);
			printf("\n");
			ListInsert(L, i, e);
			break;
		case 11:
			printf("\nҪ���ĸ�λ��ɾ��Ԫ�أ�");
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

LinkList* InitList() {
	LinkList* L= (LinkList*)malloc(sizeof(LinkList));
	if (!L) {
		printf("\n�������Ա�ʧ��\n");
		exit(FALSE);
	}
	L->length = 0;
	L->head = NULL;
	printf("\n�������Ա�ɹ�\n");
	return L;
}

int DestroyList(LinkList* L) {
	ClearList(L);
	free(L);
	L = NULL;
	printf("\n�������Ա�ɹ�\n");
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
	printf("\n������Ա�ɹ�\n");
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
	printf("\n���Ա���%d��Ԫ��\n",L->length);
	return L->length;
}

ElemType GetElem(LinkList* L,int i) {
	LNode* p = L->head;
	if (i <= 0||i>L->length) {
		printf("\n����ʧ��\n");
		exit(FALSE);
	}
	for (i; i-1 > 0; i--) {
		p = p->next;
	}
	printf("\n��%d��Ԫ����%d\n", i, p->data);
	return p->data;
}

int LocateElem(LinkList* L, ElemType e) {
	LNode* p = L->head;
	int i=1;
	while (p) {
		if (compare(p->data,e)) {
			printf("\n��һ����e����compare()������Ԫ�ص�λ����%d\n", i);
			return i;
		}
		p = p->next;
		i++;
	}
	printf("\n����������Ԫ�ز�����\n");
	return 0;
}

int compare(ElemType a, ElemType b) {
	return a > b ? 1 : 0;
}

ElemType PriorElem(LinkList* L, ElemType cur_e) {
	LNode* p = L->head;
	LNode* pre;
	if (p->data == cur_e) {
		printf("\n����ʧ��\n");
		exit(FALSE);
	}
	pre = p;
	p = p->next;
	while (p) {
		if (p->data == cur_e) {
			printf("\n%d��ǰ����%d\n", cur_e, pre->data);
			return pre->data;
		}
	}
	printf("\n����ʧ��\n");
	exit(FALSE);
}

ElemType NextElem(LinkList* L, ElemType cur_e) {
	LNode* p = L->head;
	while (p->next) {
		if (p->data == cur_e) {
			printf("\n%d�ĺ����%d\n", cur_e, p->next->data);
			return p->next->data;
		}
	}
	printf("\n����ʧ��\n");
	exit(FALSE);
}

int ListInsert(LinkList* L, int i, ElemType e) {
	LNode* p = L->head;
	if (i<1 || i>L->length + 1) {
		printf("\n����ʧ��\n");
		exit(FALSE);
	}
	L->length++;
	LNode* new_p;
	if (i == 1) {
		new_p = (LNode*)malloc(sizeof(LNode));
		if (!new_p) {
			printf("\n����ʧ��\n");
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
			printf("\n����ʧ��\n");
			exit(FALSE);
		}
		new_p->data = e;
		new_p->next = p->next;
		p->next = new_p;
	}
	printf("\n����Ԫ�سɹ�\n");
	return TRUE;
}

ElemType ListDelete(LinkList* L, int i) {
	LNode* p = L->head;
	ElemType e;
	LNode* q = NULL;
	if (i<1 || i>L->length) {
		printf("\n����ʧ��\n");
		exit(FALSE);
	}
	L->length--;
	if (i == 1) {
		L->head = p->next;
		e = p->data;
		free(p);
		printf("\n�ɹ�ɾ��Ԫ��%d\n", e);
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
		printf("\n�ɹ�ɾ��Ԫ��%d\n", e);
		return e;
	}
}

int ListTraverse(LinkList* L) {
	LNode* p = L->head;
	if (L->length == 0) {
		printf("\nLΪ�ձ�\n");
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
		printf("\n�͵����óɹ�\n");
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
	printf("\n�͵����óɹ�\n");
	return TRUE;
	return 0;
}