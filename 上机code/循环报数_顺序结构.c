#include <stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

int main() {
	SqList* L = (SqList*)malloc(sizeof(SqList));
	int m, n;
	printf("����mΪ��");
	scanf_s("%d", &m);
	printf("\nnΪ��");
	scanf_s("%d", &n);
	printf("\n");
	if (m < 1 || n < 1) {
		printf("\n����ʧ��\n");
		exit(0);
	}

	L->elem = (ElemType*)malloc(m * sizeof(ElemType));
	if (!L->elem) {
		printf("\n����ռ�ʧ��\n");
		exit(0);
	}
	L->length = m;
	L->listsize = m;
	int i ;
	for (i=0; i < m; i++) {
		L->elem[i] = 0;
	}

	int j = L->length;
	i = 0;
	int num=1;
	while (j) {
		if (L->elem[i]) {
			i++;
			if (i > L->length - 1) {
				i = 0;
			}
		}//����Ƿ���У��Ѿ����в�����
		else {
			//printf("��%d���˱�%d\n", i + 1, num);
			if (num==n) {
				L->elem[i] = 1;
				printf("��%d���˳���\n\n", i + 1);
				j--;
				num = 0;
			}
			i++;
			if (i > L->length - 1) {
				i = 0;
			}
			num++;
		}
	}

	free(L->elem);

	return 0;
}