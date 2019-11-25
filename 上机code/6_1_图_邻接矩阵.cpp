#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#define INFINITY INT_MAX//最大值
#define MAX_VERTEX_NUM 20//最大顶点个数

typedef struct {
	char vexs[MAX_VERTEX_NUM];//顶点向量	
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵	
	int vexnum, arcnum;//图的当前顶点数和弧数	
	//图的种类为不带权有向图，顶点为单个字符，邻接矩阵1代表弧存在，0代表弧不存在
}MGraph;

//创建图
void CreatGraph(MGraph& G,char V[],int VR[][MAX_VERTEX_NUM]) {
	G.vexnum = 0;
	G.arcnum = 0;
	while (V[G.vexnum] != 0) {
		G.vexs[G.vexnum] = V[G.vexnum];
		G.vexnum++;
	}
	int i, j;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = VR[i][j];
			if (VR[i][j] != INFINITY) {
				G.arcnum++;
			}
		}
	}
}
//销毁图
void DestroyGraph(MGraph& G) {
	//由于主函数中直接定义MGraph G;故不用主动销毁
	return;
}
//返回顶点位置
int LocateVex(MGraph G, char u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == u) {
			return i;
		}
	}
	return -1;
}
//返回顶点值
char GetVex(MGraph G, int v) {
	if (v >= G.vexnum) {
		return 0;
	}
	else return G.vexs[v];
}
//给顶点赋值
void PutVex(MGraph &G, int v, char value) {
	if (v >= G.vexnum) return;
	else G.vexs[v] = value;
}
//返回第一个邻接顶点
int FirstAdjVex(MGraph G, int v) {
	for (int i = 0; i < G.vexnum; i++) {
		if ((G.arcs[i][v] != 0 || G.arcs[v][i] != 0)&&i!=v) {
			return i;
		}
	}
	return -1;
}
//返回相对于w的下一个邻接顶点
int NextAdjVex(MGraph G, int v, int w) {
	for (int i = w + 1; i < G.vexnum; i++) {
		if ((G.arcs[i][v] != 0 || G.arcs[v][i] != 0)&&i!=v&&i!=w) {
			return i;
		}
	}
	return -1;
}
//增加顶点
bool InsertVex(MGraph& G, char v) {
	if (G.vexnum >= MAX_VERTEX_NUM) {
		return false;
	}
	G.vexs[G.vexnum] = v;
	for (int i = 0; i <= G.vexnum; i++) {
		G.arcs[G.vexnum][i] = 0;
		G.arcs[i][G.vexnum] = 0;
	}
	G.vexnum++;

	return true;
}
//删除顶点和相关弧
bool DeleteVex(MGraph& G, int v) {
	if (v >= G.vexnum) {
		return false;
	}
	int i, j;
	//移动其它顶点编号
	for (i = v+1; i < G.vexnum; i++) {
		G.vexs[i - 1] = G.vexs[i];
	}
	//移动邻接矩阵
	for (i = v+1; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[j][i - 1] = G.arcs[j][i];
		}
	}//左移
	for (i = v+1; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i-1][j] = G.arcs[i][j];
		}
	}//上移
	//重新统计点数和弧数
	G.vexnum--;
	G.arcnum = 0;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] == 1) G.arcnum++;
		}
	}
	return true;
}
//插入弧
bool InsertArc(MGraph& G, int v, int w) {
	if (v >= G.vexnum || w >= G.vexnum || v < 0 || w < 0) {
		return false;
	}
	G.arcs[v][w] = 1;
	return true;
}
//删除弧
bool DeleteArc(MGraph& G, int v, int w) {
	if (v >= G.vexnum || w >= G.vexnum || v < 0 || w < 0) {
		return false;
	}
	G.arcs[v][w] = 0;
	return true;
}
//visit
void visit(char v) {
	cout << v;
}
//深度优先遍历
void DFSTraverse(MGraph G) {
	stack<int> Vstack;
	int now;
	int flag[MAX_VERTEX_NUM] = { 0 };
	for (int i = 0; i < G.vexnum; i++) {
		if (!flag[i]) {
			Vstack.push(i);
			while (!Vstack.empty()) {
				now = Vstack.top();
				Vstack.pop();
				if (!flag[now]) {
					visit(G.vexs[now]);
					flag[now] = 1;
				}
				for (int j = 0; j < G.vexnum; j++) {
					if (G.arcs[now][j]&&!flag[j]) {
						Vstack.push(j);
					}
				}
			}
		}
		cout << endl;
	}
}
//广度优先遍历
void BFSTraverse(MGraph G) {
	queue<int> Vstack;
	int now;
	int flag[MAX_VERTEX_NUM] = { 0 };
	for (int i = 0; i < G.vexnum; i++) {
		if (!flag[i]) {
			Vstack.push(i);
			while (!Vstack.empty()) {
				now = Vstack.front();
				Vstack.pop();
				if (!flag[now]) {
					visit(G.vexs[now]);
					flag[now] = 1;
				}
				for (int j = 0; j < G.vexnum; j++) {
					if (G.arcs[now][j] && !flag[j]) {
						Vstack.push(j);
					}
				}
			}
		}
		cout << endl;
	}
}
//打印邻接矩阵
void PrintArcs(MGraph G) {
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			cout << G.arcs[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	char V[MAX_VERTEX_NUM] = {0};
	int VR[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {0};
	int vex, arc;
	int i, j;
    //创建图
	cout << "输入图的顶点数：";
	cin >> vex;
	getchar();
	if (vex > MAX_VERTEX_NUM) {
		cout << "\n顶点数过大\n";
		exit(1);
	}
	for (i = 0; i < vex; i++) {
		cout << "输入顶点V[" << i << "]：";
		cin >> V[i];
		getchar();
	}
	cout << "输入图的边数：";
	cin >> arc;
	getchar();
	if (arc > MAX_VERTEX_NUM* MAX_VERTEX_NUM) {
		cout << "\n边数过大\n";
		exit(1);
	}
	int vi, vj;
	for (i = 0; i < vex; i++) {
		for (j = 0; j < vex; j++) {
			VR[i][j] = 0;
		}
	}
	for (i = 0; i < arc; i++) {
		cout << "输入第"<<i+1<<"条边的顶点编号vi，vj："<<endl;
		cin >> vi;
		cin >> vj;
		getchar();
		VR[vi][vj] = 1;
	}
	MGraph G;
	CreatGraph(G, V, VR);
	getchar();
	int chose=1;
	char u;
	int v;
	char uw;
	int w;
	while (chose) {
		cout << "\n====================================================================\n";
		cout << "输入其它值：销毁图并退出程序\n";
		cout << "输入1：输入顶点返回位置\n";
		cout << "输入2：输入位置返回顶点的值\n";
		cout << "输入3：输入位置并赋值\n";
		cout << "输入4：输入顶点返回第一个邻接顶点位置\n";
		cout << "输入5：输入顶点和邻接顶点，返回下一个邻接顶点位置\n";
		cout << "输入6：增加顶点\n";
		cout << "输入7：删除顶点和相关弧\n";
		cout << "输入8：添加弧\n";
		cout << "输入9：删除弧\n";
		cout << "输入10：深度优先遍历\n";
		cout << "输入11：广度优先遍历\n";
		cout << "输入12：打印邻接矩阵\n";
		cin >> chose;
		getchar();
		switch (chose){
		case 1:
			cout << "输入顶点值：";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			if (v == -1) {
				cout << "\n该顶点不存在\n";
			}
			else {
				cout << "\n顶点位置为" << v << "\n";
			}
			break;
		case 2:
			cout << "输入位置值：";
			cin >> v;
			getchar();
			u = GetVex(G, v);
			if (u == 0) {
				cout << "\n该位置不存在\n";
			}
			else {
				cout << "\n顶点为" << u << "\n";
			}
			break;
		case 3:
			cout << "输入位置值：";
			cin >> v;
			getchar();
			cout << "要赋的值：";
			cin >> u;
			getchar();
			PutVex(G, v, u);
			cout << "\n操作完成\n";
			break;
		case 4:
			cout << "输入顶点值：";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			v = FirstAdjVex(G, v);
			if (v == -1) {
				cout << "\n该顶点不存在\n";
			}
			else {
				cout << "\n顶点位置为" << v << "\n";
			}
			break;
		case 5:
			cout << "输入顶点值：";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			cout << "输入邻接顶点值：";
			cin >> uw;
			getchar();
			w = LocateVex(G, u);
			v = NextAdjVex(G, v, w);
			if (v == -1) {
				cout << "\n该顶点不存在\n";
			}
			else {
				cout << "\n顶点位置为" << v << "\n";
			}
			break;
		case 6:
			cout << "输入顶点值：";
			cin >> u;
			getchar();
			if (InsertVex(G, u)) {
				cout << "\n操作完成\n";
			}
			else {
				cout << "\n操作失败\n";
			}
			break;
		case 7:
			cout << "输入顶点值：";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			if (DeleteVex(G, v)) {
				cout << "\n操作完成\n";
			}
			else {
				cout << "\n操作失败\n";
			}
			break;
		case 8:
			cout << "输入顶点值：";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			cout << "输入顶点值：";
			cin >> uw;
			getchar();
			w = LocateVex(G, uw);
			if (InsertArc(G,v,w)) {
				cout << "\n操作完成\n";
			}
			else {
				cout << "\n操作失败\n";
			}
			break;
		case 9:
			cout << "输入顶点值：";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			cout << "输入顶点值：";
			cin >> uw;
			getchar();
			w = LocateVex(G, uw);
			if (DeleteArc(G, v, w)) {
				cout << "\n操作完成\n";
			}
			else {
				cout << "\n操作失败\n";
			}
			break;
		case 10:
			cout << "深度优先遍历：" << endl;
			DFSTraverse(G);
			break;
		case 11:
			cout << "广度优先遍历：" << endl;
			BFSTraverse(G);
			break;
		case 12:
			PrintArcs(G);
			break;
		default:
			DestroyGraph(G);
			return 0;
		}
	}

	


	return 0;
}