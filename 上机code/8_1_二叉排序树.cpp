#include<iostream>
using namespace std;

typedef struct BinarySortNode {
	int data;
	struct BinarySortNode* small, *big;
}BinarySortNode,*BinarySortTree;

//����
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
//����
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
//ɾ��
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
//�������
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
//��������
void DestroyBST(BinarySortTree& T) {
	if (T) {
		DestroyBST(T->small);
		DestroyBST(T->big);
		free(T);
	}
}

int main() {
	BinarySortTree T = NULL;
	cout << "�����ʼ��������";
	int n;
	cin >> n;
	cout << "�����������ݹ����ʼ������������" << endl;
	int num;
	while (n) {
		cin >> num;
		InsertBST(T, num);
		n--;
	}
	n = 1;
	while (n) {
		cout << "\n================================================" << endl;
		cout << "��ǰ��������������������ǣ�";
		printf(T);
		cout << "\n����1������";
		cout << "\n����2��ɾ��";
		cout << "\n��������ֵ�����ٶ��������˳�";
		cout << "\n\n���룺";
		cin >> n;
		switch (n){
		case 1:
			cout << "Ҫ�����ֵ�ǣ�";
			cin >> num;
			if (InsertBST(T,num)) {
				cout << "\n����ɹ�";
			}
			else {
				cout << "\n����ʧ��";
			}
			break;
		case 2:
			cout << "Ҫɾ����ֵ�ǣ�";
			cin >> num;
			if (DeletNode(T, num)) {
				cout << "\nɾ���ɹ�";
			}
			else {
				cout << "\nɾ��ʧ��";
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