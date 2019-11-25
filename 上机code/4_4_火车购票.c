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
		//按指令循环
		for (j = 0; j < 20; j++) {
			//判断第j+1排是否有足够空位
			if (flag[j] + p[i] <= 5) {
				//有
				//排位
				q = 0;
				while (p[i] != 0) {
					if (T[q][j] == 0) {
						T[q][j] = 1;//排位
						printf("%d ", 5 * j + q + 1);//打印结果
						p[i]--;//还要买的票数减一
						flag[j]++;//第j+1排空位减一(已排座位加一)
					}
					q++;//判断这一排的下个位置
				}
				break;//跳出循环
			}
			//到最后一排还没有连续空位
			if (j == 19) {
				//从小到大找空位排
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