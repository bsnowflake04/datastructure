// queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define M 20
int queue[M] = {0};
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
	return front == NULL;
}
bool push(QueueList &front, QueueList &rear, int item) {
	//	无需判断满
	QueueList p;
	if(!(p = (QueueList)malloc(sizeof(QNode))))return false;
	p->data = item;
	p->link = NULL;
	if (front == NULL) {
		front = p;
	}
	else {
		rear->link = p;
	}
	rear = p;
	return true;
}
bool pop(QueueList &front, QueueList &rear, int &item) {
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
	while (front != NULL) {
		p = front;
		front = front->link;
		free(p);
	}
	return true;
}
void print(int queue[], int front, int rear) {
	for (int i = front+1; i < rear+1; i++) {
		std::cout << queue[i] << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < M; i++) {
		std::cout << queue[i] << " ";
	}
}
void print1(QueueList front, QueueList rear) {
	while (front != NULL) {
		std::cout << front->data << " ";
		front = front->link;
	}
}

//	应用： 主机与外部用户资源不匹配  多用户资源竞争 离散事件模拟 图的广度优先搜索 树的层次遍历

//	循环队列: front和rear中间有一块空的存储单元
typedef struct circleQueue {
	int queue[M];
	int front;
	int rear;
}CQueue;

void init3(CQueue* cq) {
	cq->front = cq->rear = 0;
}

bool isEmpty3(CQueue* cq) {
	return cq->front == cq->rear;
}

bool isFull3(CQueue* cq) {
	return (cq->rear + 1) % M == cq->front;
}

bool push3(CQueue* cq, int data) {
	if (isFull3(cq))return false;
	cq->queue[cq->rear] = data;
	cq->rear = (cq->rear + 1) % M;
	return true;
}

bool pop3(CQueue* cq, int &data) {
	if (isEmpty3(cq))return false;
	data = cq->queue[cq->front];
	cq->front = (cq->front + 1) % M;
	return true;
}

bool print3(CQueue* cq) {
	if(isEmpty3(cq))return false;
	if (cq->front < cq->rear) {
		for (int i = cq->front; i < cq->rear; i++) {
			std::cout << cq->queue[i] << " ";
		}
	}
	else {
		for (int i = cq->front; i < cq->rear + M; i++) {
			std::cout << cq->queue[i] << " ";
		}
	}
	return true;
}
int main()
{
	////	1
	//int n;
	//init(front, rear);
	//push(queue, front, rear, 22);
	//push(queue, front, rear, 22);
	//push(queue, front, rear, 33);
	//push(queue, front, rear, 20);
	//pop(queue, front, rear, n);
	//print(queue, front, rear);
 //   std::cout << "Hello World!\n" << n;
	//
	////	2
	//QueueList p = NULL, q = NULL;
	//init(p, q);
	//push(p, q, 1);
	//push(p, q, 2);
	//push(p, q, 3);
	//pop(p, q, n);
	//delet(p, q);
	//print1(p, q);
	//std::cout << "Hello World!\n" << n;
	////	3
	//CQueue q;
	//
	//int a = 0;
	//init3(&q);
	//push3(&q, 22);
	//push3(&q, 21);
	//push3(&q, 23);
	//print3(&q);

	//pop3(&q, a);
	//std::cout << a;
	//print3(&q);

	CQueue* q = NULL;

	int a = 0;
	init3(q);
	push3(q, 22);
	push3(q, 21);
	push3(q, 23);
	print3(q);

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
