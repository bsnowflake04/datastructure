// stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define M 20
int stack[M];
int top;
int top1[] = { -1, M };

typedef struct node {
	int data;
	struct node* link;
}SNode, *StackList;

//	堆栈
bool isFilled(int top) {
	return (top == M-1);
}
bool isVoid(int top) {
	return (top == -1);
}
void init(int& top) {
	top = -1;
}
bool push(int stack[], int& top, int item) {//	1a 2b c d e top--->
	if (isFilled(top))return false;
	stack[++top] = item;
	return true;
}
bool pop(int stack[], int& top, int &item) {
	if (isVoid(top))return false;
	item = stack[top--];
	return true;
}

////	多栈连续共享空间
void init1(int top[]) {
	top[0] = -1;
	top[1] = M;
}
bool push1(int stack[], int top[], int i, int item) {
	if (top[0] + 1 == top[1])return false;
	if (i == 0) {
		stack[++top[0]] = item;
	}
	else {
		stack[--top[1]] = item;
	}
	return true;
}
bool pop1(int stack[], int top[], int i, int &item) {
	if (i == 0) {
		if (top[0] == -1)return false;
		item = stack[top[0]--];
	}
	else {
		if (top[1] == M)return false;
		item = stack[top[1]++];
	}
	return true;
}
////	堆栈链式结构
void init(StackList &top) {
	top = NULL;
}
bool isVoid(StackList top) {
	return top == NULL;
}

bool push2(StackList& top, int item) {
	//	不用判满哈哈哈
	StackList p = NULL;
	if (!(p = (StackList)malloc(sizeof(SNode))))return false;
	p->data = item;
	p->link = top;
	top = p;
	return true;
}
bool pop2(StackList& top, int& item) {
	//	需要判空！
	if (isVoid(top))return false;
	StackList p;
	item = top->data;
	p = top;
	top = top->link;
	free(p);
	return true;
}

void print(int stack[], int top) {
	for (int i = 0; i < top+1; i++) {
		std::cout << stack[i] << " ";
	}
	std::cout << "\n";

}
void print1(int stack[]) {
	for (int i = 0; i < M; i++) {
		std::cout << stack[i] << " ";
	}
}
void print2(StackList top) {
	while (top != NULL) {
		std::cout << top->data << " ";
		top = top->link;
	}
}
int main()
{
	//1
	int n, m, x;
	init(top);
	push(stack, top, 2);
	push(stack, top, 12);
	push(stack, top, 11);
	pop(stack, top, n);
	push(stack, top, 132);
	print(stack, top);
	
    std::cout << "Hello World!\n" << n << "\n";
	//2
	init1(top1);
	push1(stack, top1, 0, 55);
	push1(stack, top1, 0, 2);
	pop1(stack, top1, 0, m);
	push1(stack, top1, 1, 22);
	push1(stack, top1, 1, 33);
	push1(stack, top1, 0, 55);
	print1(stack);
	std::cout << "Hello World!\n" << m << "\n";
	//3
	StackList p;
	init(p);
	push2(p, 23);
	push2(p, 23);
	push2(p, 22);
	push2(p, 7);
	pop2(p, x);
	print2(p);
	std::cout << "he" << "\n" << x;

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
