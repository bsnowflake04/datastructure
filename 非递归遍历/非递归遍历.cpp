// 非递归遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MAX 200
using namespace std;
typedef struct _node{
	struct _node* left;
	struct _node* right;
	char data;
}Node;
class Stack {
private:
	int top = -1;
	Node *data[MAX];
public:
	bool push(Node* node) {
		if (!isFull())
		{
			data[++top] = node;
			return true;
		}
		return false;
	}
	Node* pop() {
		if (!isEmpty())
			return data[top--];
		return NULL;
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MAX - 1;
	}
};


void visit(Node*p)
{
	cout << p->data<<" ";
}
void preorder(Node * root)
{
	Node* p = root;
	Stack stack;
	do {
		while (p != NULL)
		{
			visit(p);
			stack.push(p);
			p = p->left;
		}
	} while ((p = stack.pop()) != NULL&&(p=p->right)==p);
}

void midorder(Node* root)
{
	Node* p = root;
	Stack stack;
	do {
		while (p != NULL)
		{
			stack.push(p);
			p = p->left;
		}
		if ((p = stack.pop()) == NULL) break; 
		visit(p);
		p = p->right;
	} while (true);
}
void postorder(Node * root) {
	Node* p = root;
	Stack stack1,stack2;
	do {
		while (p != NULL)
		{
			stack2.push(p);
			stack1.push(p);
			p = p->right;
		}
		if ((p = stack1.pop()) == NULL) break;
		p = p->left;
	} while (true);
	while (!stack2.isEmpty()) {
		visit(stack2.pop());
	}
}
int main()
{

	Node* root = new Node();
	root->data = 'a';
	root->left = new Node();
	root->left->data = 'b';
	root->left->left = NULL;
	root->left->right = NULL;


	root->right = new Node();
	root->right->data = 'c';
	root->right->left = NULL;
	root->right->right = NULL;


	preorder(root);
	midorder(root);
	postorder(root);
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
