// DoubleLinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* llink, * rlink;
}DNode, *DLinkList;

int main()
{
    std::cout << "Hello World!\n";
}

//	在带有头结点的非空双向循环链表中第一个数据域的内容为x的链结点右边插入一个数据信息为item的新结点
void insert(DLinkList list, int x, int item) {
	DLinkList p, q = list;
	do {
		q = q->rlink;
	} while (q->data != x && q != list);

	p = (DLinkList)malloc(sizeof(DNode));
	p->data = item;

	p->llink = q;
	p->rlink = q->rlink;
	q->rlink->llink = p;
	q->rlink = p;
}

//	删除带有头结点的非空双向循环链表中第一个数据域的内容为x的链结点
void delette(DLinkList list, int x) {
	DLinkList p, q = list;
	do {
		p = q;
		q = q->rlink;
	} while (q->data != x && q != list);

	p->rlink = q->rlink;
	q->rlink->llink = p;
	free(q);
}

//	构造一个带头结点的双向循环链表
DLinkList establish(int x) {
	DLinkList p, r, list = NULL;
	list = (DLinkList)malloc(sizeof(DNode));
	list->data = NULL;
	list->llink = list;
	list->rlink = list;

	for (int i = 0; i < x; i++) {
		p = (DLinkList)malloc(sizeof(DNode));
		p->data = i;

		p->llink = list->llink;
		p->rlink = list;
		list->llink->rlink = p;
		list->llink = p;
	}
	return list;
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
