#include<iostream>
using namespace std;

typedef struct BinarySortNode {
	int data;
	struct BinarySortNode* small, *big;
}BinarySortNode,*BinarySortTree;

//查找
bool SearchBST(BinarySortTree T, int key,BinarySortTree f,BinarySortTree&p) {
	if (!T) {
		p = f;
		return false;
	}
	else if (key == T->data) {
		p = T;
		return true;
	}
	else if (key < T->data) {
		return SearchBST(T->small, key, T, p);
	}
	else {
		return SearchBST(T->big, key, T, p);
	}
}
//插入
bool InsertBST(BinarySortTree& T, int num) {
	BinarySortTree p;
	if (!SearchBST(T, num, NULL, p)) {
		BinarySortTree s = (BinarySortTree)malloc(sizeof(BinarySortNode));
		s->data = num;
		s->small = NULL;
		s->big = NULL;
		if (!p) T = s;
		else if (num < p->data) {
			p->small = s;
		}
		else {
			p->big = s;
		}
		return true;
	}
	else {
		return false;
	}
}
//删除
bool Delete(BinarySortTree& p) {
	BinarySortTree q;
	if (!p->big) {
		q = p;
		p = p->small;
		free(q);
	}
	else if (!p->small) {
		q = p;
		p = p->big;
		free(q);
	}
	else {
		q = p;
		BinarySortTree s = p->small;
		while (s->big) {
			q = s;
			s = s->big;
		}
		p->data = s->data;
		if (q != p) {
			q->big = s->small;
		}
		else {
			q->small = s->small;
		}
		free(s);
	}
	return true;
}
bool DeletNode(BinarySortTree& T, int num) {
	if (!T) return false;
	else {
		if (num == T->data) {
			return Delete(T);
		}
		else if (num < T->data) {
			return DeletNode(T->small, num);
		}
		else {
			return DeletNode(T->big, num);
		}
	}
}
//中序遍历
void printf(BinarySortTree T) {
	if (T) {
		printf(T->small);
		cout << T->data << ' ';
		printf(T->big);
	}
	else {
		cout << ' ';
	}
}
//后续销毁
void DestroyBST(BinarySortTree& T) {
	if (T) {
		DestroyBST(T->small);
		DestroyBST(T->big);
		free(T);
	}
}

int main() {
	BinarySortTree T = NULL;
	cout << "输入初始数据量：";
	int n;
	cin >> n;
	cout << "依次输入数据构造初始二叉排序树：" << endl;
	int num;
	while (n) {
		cin >> num;
		InsertBST(T, num);
		n--;
	}
	n = 1;
	while (n) {
		cout << "\n================================================" << endl;
		cout << "当前二叉排序树的中序遍历是：";
		printf(T);
		cout << "\n输入1：插入";
		cout << "\n输入2：删除";
		cout << "\n输入其它值：销毁二叉树并退出";
		cout << "\n\n输入：";
		cin >> n;
		switch (n){
		case 1:
			cout << "要插入的值是：";
			cin >> num;
			if (InsertBST(T,num)) {
				cout << "\n插入成功";
			}
			else {
				cout << "\n插入失败";
			}
			break;
		case 2:
			cout << "要删除的值是：";
			cin >> num;
			if (DeletNode(T, num)) {
				cout << "\n删除成功";
			}
			else {
				cout << "\n删除失败";
			}
			break;
		default:
			DestroyBST(T);
			return 0;
			break;
		}
	}
	
	return 0;
}