﻿// queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define M 20
int queue[M];
int front, rear;

typedef struct node {
	int data;
	struct node* link;
}QNode, *QueueList;

void init(int &front, int &rear) {
	front = rear = -1;
}
bool isVoid(int front, int rear) {
	return front == rear;
}
bool push(int queue[], int &front, int &rear, int item) {
	if (rear == M - 1)return false;
	queue[++rear] = item;
	return true;
}
bool pop(int queue[], int &front, int &rear, int &item) {
	if (isVoid(front, rear))return false;
	item = queue[++front];
	return true;
}

//	队列链表结构
void init(QueueList &front, QueueList &rear) {
	front = NULL;
	rear = NULL;
}
bool isVoid(QueueList front, QueueList rear) {
	return front == rear;
}
bool push(QueueList &front, QueueList &rear, int &item) {
	//	无需判断满
	QueueList p;
	if(!(p = (QueueList)malloc(sizeof(QNode))))return false;
	p->data = item;
	p->link = NULL;
	if (front == rear) {
		front = p;
	}
	else {
		rear->link = p;
	}
	rear = p;
	return true;
}
bool pop(QueueList &front, QueueList &rear, int item) {
	QueueList p;
	if (isVoid(front, rear))return false;
	item = front->data;
	p = front;
	front = front->link;
	free(p);
	return true;
}
bool delet(QueueList &front, QueueList &rear) {
	QueueList p;
	while (front != rear) {
		p = front;
		front = front->link;
		free(p);
	}
	return true;
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