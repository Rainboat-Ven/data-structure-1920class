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
	printf("人数m为：");
	scanf_s("%d", &m);
	printf("\nn为：");
	scanf_s("%d", &n);
	printf("\n");
	if (m < 1 || n < 1) {
		printf("\n操作失败\n");
		exit(0);
	}

	L->elem = (ElemType*)malloc(m * sizeof(ElemType));
	if (!L->elem) {
		printf("\n分配空间失败\n");
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
		}//检测是否出列，已经出列不报数
		else {
			//printf("第%d个人报%d\n", i + 1, num);
			if (num==n) {
				L->elem[i] = 1;
				printf("第%d个人出列\n\n", i + 1);
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