#include<iostream>
#include <cstring>
using namespace std;

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char** HuffmanCode;

int main() {
	cout << "输入元素个数：";
	int n;
	cin >> n;
	getchar();
	if (n <= 1) {
		cout << "元素过少" << endl;
		return 0;
	}
	int m = 2 * n - 1;
	HuffmanTree HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	HuffmanTree p = HT;
	int i = 1;
	unsigned int w;
	++p;
	//初始化
	while (i <= n) {
		cout << "输入第" << i << "个元素的权值：";
		cin >> w;
		getchar();
		*p = { w,0,0,0 };
		++i;
		++p;
	}
	while (i <= m) {
		*p = { 0,0,0,0 };
		++i;
		++p;
	}
	int s1, s2;
	//建立哈夫曼树
	for (i = n + 1; i <= m; ++i) {
		//确定s1,s2
		s1 = 1;
		s2 = 1;
		for (int j = 1; j < i; j++) {
			//s1最小
			while (HT[s1].parent != 0&&s1<i) {
				s1++;
			}
			if (HT[j].parent == 0 && HT[j].weight < HT[s1].weight) {
				s1 = j;
			}
		}
		for (int j = 1; j < i; j++) {
			//s2次小
			while ((HT[s2].parent != 0 ||s2==s1)&& s2 < i) {
				s2++;
			}
			if (HT[j].parent == 0 && HT[j].weight < HT[s2].weight && j != s1) {
				s2 = j;
			}
		}
		//
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//求哈夫曼编码
	HuffmanCode HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	char* cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	int start;
	int f;
	int c;
	for (i = 1; i <= n; i++) {
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0) {
			if (HT[f].lchild == c) {
				cd[--start] = '0';
			}
			else {
				cd[--start] = '1';
			}
			c = f;
			f = HT[f].parent;
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy_s(HC[i], strlen(&cd[start]) + 1,&cd[start]);
		cout << "第" << i << "个元素的哈福曼编码是：" <<HC[i]<<endl;
	}
	free(cd);

	return 0;
}