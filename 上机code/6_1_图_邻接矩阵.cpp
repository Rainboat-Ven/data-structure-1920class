#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#define INFINITY INT_MAX//���ֵ
#define MAX_VERTEX_NUM 20//��󶥵����

typedef struct {
	char vexs[MAX_VERTEX_NUM];//��������	
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���	
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���	
	//ͼ������Ϊ����Ȩ����ͼ������Ϊ�����ַ����ڽӾ���1�������ڣ�0����������
}MGraph;

//����ͼ
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
//����ͼ
void DestroyGraph(MGraph& G) {
	//������������ֱ�Ӷ���MGraph G;�ʲ�����������
	return;
}
//���ض���λ��
int LocateVex(MGraph G, char u) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == u) {
			return i;
		}
	}
	return -1;
}
//���ض���ֵ
char GetVex(MGraph G, int v) {
	if (v >= G.vexnum) {
		return 0;
	}
	else return G.vexs[v];
}
//�����㸳ֵ
void PutVex(MGraph &G, int v, char value) {
	if (v >= G.vexnum) return;
	else G.vexs[v] = value;
}
//���ص�һ���ڽӶ���
int FirstAdjVex(MGraph G, int v) {
	for (int i = 0; i < G.vexnum; i++) {
		if ((G.arcs[i][v] != 0 || G.arcs[v][i] != 0)&&i!=v) {
			return i;
		}
	}
	return -1;
}
//���������w����һ���ڽӶ���
int NextAdjVex(MGraph G, int v, int w) {
	for (int i = w + 1; i < G.vexnum; i++) {
		if ((G.arcs[i][v] != 0 || G.arcs[v][i] != 0)&&i!=v&&i!=w) {
			return i;
		}
	}
	return -1;
}
//���Ӷ���
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
//ɾ���������ػ�
bool DeleteVex(MGraph& G, int v) {
	if (v >= G.vexnum) {
		return false;
	}
	int i, j;
	//�ƶ�����������
	for (i = v+1; i < G.vexnum; i++) {
		G.vexs[i - 1] = G.vexs[i];
	}
	//�ƶ��ڽӾ���
	for (i = v+1; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[j][i - 1] = G.arcs[j][i];
		}
	}//����
	for (i = v+1; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			G.arcs[i-1][j] = G.arcs[i][j];
		}
	}//����
	//����ͳ�Ƶ����ͻ���
	G.vexnum--;
	G.arcnum = 0;
	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j] == 1) G.arcnum++;
		}
	}
	return true;
}
//���뻡
bool InsertArc(MGraph& G, int v, int w) {
	if (v >= G.vexnum || w >= G.vexnum || v < 0 || w < 0) {
		return false;
	}
	G.arcs[v][w] = 1;
	return true;
}
//ɾ����
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
//������ȱ���
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
//������ȱ���
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
//��ӡ�ڽӾ���
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
    //����ͼ
	cout << "����ͼ�Ķ�������";
	cin >> vex;
	getchar();
	if (vex > MAX_VERTEX_NUM) {
		cout << "\n����������\n";
		exit(1);
	}
	for (i = 0; i < vex; i++) {
		cout << "���붥��V[" << i << "]��";
		cin >> V[i];
		getchar();
	}
	cout << "����ͼ�ı�����";
	cin >> arc;
	getchar();
	if (arc > MAX_VERTEX_NUM* MAX_VERTEX_NUM) {
		cout << "\n��������\n";
		exit(1);
	}
	int vi, vj;
	for (i = 0; i < vex; i++) {
		for (j = 0; j < vex; j++) {
			VR[i][j] = 0;
		}
	}
	for (i = 0; i < arc; i++) {
		cout << "�����"<<i+1<<"���ߵĶ�����vi��vj��"<<endl;
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
		cout << "��������ֵ������ͼ���˳�����\n";
		cout << "����1�����붥�㷵��λ��\n";
		cout << "����2������λ�÷��ض����ֵ\n";
		cout << "����3������λ�ò���ֵ\n";
		cout << "����4�����붥�㷵�ص�һ���ڽӶ���λ��\n";
		cout << "����5�����붥����ڽӶ��㣬������һ���ڽӶ���λ��\n";
		cout << "����6�����Ӷ���\n";
		cout << "����7��ɾ���������ػ�\n";
		cout << "����8����ӻ�\n";
		cout << "����9��ɾ����\n";
		cout << "����10��������ȱ���\n";
		cout << "����11��������ȱ���\n";
		cout << "����12����ӡ�ڽӾ���\n";
		cin >> chose;
		getchar();
		switch (chose){
		case 1:
			cout << "���붥��ֵ��";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			if (v == -1) {
				cout << "\n�ö��㲻����\n";
			}
			else {
				cout << "\n����λ��Ϊ" << v << "\n";
			}
			break;
		case 2:
			cout << "����λ��ֵ��";
			cin >> v;
			getchar();
			u = GetVex(G, v);
			if (u == 0) {
				cout << "\n��λ�ò�����\n";
			}
			else {
				cout << "\n����Ϊ" << u << "\n";
			}
			break;
		case 3:
			cout << "����λ��ֵ��";
			cin >> v;
			getchar();
			cout << "Ҫ����ֵ��";
			cin >> u;
			getchar();
			PutVex(G, v, u);
			cout << "\n�������\n";
			break;
		case 4:
			cout << "���붥��ֵ��";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			v = FirstAdjVex(G, v);
			if (v == -1) {
				cout << "\n�ö��㲻����\n";
			}
			else {
				cout << "\n����λ��Ϊ" << v << "\n";
			}
			break;
		case 5:
			cout << "���붥��ֵ��";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			cout << "�����ڽӶ���ֵ��";
			cin >> uw;
			getchar();
			w = LocateVex(G, u);
			v = NextAdjVex(G, v, w);
			if (v == -1) {
				cout << "\n�ö��㲻����\n";
			}
			else {
				cout << "\n����λ��Ϊ" << v << "\n";
			}
			break;
		case 6:
			cout << "���붥��ֵ��";
			cin >> u;
			getchar();
			if (InsertVex(G, u)) {
				cout << "\n�������\n";
			}
			else {
				cout << "\n����ʧ��\n";
			}
			break;
		case 7:
			cout << "���붥��ֵ��";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			if (DeleteVex(G, v)) {
				cout << "\n�������\n";
			}
			else {
				cout << "\n����ʧ��\n";
			}
			break;
		case 8:
			cout << "���붥��ֵ��";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			cout << "���붥��ֵ��";
			cin >> uw;
			getchar();
			w = LocateVex(G, uw);
			if (InsertArc(G,v,w)) {
				cout << "\n�������\n";
			}
			else {
				cout << "\n����ʧ��\n";
			}
			break;
		case 9:
			cout << "���붥��ֵ��";
			cin >> u;
			getchar();
			v = LocateVex(G, u);
			cout << "���붥��ֵ��";
			cin >> uw;
			getchar();
			w = LocateVex(G, uw);
			if (DeleteArc(G, v, w)) {
				cout << "\n�������\n";
			}
			else {
				cout << "\n����ʧ��\n";
			}
			break;
		case 10:
			cout << "������ȱ�����" << endl;
			DFSTraverse(G);
			break;
		case 11:
			cout << "������ȱ�����" << endl;
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