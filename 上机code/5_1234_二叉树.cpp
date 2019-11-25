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
BiTree Tempty = (BiTree)malloc(sizeof(BiTNode));//用于逻辑上表示返回节点为空

queue<BiTree> TQueue;
stack<BiTree> TStack;

//节点data为0的话视作节点为空
//空树判断
bool BiTreeEmpty(BiTree T) {
	return (T == NULL || T->data == 0);
}
//构造空的二叉树
BiTree InitBiTree() {
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	T->data = 0;
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}
//销毁二叉树（后续递归）
void DestroyBiTree(BiTree T) {
	if (T) {
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
	}
}
//构造二叉树（先序递归）
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
//清空树（中序递归）
void ClearBiTree(BiTree T) {
	if (!BiTreeEmpty(T)) {
		ClearBiTree(T->lchild);
		T->data = 0;
		ClearBiTree(T->rchild);
	}
}
//返回树的深度（后序递归）
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
//返回树的根
BiTNode Root(BiTree T) {
	return *T;
}
//返回节点值
TElemType Value(BiTree T, BiTNode e) {
	BiTree Tp;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//队首出列比较
		if (Tp==&e) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//清空队列
			return Tp->data;//返回节点值
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return 0;//节点不存在或者为空
}
//给节点赋值
bool Assign(BiTree T, BiTNode e,TElemType value) {
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//队首出列比较
		if (Tp->data == e.data) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//清空队列
			Tp->data = value;
			return true;//赋值成功
		}
		else {
			if (!BiTreeEmpty(Tp->lchild)) TQueue.push(Tp->lchild);
			if (!BiTreeEmpty(Tp->rchild)) TQueue.push(Tp->rchild);
		}
	}
	return false;//节点不存在或者为空
}
//返回双亲
BiTNode Parent(BiTree T, BiTNode e) {
	if (BiTreeEmpty(T)) return *Tempty;
	BiTree Tp = T;
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//队首出列比较
		if (!BiTreeEmpty(Tp->lchild)) {
			if (Tp->lchild->data == e.data) { 
				while (!TQueue.empty()) {
					TQueue.pop();
				}//清空队列
				return *Tp; //返回双亲节点
			}
			else TQueue.push(Tp->lchild);
		}
		if (!BiTreeEmpty(Tp->rchild)) {
			if (Tp->rchild->data == e.data) {
				while (!TQueue.empty()) {
					TQueue.pop();
				}//清空队列
				return *Tp; //返回双亲节点
			}
			else TQueue.push(Tp->rchild);
		}
	}
	return *Tempty;
}
//返回左孩子
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
				}//清空队列
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
//返回右孩子
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
				}//清空队列
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
//返回左兄弟
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
				}//清空队列
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
//返回右兄弟
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
				}//清空队列
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
//插入子树
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
				}//清空队列
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
				}//清空队列
				return;
			}
		}
		if (!BiTreeEmpty(Tp->rchild)) TStack.push(Tp->rchild);
		if (!BiTreeEmpty(Tp->lchild)) TStack.push(Tp->lchild);
	}
}
//删除子树
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
//先序遍历（递归）
void PreOrderTraverse(BiTree T) {
	if (!BiTreeEmpty(T)) {
		visit(*T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
//中序遍历（递归）
void InOrderTraverse(BiTree T) {
	if (!BiTreeEmpty(T)) {
		InOrderTraverse(T->lchild);
		visit(*T);
		InOrderTraverse(T->rchild);
	}
}
//后序遍历（递归）
void PostOrderTraverse(BiTree T) {
	if (!BiTreeEmpty(T)) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(*T);
	}
}
//层序遍历
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
//先序遍历（非递归）
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
//中序遍历（非递归）
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
//后序遍历（非递归）
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
//5.3 对二叉树中每个元素值为x的结点，删除以它为根的子树，并释放相应空间
void DeleteBiTree(BiTree T, TElemType x) {
	BiTree Tp = T;
	if (T->data == x) {
		DestroyBiTree(T);
		cout << "\n树完全被删除\n";
		exit(0);
	}
	TQueue.push(Tp);
	while (!TQueue.empty()) {
		Tp = TQueue.front();
		TQueue.pop();//队首出列比较
		if (!BiTreeEmpty(Tp->lchild)&&Tp->lchild->data==x) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//清空队列
			DestroyBiTree(Tp->lchild);
			Tp->lchild = NULL;
			return ;
		}
		if (!BiTreeEmpty(Tp->rchild) && Tp->rchild->data == x) {
			while (!TQueue.empty()) {
				TQueue.pop();
			}//清空队列
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
//5.4 判断给定的二叉树是否是完全二叉树
bool CompleteBiTree(BiTree T) {
	if (BiTreeEmpty(T)) return true;
	if (BiTreeEmpty(T->lchild) && BiTreeEmpty(T->rchild)) return true;
	if ((BiTreeEmpty(T->lchild) && !BiTreeEmpty(T->rchild)) || (!BiTreeEmpty(T->lchild) && BiTreeEmpty(T->rchild))) return false;
	if (CompleteBiTree(T->lchild) && CompleteBiTree(T->rchild)) return true;
	return false;
}

//给定一个值后返回先序遍历最早存有这个值的节点
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
	cout << "输入1：创建两个空树\n输入其它值：结束程序\n";
	cin >> chose;
	while (getchar() != '\n') continue;
	if (chose == 1) {
		BiTree T1 = InitBiTree();
		BiTree T2 = InitBiTree();
		if (!T1 || !T2) {
			cout << "\n分配空间失败\n";
			exit(0);
		}
		cout << "\n====================================================================\n";
		cout << "输入其它值：销毁两个树并退出程序\n";
		cout << "输入1：先序创建T1和T2\n";
		cin >> chose;
		while (getchar() != '\n') continue;
        switch (chose) {
		case 1:
			cout << "\nT1：\n";
			cin.get(ch1, 100);
			while (getchar() != '\n') continue;
			CreateBiTree(T1, ch1);
			cout << "\n创建T1成功\n";
			cout << "\nT2：\n";
			cin.get(ch2, 100);
			while (getchar() != '\n') continue;
			CreateBiTree(T2, ch2);
			cout << "\n创建T2成功\n";
			break;
		default:
			DestroyBiTree(T1);
			DestroyBiTree(T2);
			return 0;
		}
		while (chose != 0) {
			cout << "\n====================================================================\n";
			cout << "输入其它值：销毁两个树并退出程序\n";
			cout << "输入1：分别用递归先序/中序/后序遍历T1T2\n";
			cout << "输入2：层序遍历T1T2\n";
			cout << "输入3：分别用非递归先序/中序/后序/遍历T1T2\n";
			cout << "输入4：输入值x,返回它在T1中的双亲/左兄弟/右兄弟/左孩子/右孩子\n";
			cout << "输入5：返回T1的深度\n";
			cout << "输入6：返回T1根中的值\n";
			cout << "输入7：输入值x,值value,将x对应T1中的结点的值改为value\n";
			cout << "输入8：输入值x,LR,将T2插入到x对应节点的左/右子树，原左/右子树替换T2的右子树\n";
			cout << "输入9：输入值x,LR,删除T1中对应节点的左/右子树\n";
			cout << "输入10：清空树T1\n";
			cout << "输入11：判断树T1是否为空\n";
			cout << "输入12：输入值x，删除T1中对应节点为根的子树\n";
			cout << "输入13：判断树T1是否为完全二叉树\n";
			cin >> chose;
			while (getchar() != '\n') continue;
			switch (chose) {
			case 1:
				cout << "\n递归先序遍历T1T2\nT1：";
				PreOrderTraverse(T1);
				cout << "\nT2：";
				PreOrderTraverse(T2);
				cout << "\n递归中序遍历T1T2\nT1：";
				InOrderTraverse(T1);
				cout << "\nT2：";
				InOrderTraverse(T2);
				cout << "\n递归后序遍历T1T2\nT1：";
				PostOrderTraverse(T1);
				cout << "\nT2：";
				PostOrderTraverse(T2);
				break;
			case 2:
				cout << "\n层序遍历T1T2\nT1：";
				LevelOrderTraverse(T1);
				cout << "\nT2：";
				LevelOrderTraverse(T2);
				break;
			case 3:
				cout << "\n非递归先序遍历T1T2\nT1：";
				PreOrderTraverseS(T1);
				cout << "\nT2：";
				PreOrderTraverseS(T2);
				cout << "\n非递归中序遍历T1T2\nT1：";
				InOrderTraverseS(T1);
				cout << "\nT2：";
				InOrderTraverseS(T2);
				cout << "\n非递归后序遍历T1T2\nT1：";
				PostOrderTraverseS(T1);
				cout << "\nT2：";
				PostOrderTraverseS(T2);
				break;
			case 4:
				cout << "\nx：";
				cin >> x;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				cout << "\n双亲：";
				es = Parent(T1, e);
				cout << es.data;
				cout << "\n左兄弟：";
				es = LeftSibling(T1, e);
				cout << es.data;
				cout << "\n右兄弟：";
				es = RightSibling(T1, e);
				cout << es.data;
				cout << "\n左孩子：";
				es = LeftChild(T1, e);
				cout << es.data;
				cout << "\n右孩子：";
				es = RightChild(T1, e);
				cout << es.data;
				break;
			case 5:
				cout << "\nT1的深度是" << BiTreeDepth(T1) << endl;
				break;
			case 6:
				es = Root(T1);
				cout << "\nT1根中的值是：" << es.data << endl;
				break;
			case 7:
				cout << "\nx：";
				cin >> x;
				while (getchar() != '\n') continue;
				cout << "\nvalue：";
				cin >> value;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				Assign(T1, e, value);
				cout << "\n操作完成\n";
				break;
			case 8:
				cout << "\nx：";
				cin >> x;
				while (getchar() != '\n') continue;
				cout << "\nLR：";
				cin >> LR;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				InsertChild(T1, &e, LR, T2);
				cout << "\n操作完成\n";
				break;
			case 9:
				cout << "\nx：";
				cin >> x;
				while (getchar() != '\n') continue;
				cout << "\nLR：";
				cin >> LR;
				while (getchar() != '\n') continue;
				e = findelem(T1, x);
				DeleteChild(T1, &e, LR);
				cout << "\n操作完成\n";
				break;
			case 10:
				ClearBiTree(T1);
				cout << "\n操作完成\n";
				break;
			case 11:
				if (BiTreeEmpty(T1)) {
					cout << "\nT1为空\n";
				}
				else {
					cout << "\nT1不为空\n";
				}
				break;
			case 12:
				cout << "\nx：";
				cin >> x;
				while (getchar() != '\n') continue;
				DeleteBiTree(T1, x);
				cout << "\n操作完成\n";
				break;
			case 13:
				if (CompleteBiTree(T1)) {
					cout << "\nT1是完全二叉树\n";
				}
				else {
					cout << "\nT1不是完全二叉树\n";
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