#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;

typedef char TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
BiTree Tempty = (BiTree)malloc(sizeof(BiTNode));//�����߼��ϱ�ʾ���ؽڵ�Ϊ��

queue<BiTree> TQueue;
stack<BiTree> TStack;

//�ڵ�dataΪ0�Ļ������ڵ�Ϊ��
//�����ж�
bool BiTreeEmpty(BiTree T) {
	return (T == NULL || T->data == 0);
}
//����յĶ�����
BiTree InitBiTree() {
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	T->data = 0;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}
//���ٶ������������ݹ飩
void DestroyBiTree(BiTree T) {
	if (T) {
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
	}
}
//���������������ݹ飩
TElemType* CreateBiTree(BiTree T,TElemType* ch) {
	if (*ch == ' ' || *ch == 0) { 
		ch++; 
	    return ch; 
	}
	else {
		T->data = *ch;
		ch++;
		if(T->lchild==NULL) T->lchild = InitBiTree();
		ch=CreateBiTree(T->lchild, ch);
		if(T->rchild==NULL) T->rchild = InitBiTree();
		ch=CreateBiTree(T->rchild, ch);
	}
	return ch;
}
//�����������ݹ飩
void ClearBiTree(BiTree T) {
	if (!BiTreeEmpty(T)) {
		ClearBiTree(T->lchild);
		T->data = 0;
		ClearBiTree(T->rchild);
	}
}
//����������ȣ�����ݹ飩
int BiTreeDepth(BiTree T) {
	int l, r;
	if (BiTreeEmpty(T)) {
		return 0;
	}
	else {
		l = BiTreeDepth(T->lchild);
		r = BiTreeDepth(T->rchild);
		return (l > r) ? (l + 1) : (r + 1);
	}
}
//�������ĸ�
BiTNode Root(BiTree T) {
	return *T;
}
//���ؽڵ�ֵ
TElemType Value(BiTree T, BiTNode e) {
	BiTree Tp;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//���׳��бȽ�
		if (Tp==&e) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//��ն���
			return Tp->data;//���ؽڵ�ֵ
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return 0;//�ڵ㲻���ڻ���Ϊ��
}
//���ڵ㸳ֵ
bool Assign(BiTree T, BiTNode e,TElemType value) {
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//���׳��бȽ�
		if (Tp->data == e.data) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//��ն���
			Tp->data = value;
			return true;//��ֵ�ɹ�
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return false;//�ڵ㲻���ڻ���Ϊ��
}
//����˫��
BiTNode Parent(BiTree T, BiTNode e) {
	if (BiTreeEmpty(T)) return *Tempty;
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//���׳��бȽ�
		if (!BiTreeEmpty(Tp->lchild)) {
			if (Tp->lchild->data == e.data) { 
				while (!TQueue.empty()) {
					TQueue.pop();
				}//��ն���
				return *Tp; //����˫�׽ڵ�
			}
			else TQueue.push(Tp->lchild);
		}
		if (!BiTreeEmpty(Tp->rchild)) {
			if (Tp->rchild->data == e.data) {
				while (!TQueue.empty()) {
					TQueue.pop();
				}//��ն���
				return *Tp; //����˫�׽ڵ�
			}
			else TQueue.push(Tp->rchild);
		}
	}
	return *Tempty;
}
//��������
BiTNode LeftChild(BiTree T, BiTNode e) {
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();
		if (Tp->data==e.data) {
			if (!BiTreeEmpty(Tp->lchild)) {
				while (!TQueue.empty()) {
					TQueue.pop();
				}//��ն���
				return *(Tp->lchild);
			}
			else return *Tempty;
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return *Tempty;
}
//�����Һ���
BiTNode RightChild(BiTree T, BiTNode e) {
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();
		if (Tp->data==e.data) {
			if (!BiTreeEmpty(Tp->rchild)) {
				while (!TQueue.empty()) {
					TQueue.pop();
				}//��ն���
				return *(Tp->rchild);
			}
			else return *Tempty;
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return *Tempty;
}
//�������ֵ�
BiTNode LeftSibling(BiTree T, BiTNode e) {
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();
		if (Tp->rchild->data == e.data) {
			if (!BiTreeEmpty(Tp->lchild)) {
				while (!TQueue.empty()) {
					TQueue.pop();
				}//��ն���
				return *(Tp->lchild);
			}
			else return *Tempty;
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return *Tempty;
}
//�������ֵ�
BiTNode RightSibling(BiTree T, BiTNode e) {
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();
		if (Tp->lchild->data == e.data) {
			if (!BiTreeEmpty(Tp->rchild)) {
				while (!TQueue.empty()) {
					TQueue.pop();
				}//��ն���
				return *(Tp->rchild);
			}
			else return *Tempty;
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return *Tempty;
}
//��������
void InsertChild(BiTree T, BiTNode* p, int LR, BiTree c) {
	if (BiTreeEmpty(T)) return;
	BiTree Tp = T;
	BiTree TT = NULL;
	BiTNode* del = NULL;
	TStack.push(Tp);
	while (!TStack.empty()) {
		Tp = TStack.top();
		TStack.pop();
		if (Tp->data == p->data) {
			if (LR == 0) {
				TT = Tp->lchild;
				Tp->lchild = c;
				del = c->rchild;
				c->rchild = TT;
				DestroyBiTree(del);
				while (!TStack.empty()) {
					TStack.pop();
				}//��ն���
				return;
			}
			if (LR == 1) {
				TT = Tp->rchild;
				Tp->rchild = c;
				del = c->rchild;
				c->rchild = TT;
				DestroyBiTree(del);
				while (!TStack.empty()) {
					TStack.pop();
				}//��ն���
				return;
			}
		}
		if (!BiTreeEmpty(Tp->rchild)) TStack.push(Tp->rchild);
		if (!BiTreeEmpty(Tp->lchild)) TStack.push(Tp->lchild);
	}
}
//ɾ������
void DeleteChild(BiTree T, BiTNode* p, int LR){
	BiTree Tp = T;
	if (LR == 0) {
		ClearBiTree(p->lchild);
	}
	if (LR == 1) {
		ClearBiTree(p->rchild);
	}
}
//visit
void visit(BiTNode e) {
	cout << e.data;
}
//����������ݹ飩
void PreOrderTraverse(BiTree T) {
	if (!BiTreeEmpty(T)) {
		visit(*T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
//����������ݹ飩
void InOrderTraverse(BiTree T) {
	if (!BiTreeEmpty(T)) {
		InOrderTraverse(T->lchild);
		visit(*T);
		InOrderTraverse(T->rchild);
	}
}
//����������ݹ飩
void PostOrderTraverse(BiTree T) {
	if (!BiTreeEmpty(T)) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(*T);
	}
}
//�������
void LevelOrderTraverse(BiTree T) {
	BiTree Tp = T;
	TQueue.push(Tp);
	while (TQueue.size()) {
		Tp = TQueue.front();
		TQueue.pop();
		visit(*Tp);
		if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
		if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
	}
}
//����������ǵݹ飩
void PreOrderTraverseS(BiTree T) {
	if (BiTreeEmpty(T)) return;
	BiTree Tp = T;
	TStack.push(Tp);
	while (!TStack.empty()) {
		Tp=TStack.top();
		TStack.pop();
		visit(*Tp);
		if (!BiTreeEmpty(Tp->rchild)) TStack.push(Tp->rchild);
		if (!BiTreeEmpty(Tp->lchild)) TStack.push(Tp->lchild);
	}
}
//����������ǵݹ飩
void InOrderTraverseS(BiTree T) {
	if (BiTreeEmpty(T)) return;
	BiTree Tp = T;
	bool back=false;
	TStack.push(Tp);
	while (!TStack.empty()) {
		Tp = TStack.top();
		if (!BiTreeEmpty(Tp->lchild)&&!back) {
			TStack.push(Tp->lchild);
		}
		else {
			visit(*Tp);
			TStack.pop();
			if (!BiTreeEmpty(Tp->rchild)) {
				TStack.push(Tp->rchild);
				back = false;
			}
			else {
				back = true;
			}
		}
	}
}
//����������ǵݹ飩
void PostOrderTraverseS(BiTree T) {
	if (BiTreeEmpty(T)) return;
	stack<BiTree> flag;
	BiTree Tp = T;
	TStack.push(Tp);
	while (!TStack.empty()) {
		Tp = TStack.top();
		TStack.pop();
		flag.push(Tp);
		if (!BiTreeEmpty(Tp->lchild)) TStack.push(Tp->lchild);
		if (!BiTreeEmpty(Tp->rchild)) TStack.push(Tp->rchild);
	}
	while (!flag.empty()) {
		Tp = flag.top();
		visit(*Tp);
		flag.pop();
	}
}
//5.3 �Զ�������ÿ��Ԫ��ֵΪx�Ľ�㣬ɾ������Ϊ�������������ͷ���Ӧ�ռ�
void DeleteBiTree(BiTree T, TElemType x) {
	BiTree Tp = T;
	if (T->data == x) {
		DestroyBiTree(T);
		cout << "\n����ȫ��ɾ��\n";
		exit(0);
	}
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//���׳��бȽ�
		if (!BiTreeEmpty(Tp->lchild)&&Tp->lchild->data==x) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//��ն���
			DestroyBiTree(Tp->lchild);
			Tp->lchild = NULL;
			return ;
		}
		if (!BiTreeEmpty(Tp->rchild) && Tp->rchild->data == x) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//��ն���
			DestroyBiTree(Tp->rchild);
			Tp->rchild = NULL;
			return;
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
}
//5.4 �жϸ����Ķ������Ƿ�����ȫ������
bool CompleteBiTree(BiTree T) {
	if (BiTreeEmpty(T)) return true;
	if (BiTreeEmpty(T->lchild) && BiTreeEmpty(T->rchild)) return true;
	if ((BiTreeEmpty(T->lchild) && !BiTreeEmpty(T->rchild)) || (!BiTreeEmpty(T->lchild) && BiTreeEmpty(T->rchild))) return false;
	if (CompleteBiTree(T->lchild) && CompleteBiTree(T->rchild)) return true;
	return false;
}

//����һ��ֵ�󷵻������������������ֵ�Ľڵ�
BiTNode findelem(BiTree T, TElemType x) {
	if (BiTreeEmpty(T)) return *Tempty;
	BiTree Tp = T;
	TStack.push(Tp);
	while (!TStack.empty()) {
		Tp = TStack.top();
		TStack.pop();
		if (Tp->data == x) {
			return *Tp;
		}
		if (!BiTreeEmpty(Tp->rchild)) TStack.push(Tp->rchild);
		if (!BiTreeEmpty(Tp->lchild)) TStack.push(Tp->lchild);
	}
	return *Tempty;
}

int main() {
	int chose = 0;
	TElemType ch1[100] = { 0 };
	TElemType ch2[100] = { 0 };
	Tempty->data = 0;
	Tempty->lchild = NULL;
	Tempty->rchild = NULL;
	BiTNode e = *Tempty;
	BiTNode es = e;
	TElemType x;
	TElemType value;
	int LR;
	cout << "\n====================================================================\n";
	cout << "����1��������������\n��������ֵ����������\n";
	cin >> chose;
	while (getchar() != '\n') continue;
	if (chose == 1) {
		BiTree T1 = InitBiTree();
		BiTree T2 = InitBiTree();
		if (!T1 || !T2) {
			cout << "\n����ռ�ʧ��\n";
			exit(0);
		}
		cout << "\n====================================================================\n";
		cout << "��������ֵ���������������˳�����\n";
		cout << "����1�����򴴽�T1��T2\n";
		cin >> chose;
		while (getchar() != '\n') continue;
        switch (chose) {
		case 1:
			cout << "\nT1��\n";
			cin.get(ch1, 100);
			while (getchar() != '\n') continue;
			CreateBiTree(T1, ch1);
			cout << "\n����T1�ɹ�\n";
			cout << "\nT2��\n";
			cin.get(ch2, 100);
			while (getchar() != '\n') continue;
			CreateBiTree(T2, ch2);
			cout << "\n����T2�ɹ�\n";
			break;
		default:
			DestroyBiTree(T1);
			DestroyBiTree(T2);
			return 0;
		}
		while (chose != 0) {
			cout << "\n====================================================================\n";
			cout << "��������ֵ���������������˳�����\n";
			cout << "����1���ֱ��õݹ�����/����/�������T1T2\n";
			cout << "����2���������T1T2\n";
			cout << "����3���ֱ��÷ǵݹ�����/����/����/����T1T2\n";
			cout << "����4������ֵx,��������T1�е�˫��/���ֵ�/���ֵ�/����/�Һ���\n";
			cout << "����5������T1�����\n";
			cout << "����6������T1���е�ֵ\n";
			cout << "����7������ֵx,ֵvalue,��x��ӦT1�еĽ���ֵ��Ϊvalue\n";
			cout << "����8������ֵx,LR,��T2���뵽x��Ӧ�ڵ����/��������ԭ��/�������滻T2��������\n";
			cout << "����9������ֵx,LR,ɾ��T1�ж�Ӧ�ڵ����/������\n";
			cout << "����10�������T1\n";
			cout << "����11���ж���T1�Ƿ�Ϊ��\n";
			cout << "����12������ֵx��ɾ��T1�ж�Ӧ�ڵ�Ϊ��������\n";
			cout << "����13���ж���T1�Ƿ�Ϊ��ȫ������\n";
			cin >> chose;
			while (getchar() != '\n') continue;
			switch (chose) {
			case 1:
				cout << "\n�ݹ��������T1T2\nT1��";
				PreOrderTraverse(T1);
				cout << "\nT2��";
				PreOrderTraverse(T2);
				cout << "\n�ݹ��������T1T2\nT1��";
				InOrderTraverse(T1);
				cout << "\nT2��";
				InOrderTraverse(T2);
				cout << "\n�ݹ�������T1T2\nT1��";
				PostOrderTraverse(T1);
				cout << "\nT2��";
				PostOrderTraverse(T2);
				break;
			case 2:
				cout << "\n�������T1T2\nT1��";
				LevelOrderTraverse(T1);
				cout << "\nT2��";
				LevelOrderTraverse(T2);
				break;
			case 3:
				cout << "\n�ǵݹ��������T1T2\nT1��";
				PreOrderTraverseS(T1);
				cout << "\nT2��";
				PreOrderTraverseS(T2);
				cout << "\n�ǵݹ��������T1T2\nT1��";
				InOrderTraverseS(T1);
				cout << "\nT2��";
				InOrderTraverseS(T2);
				cout << "\n�ǵݹ�������T1T2\nT1��";
				PostOrderTraverseS(T1);
				cout << "\nT2��";
				PostOrderTraverseS(T2);
				break;
			case 4:
				cout << "\nx��";
				cin >> x;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				cout << "\n˫�ף�";
				es = Parent(T1, e);
				cout << es.data;
				cout << "\n���ֵܣ�";
				es = LeftSibling(T1, e);
				cout << es.data;
				cout << "\n���ֵܣ�";
				es = RightSibling(T1, e);
				cout << es.data;
				cout << "\n���ӣ�";
				es = LeftChild(T1, e);
				cout << es.data;
				cout << "\n�Һ��ӣ�";
				es = RightChild(T1, e);
				cout << es.data;
				break;
			case 5:
				cout << "\nT1�������" << BiTreeDepth(T1) << endl;
				break;
			case 6:
				es = Root(T1);
				cout << "\nT1���е�ֵ�ǣ�" << es.data << endl;
				break;
			case 7:
				cout << "\nx��";
				cin >> x;
				while (getchar() != '\n') continue;
				cout << "\nvalue��";
				cin >> value;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				Assign(T1, e, value);
				cout << "\n�������\n";
				break;
			case 8:
				cout << "\nx��";
				cin >> x;
				while (getchar() != '\n') continue;
				cout << "\nLR��";
				cin >> LR;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				InsertChild(T1, &e, LR, T2);
				cout << "\n�������\n";
				break;
			case 9:
				cout << "\nx��";
				cin >> x;
				while (getchar() != '\n') continue;
				cout << "\nLR��";
				cin >> LR;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				DeleteChild(T1, &e, LR);
				cout << "\n�������\n";
				break;
			case 10:
				ClearBiTree(T1);
				cout << "\n�������\n";
				break;
			case 11:
				if (BiTreeEmpty(T1)) {
					cout << "\nT1Ϊ��\n";
				}
				else {
					cout << "\nT1��Ϊ��\n";
				}
				break;
			case 12:
				cout << "\nx��";
				cin >> x;
				while (getchar() != '\n') continue;
				DeleteBiTree(T1, x);
				cout << "\n�������\n";
				break;
			case 13:
				if (CompleteBiTree(T1)) {
					cout << "\nT1����ȫ������\n";
				}
				else {
					cout << "\nT1������ȫ������\n";
				}
				break;
			default:
				DestroyBiTree(T1);
				DestroyBiTree(T2);
				return 0;
			}
		}
	}

	return 0;
}