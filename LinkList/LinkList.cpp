// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* link;
}LNode, *LinkList;

//	读循环链表
void read(LinkList list) {
	LinkList w = list;
	do {
		printf("%d ", w->data);
		w = w->link;
	} while (w != list);
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
	LinkList  p = NULL, r=NULL, list = NULL;
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

//	求循环链表的长度
int Lengthen(LinkList list) {
	int n = 0;
	LinkList p = list;
	do {
		p = p->link;
		n++;
	} while (p != list);
	return n;
}

//	圆桌问题：n个人围坐在一张圆桌周围，编号为k的人从1开始报数，数到m的那个人出列，他的下一个人又从1开始继续报数，数到m的那个人出列，直到圆桌只剩一人
void JOSEPHU(int n, int k, int m) {
	LinkList p=NULL, r=NULL, list = NULL;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		if (list == NULL) {
			list = p;
		}
		else {
			r->link = p;
		} 
		r = p;
	}
	p->link = list;
	read(list);
	r = list;
	for (int i = 1; i < k; i++) {
		r = r->link;
	}
	
	while (r->link != r) {
		for (int i = 1; i < m; i++) {
			p = r;
			r = r->link;
		}
		p->link = r->link;
		printf("%d ", r->data);
		free(r);
		r = p->link;

		read(list);
	}
}

//	已知线性链表第一个链结点的指针为list，请写一段销毁（将链表中所有结点都删除，并释放其存储空间，使之成为一个空链表）该链表的非递归算法

//	建立链表，判空
LinkList e(int n) {
	LinkList p = NULL, r = NULL, list = NULL;
	for (int i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
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

//	向list的n位置插入结点，判n<1，n>长度，头结点，空
bool i(LinkList &list ,int n, int item) {
	if (n < 1 )return false;

	LinkList p = NULL, r = list;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = item;

	if (n == 1 || list == NULL) {
		p->link = list;
		list = p;
		return true;
	}

	for (int i = 2; i < n; i++) {
		r = r->link;
		if (p == NULL)return false;
	}

	p->link = r->link;
	r->link = p;
}

//删除链表n位置结点 判n<1, n>长度, 空, 头节点, 
bool d(LinkList& list, int n) {
	if (n < 1 || list == NULL)return false;
	LinkList p = list, r = NULL;
	if (n == 1) {
		r = list;
		list = list->link;
		free(r);
		return true;
	}

	for (int i = 1; i < n; i++) {
		r = p;
		p = p->link;
		if (p == NULL)return false;
	}

	r->link = p->link;
	free(p);
	return true;
}

class DoubleLinkList {

	typedef struct node {
		int data;
		struct node* llink, * rlink;
	};

	struct node* head;
	struct node* tail;

//	向无头结点双向链表n位置插入结点，判n<1,>长度，空，头尾结点，
bool in(int n) {
	if (n < 1)return false;
		struct node* p = NULL, *r = head;
		p = (struct node*)malloc(sizeof(struct node));
		if (head == NULL) {
			head = p;
			tail = p;
			return true;
		}
		if (n == 1) {
			p->rlink = head;
			head->llink = p;
			head = p;
			return true;
		}

		for (int i = 2; i < n; i++) {
			r = r->rlink;
			if (r == NULL) {
				r = tail;
				break;
			}
		}

		if (tail == r) {
			p->llink = tail;
			tail->rlink = p;
			tail = p;
			return true;
		}

		p->llink = r;
		p->rlink = r->rlink;
		r->rlink->llink = p;
		r->rlink = p;
		
		return true;
}

//删除无头结点双向链表n位置的结点 判n<1，>长度，空，头尾结点
bool de(int n) {
	if (n == 0 || head == NULL)return false;
	struct node* r = NULL, * p = NULL;

	for (int i = 1; i < n; i++) {
		p = p->llink;
		if (p == NULL)return false;
	}
	if (head == p) {
		r = head;
		head = head->rlink;
		free(r);
		return true;
	}
	if (tail == p) {
		r = tail;
		tail = p->llink;
		free(p);
		return true;
	}

	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	return true;

}
};

int main() {
	return 0;
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
