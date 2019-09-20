// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Tree.h"
#define M 30

typedef struct node {
	int data;
	struct node *lchild, *rchild;
}BTnode, *BTree;

void visit(BTree b) {
	
}
//	遍历二叉树的递归算法：前，中，后序遍历
void preorder(BTree b) {
	if (b != NULL) {
		visit(b);
		preorder(b->lchild);
		preorder(b->rchild);
	}
}
void inorder(BTree b) {
	if (b != NULL) {
		inorder(b->lchild);
		visit(b);
		inorder(b->rchild);
	}
}
void postorder(BTree b) {
	if (b != NULL) {
		postorder(b->lchild);
		postorder(b->rchild);
		visit(b);
	}
}
//	遍历二叉树的非递归算法：层次，前，中，后遍历
//	层次遍历利用队列的性质，先进先出
void layerorder(BTree b) {
	BTree queue[M] = {NULL};
	BTree q = b;
	int front = -1, rear = -1;
	if (q != NULL) {
		queue[++rear] = q;
		do {
			q = queue[++front];
			visit(q);
			if (q->lchild != NULL)queue[++rear] = q->lchild;
			if (q->rchild != NULL)queue[++rear] = q->rchild;
		} while (front < rear);
	}
}
void preorder2(BTree b) {
	BTree stack[M] = {NULL};
	int top = -1;
	BTree p = b;
	if (p != NULL) {
		do {
			while (p != NULL) {
				visit(p);
				stack[++top] = p;
				p = p->lchild;
			}
			p = stack[top--];
			p = p->rchild;
		} while (!(p == NULL && top == -1));
	}
}
void inorder2(BTree b) {
	BTree stack[M] = { NULL }, p = b;
	int top = -1;//	LinkList top = NULL;
	if (p != NULL) {
		do {
			while (p != NULL) {
				stack[++top] = p;//	q = (Btree)malloc(sizeof(BTnode)); q->data = p; q->link = top; top = p;
				p = p->lchild;
			}
			p = stack[top--];//	p = top->data; q = top; top = top->link; free(q);
			visit(p);
			p = p->rchild;
		} while (!(top == -1 && p == NULL));
	}
}

//	???错误
void postorder3(BTree b) {
	BTree stack[M] = { NULL }, p = b;
	int top = -1;
	if (p != NULL) {
		do {
			while (p != NULL) {
				stack[++top] = p;
				p = p->lchild;
			}
			p = stack[top--];
			visit(p);
			p = p->rchild;
		} while (!(top == -1 && p == NULL));
	}
}
//

//void postorder2(BTree b) {
//	BTree stack[M] = { NULL }, p = b;
//	int top = -1;
//	if (p != NULL) {
//		do {
//			while (p != NULL) {
//				stack[++top] = p;
//				p = p->lchild;
//			}
//			p = stack[top--];
//			p = p->rchild;
//			visit(p);
//		} while (!(top == -1 && p == NULL));
//	}
//}

//	已知具有n个结点的完全二叉树采用顺序存储结构，结点的数据信息依次存放于一维数组BT[n]中，写出中序遍历二叉树的非递归算法(顺序存储结构的中序遍历算法)
void inorder(int BTree[], int n) {
	int i = 0;
	int stack[M] = { 0 };
	int top = -1;
	if (n >= 0) {
		do {
			while (i < n) {
				stack[++top] = i;
				i = i * 2 + 1;
			}
			i = stack[top--];
			std::cout << BTree[i];
			i = i * 2 + 2;
		} while (!(top == -1 && i > n));
	}
}

//	二叉排序树binary sort tree
BTree insertBST(BTree &t, int item) {
	BTree p = NULL, q = t;
	p = (BTree)malloc(sizeof(BTnode));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;

	if (t == NULL) { t = p; }
	else {
		while (true) {
			if (q->data == item)return q;
			if (item < q->data) {
				if (q->lchild == NULL) { q->lchild = p; break; }
				else { q = q->lchild; }
			}
			else {
				if (q->rchild == NULL) { q->rchild = p; break; }
				else { q = q->rchild; }
			}

		}
	}
	return t;

}
BTree buildBST(int p[], int n) {
	BTree q = NULL;
	for (int i = 0; i < n; i++) {
		q = insertBST(q, p[i]);
	}
	return q;
}
BTree searchBST(BTree t, int item) {
	BTree p = t;
	while (p != NULL) {
		if (item == p->data)return p;
		if (item < p->data) {
			p = p->lchild;
		}
		if (item > p->data) {
			p = p->rchild;
		}
	}
	return NULL;
}
BTree searchBST2(BTree t, int item) {//	递归遍历
	BTree p = t;
	if(p != NULL) {
		if (item == p->data)return p;
		if (item < p->data) {
			return searchBST2(p->lchild, item);
		}
		if (item > p->data) {
			return searchBST2(p->rchild, item);
		}
	}
	else {
		return NULL;
	}
}

//	已知深度为h的非空二叉树采用顺序存储结构存放于数组BT[0..2^h-2],写一算法求二叉树中叶节点的数目
int game1(BTree BT[], int h) {
	int total = 0;
	for (int i = 0; i < int(pow(2, h)) - 1; i++) {
		if (BT[i] != NULL) {
			if (BT[2 * i + 1] == NULL && BT[2 * 2 + 2] == NULL || i > int(pow(2, h - 1)) - 1)total++;
		}
	}
	return total;
}
int game1_1(BTree t) {
	if (t == NULL) {
		return 0;
	}
	if (t->lchild == NULL && t->rchild == NULL)return 1;
	return game1_1(t->lchild) + game1_1(t->rchild);
}

//	已知具有n个结点的非空完全二叉树采用顺序存储结构，结点的数据信息依次存放于数组BT[0..n-1],请写出产生该二叉树二叉链表的算法
#define maxnode 100
BTree game2(int bt[], int n) {
	BTree t, ptr[maxnode];

	ptr[0] = (BTree)malloc(sizeof(BTnode));
	ptr[0]->data = bt[0];
	ptr[0]->lchild = NULL;
	ptr[0]->rchild = NULL;

	t = ptr[0];
	for (int i = 1; i < n; i++) {
		//if (bt[i] == NULL)continue;//	非空二叉树
		ptr[i] = (BTree)malloc(sizeof(BTnode));
		ptr[i]->data = bt[i];
		ptr[i]->lchild = NULL;
		ptr[i]->rchild = NULL;
		int j = (i - 1) / 2;
		if (i - 2 * j - 1 == 0)ptr[j]->lchild = ptr[i];
		else ptr[j]->rchild = ptr[i];
	}
	return t;
}

//	已知两二叉树采用二叉链表存储结构，根节点指针分别为t1,t2,写一递归算法，判断这两颗二叉树是否等价
bool game3(BTree t1, BTree t2) {
	if (t1 == NULL && t2 == NULL)return true;
	if (t1 != NULL && t2 != NULL && t1->data == t2->data && game3(t1->lchild, t2->lchild) && game3(t1->rchild, t2->rchild))return true;
	return false;
}

//	已知二叉树采用二叉链表存储结构，根节点地址为t，写一算法删除数据域内容为item的结点以及以该节点为根的子树上的所有结点(查找(前序遍历)，删除)
void release(BTree& p) {
	if (p != NULL) {
		release(p->lchild);
		release(p->rchild);
		free(p);
	}
}
BTree game4(BTree t, int item){
	BTree stack[M] = { NULL }, p = t, q = NULL;
	int top = -1;
	if (t != NULL) {
		do {
			while (p != NULL) {
				if (p->data == item) {
					if (p == t)t = NULL;
					if (q->lchild == p)q->lchild = NULL;
					if (q->rchild == p)q->rchild = NULL;
					release(p);
					return t;
				}
				stack[++top] = p;
				q = p;
				p = p->lchild;
			}
			p = stack[top--];
			q = p;
			p = p->rchild;
		} while (!(p == NULL && top == -1));
	}
}

//	已知非空二叉树采用二叉链表存储结构，根节点指针为t，写一复制该二叉树的算法
BTree game5(BTree t) {
	BTree p;
	if (t == NULL)return NULL;
	else {
		p = (BTree)malloc(sizeof(BTnode));
		p->lchild = game5(t->lchild);
		p->rchild = game5(t->rchild);
		p->data = t->data;
	}
	return p;
}

//	已知二叉树采用二叉链表存储结构，根节点指针为t，请写一算法判断该二叉树是否为二叉排序树
bool game6(BTree t) {
	BTree stack[M], p = t;
	int top = -1, x = 0;
	if (t != NULL) {
		do {
			while (p != NULL) {
				stack[++top] = p;
				p = p->lchild;
			}
			p = stack[top--];
			if (p->data < x)return false;
			x = p->data;
			p = p->rchild;
		} while (!(top == -1 && p == NULL));
	}
	return true;
}

//	已知二叉树的前序遍历序列与中序遍历序列存放于数组preor[n],与inor[n]中，并且各结点数据信息均不相同，写一算法生成该二叉树的二叉链表存储结构
//	求前序序列中结点在中序序列中的位置，每个结点的位置值相当于data值？类似一种权重？

int searchpos(int inor[], int n, int item) {
	for (int i = 0; i < n; i++) {
		if (inor[i] == item)return i + 1;
	}
}

void insertitem(BTree& t, int inor[], int n, int item) {//	二叉有序树中插入一个结点
	BTree p = NULL, q = t;
	int ord;
	p = (BTree)malloc(sizeof(BTnode));
	p->data = item;
	p->lchild = p->rchild = NULL;
	if (t == NULL)p = t;
	else {
		ord = searchpos(inor, n, item);
		while (true) {
			if (ord < searchpos(inor, n, q->data)) {
				if (q->lchild != NULL)q = q->lchild;
				else {
					q->lchild = p; break;
				}
			}
			else {
				if (q->rchild != NULL)q = q->rchild;
				else {
					q->rchild = p; break;
				}
			}
		}
	}
}
BTree game7(int inor[], int n, int preod[]) {
	BTree t = NULL;
	for (int i = 0; i < n; i++) {
		insertitem(t, inor, n, preod[i]);
	}
	return t;
}
int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//