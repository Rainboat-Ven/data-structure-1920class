#include<iostream>
#include<stack>
using namespace std;

typedef struct CSNode {
	char data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;

void Print(CSTree T,int i) {
	//输出第i层内容等于输出所有兄弟的第i层和子树的第i-1层内容
	//若i=1,输出自己
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
	cout << "输入根结点：";
	CSTree T = (CSTree)malloc(sizeof(CSNode));
	CSTree p = T;
	cin >> T->data;
	getchar();
	//创建其它结点
	stack<CSTree> TStack;
	TStack.push(p);
	char now;
	while (!TStack.empty()) {
		p = TStack.top();
		TStack.pop();
		//
		cout << "输入" << p->data << "的第一个孩子(空格表示无)：";
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
		cout << "输入" << p->data << "的下一个兄弟(空格表示无)：";
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
	//输出第i层内容
	int i=1;
	while (i != 0) {
		cout << "输入要输出的层数(输入0退出)：";
		cin >> i;
		if (i == 0) break;
		getchar();

		Print(T, i);
		cout << endl;
	}
	//销毁树
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