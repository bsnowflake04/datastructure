// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* link;
}LNode, *LinkList;

int main(){

}

//	求链表长度
int LENGTHEN(LinkList list) {
	LinkList p = list;
	int n = 0;
	while (p != NULL) {
		p = p->link;
		n++;
	}
	return n;
}

//	求链表长度 递归
int LENGTHEN2(LinkList list) {
	if (list != NULL)
		return 1 + LENGTHEN2(list->link);
	else return 0;
}

//	建立一个线性链表
LinkList establish(int n) {
	LinkList  p, r, list = NULL;
	for (int i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->link = NULL;

		if (list == NULL) {
			list = p;
		}
		else {
			r->link = p;
		}
		r = p;
	}
	return list;
}


//	在非空线性链表的第一个节点前插入一个数据信息为item的新节点
void insert(LinkList& list, int item) {
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	p->link = list;
	list = p;
}

//	在线性链表中由指针q指的链结点之后插入一个数据信息为item的链结点
void insert2(LinkList& list, LinkList q, int item) {
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	if (list == NULL) {
		list = p;
		p->link = NULL;
	}
	else {
		p->link = q->link;
		q->link = p;
	}
}

//	在线性链表中第i(i>0)个结点后面插入一个数据信息为item的新节点（在上一个的基础上加入遍历）
void insert3(LinkList& list, int i, int item) {
	LinkList p, q = list;
	for (int j = 1; j < i; j++) {
		q = q->link;
		if (q == NULL)break;
	}
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;
	p->link = q->link;
	q->link = p;
}

//	从非空线性链表中删除q指的链结点，设q的直接前驱节点由r指出
void delete1(LinkList& list, LinkList q, LinkList r) {
	if (q == list) {
		list = q->link;
	}
	else {
		r->link = q->link;
	}
	free(q);
}

//	从非空线性链表中删除q指的链结点
void delete2(LinkList& list, LinkList q) {
	LinkList p = list;
	if (q == list) {
		list = q->link;
		free(q);
	}
	else {
		while (p->link != q && p->link != NULL) {
			p = p->link;
		}
		if (p->link != NULL) {
			p->link = q->link;
			free(q);
		}
	}
}

//	用尽可能高的时间效率找到由list所指的线性链表的倒数第K个结点，给出该点的地址否则给出NULL
LinkList game1(LinkList list, int k) {
	if (list == NULL || k <= 0) {
		return NULL;
	}
	LinkList p = list, r = list;
	for (int i = 1; i < k; i++) {
		r = r->link;
		if (r == NULL)return NULL;
	}

	while (r->link != NULL) {
		p = p->link;
		r = r->link;
	}
	return p;
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
