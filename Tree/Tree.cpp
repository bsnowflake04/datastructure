// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define M 30

typedef struct node {
	int data;
	struct node *lchild, *rchild;
}BTnode, *BTree;

void visit(BTree b) {
	;
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
//	???错误
void inorder3(BTree b) {
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
