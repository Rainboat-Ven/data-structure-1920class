#include<iostream>
#include<stack>
using namespace std;

typedef struct CSNode {
	char data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;

void Print(CSTree T,int i) {
	//�����i�����ݵ�����������ֵܵĵ�i��������ĵ�i-1������
	//��i=1,����Լ�
	CSTree next = T->nextsibling;
	if (i == 1) {
		cout << T->data << " ";
		if (next) {
			Print(next, i );
		}
	}
	else {
		next = T->firstchild;
		if (next) {
			Print(next, i - 1);
		}
		next = T->nextsibling;
		if (next) {
			Print(next, i);
		}
	}
}

int main() {
	cout << "�������㣺";
	CSTree T = (CSTree)malloc(sizeof(CSNode));
	CSTree p = T;
	cin >> T->data;
	getchar();
	//�����������
	stack<CSTree> TStack;
	TStack.push(p);
	char now;
	while (!TStack.empty()) {
		p = TStack.top();
		TStack.pop();
		//
		cout << "����" << p->data << "�ĵ�һ������(�ո��ʾ��)��";
		now=getchar();
		getchar();
		if (now != ' ') {
			p->firstchild= (CSTree)malloc(sizeof(CSNode));
			p->firstchild->data = now;
			TStack.push(p->firstchild);
		}
		else {
			p->firstchild = NULL;
		}
		cout << "����" << p->data << "����һ���ֵ�(�ո��ʾ��)��";
		now = getchar();
		getchar();
		if (now != ' ') {
			p->nextsibling = (CSTree)malloc(sizeof(CSNode));
			p->nextsibling->data = now;
			TStack.push(p->nextsibling);
		}
		else {
			p->nextsibling = NULL;
		}
	}
	//�����i������
	int i=1;
	while (i != 0) {
		cout << "����Ҫ����Ĳ���(����0�˳�)��";
		cin >> i;
		if (i == 0) break;
		getchar();

		Print(T, i);
		cout << endl;
	}
	//������
	p = T;
	TStack.push(p);
	while (!TStack.empty()) {
		p = TStack.top();
		TStack.pop();
		//
		if (p->firstchild) TStack.push(p->firstchild);
		if (p->nextsibling) TStack.push(p->nextsibling);
		free(p);
	}

	return 0;
}