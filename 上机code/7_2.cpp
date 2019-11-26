#include<iostream>
#include<fstream>
using namespace std;

#define MAX_VERTEX_NUM 20//最大顶点个数

typedef struct {
	char vexs[MAX_VERTEX_NUM];//顶点向量	
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵	
	int vexnum, arcnum;
	//图的种类为带权有向图，顶点为单个字符，-1代表弧不存在
}MGraph;

int FindVexs(MGraph* M, char a) {
	for (int i = 0; i < M->vexnum; i++) {
		if (M->vexs[i] == a) {
			return i;
		}
	}
	return -1;
}

int main() {
	ifstream start;
	start.open("start.txt", ios::in);
	if (!start.is_open()) {
		cout << "\n文件打开失败\n";
		exit(1);
	}
	MGraph* M = (MGraph*)malloc(sizeof(MGraph));
	M->vexnum = 0;
	M->arcnum = 0;
	//文件第一行是顶点信息
	char now;
	now = start.get();
	int n = 0;
	while (now != '\n') {
		if (now != '\t') {
			M->vexs[n] = now;
			n++;
			M->vexnum++;
		}
		now = start.get();
	}
	//文件之后是邻接矩阵
	int info;
	int i, j;
	while (!start.eof()) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				start >> M->arcs[i][j];
				if (M->arcs[i][j] != -1) {
					M->arcnum++;
				}
			}
		}
	}
	//Dijkstra===========================================================
	cout << "输入要求的顶点：" << endl;
	char s1;
	int i1;
	cin >> s1;
	i1 = FindVexs(M, s1);
	if (i1 == -1) {
		cout << "\n输入顶点不存在\n";
		exit(1);
	}
	int D[MAX_VERTEX_NUM] ;
	bool final_[MAX_VERTEX_NUM];
	bool P[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	//初始化
	for (i = 0; i < M->vexnum; i++) {
		D[i] = M->arcs[i1][i];
		final_[i] = false;
		for (j = 0; j < M->vexnum; j++) {
			P[i][j] = false;
		}
		if (D[i] != -1) {
			P[i][i1] = true;
			P[i][i] = true;
		}
	}
	D[i1] = 0; final_[i1] = 0;
	int v=0, w=0;
	int min = -1;
	int f;
	for (i = 1; i < M->vexnum; i++) {
		min = -1;
		for (w = 0; w < M->vexnum; w++) {
			if (!final_[w]) {
				if (D[w] != -1 && D[w] < min) {
					v = w; min = D[w];
				}
			}
		}
		final_[v] = true;
		for (w = 0; w < M->vexnum; w++) {
			if (!final_[w] && min != -1 && M->arcs[v][w] != -1 && (D[w] == -1 || min + M->arcs[v][w] < D[w])) {
				D[w] = min + M->arcs[v][w];
				for (f = 0; f < MAX_VERTEX_NUM; f++) {
					P[w][f] = P[v][f];
				}
				P[w][w] = true;
			}
		}
	}

	for (i = 0; i < n; i++) {
		cout << s1 << "-->" << M->vexs[i] << "：";
		for (j = 0; j < n; j++) {
			if (P[i][j]) {
				cout << M->vexs[j] << ' ';
			}
		}
		cout << endl;
	}
	
	free(M);
	start.close();
	return 0;
}
