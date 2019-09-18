// TBTNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

typedef struct node {
	int data;
	struct node* lchild, * rchild;
	int lbit, rbit;
}BTBNode, *TBtree;

void visit(TBtree t) {
	;
}

TBtree nextPointSearch(TBtree t) {//	寻找t的后继节点
	TBtree s;
	s = t->rchild;
	if (t->rbit == 1) {
		while (s->lbit == 1)s = s->lchild;
	}
	return s;
}

void inorder(TBtree head) {//	中序线索二叉树的中序遍历
	TBtree s = head;
	s = head->lchild;//	???
	while (true) {
		s = nextPointSearch(s);
		if (s == head)break;
		visit(s);
	}
}

TBtree buildTBtree(TBtree t) {
	TBtree head = NULL, p = t, prior;
	TBtree stack[20],
	int top = -1;

	head = (TBtree)malloc(sizeof(BTBNode));//	做头节点
	head->lbit = 1; head->rbit = 1; head->rchild = head; head->lchild = t;

	prior = head;
	do {
		while (p != NULL) {
			stack[++top] = p;
			p = p->lchild;
		}
		p = stack[top--];
		//套在中序遍历中制作线索二叉树
		if (p->lchild == NULL) {
			p->lchild = prior;
			p->lbit = 0;
		}
		else {
			p->lbit = 1;
		}

		if (prior->rchild == NULL) {
			prior->rchild = p;
			prior->rbit = 0;
		}		   
		else {
			prior->rbit = 1;
		}

		prior = p;
		//------------------
		p = p->rchild;
	} while (!(top < 0 && p == NULL));
	prior->rchild = head;
	prior->rbit = 0;//	后继节点指回头节点
	return head;
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
