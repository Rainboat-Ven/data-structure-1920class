#include<stdio.h>

int main() {
	int T[5][20] = { 0 };
	int flag[20] = { 0 };
	int n;
	scanf_s("%d", &n);
	int p[100];
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &p[i]);
	}
	int j;
	int q;
	int x, y;
	for (i = 0; i < n; i++) {
		//��ָ��ѭ��
		for (j = 0; j < 20; j++) {
			//�жϵ�j+1���Ƿ����㹻��λ
			if (flag[j] + p[i] <= 5) {
				//��
				//��λ
				q = 0;
				while (p[i] != 0) {
					if (T[q][j] == 0) {
						T[q][j] = 1;//��λ
						printf("%d ", 5 * j + q + 1);//��ӡ���
						p[i]--;//��Ҫ���Ʊ����һ
						flag[j]++;//��j+1�ſ�λ��һ(������λ��һ)
					}
					q++;//�ж���һ�ŵ��¸�λ��
				}
				break;//����ѭ��
			}
			//�����һ�Ż�û��������λ
			if (j == 19) {
				//��С�����ҿ�λ��
				for (y = 0; y < 20; y++) {
					for (x = 0; x < 5; x++) {
						if (p[i] != 0&&T[x][y]==0) {
							T[x][y] = 1;
							printf("%d ", 5 * y + x + 1);
							p[i]--;
							flag[y]++;
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}