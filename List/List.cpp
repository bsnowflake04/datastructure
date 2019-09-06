// List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>

#define MAXSIZE 100


//	读
void read(int a[], int n) {
	int i = 0;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//	确定元素item在长度为n的线性表a中的位置
int LOCATE(int a[], int n, int item) {
	for (int i = 0; i < n; i++) {
		if (a[i] == item)return i+1;
	}
	return -1;
}

//	在长度为n的线性表a的第i个位置上插入一个新的数据元素item
int insertlist(int a[], int &n, int i, int item) {
	if (n == MAXSIZE || i < 1 || i > n+1) return -1;
	for (int j = n-1; j >= i-1; j--) {
		a[j + 1] = a[j];
	}
	a[i - 1] = item;
	n++;
	return 1;
}

//	删除长度为n的线性表a的第i个元素
int deletelist(int a[], int& n, int i) {
	if (n == 0 || i < 1 || i > n) return -1;
	for (int j = i; j < n; j++) {
		a[j - 1] = a[j];
	}
	n--;
	return 1;
}

//	已知长度为n的非空线性表a采用顺序存储结构， 并且数据元素按值的大小非递减排序，则在该线性表中插入一个数据元素item，使得线性表仍然保持按值非递减排序
int ques1(int a[], int n, int item) {
	if (a[n - 1] <= item)a[n] = item;
	else {
		int i = 0;
		while (item >= a[i]) {
			i++;
		}
		for (int j = n - 1; j >= i; j--) {	//i是下标
			a[j + 1] = a[j];
		}
		a[i] = item;
	}
	n++;
	return 1;
}

//	对于通过键盘输入的n个整形数据元素，建立一个不包含重复元素的顺序表（假设不考虑存储空间溢出的问题）
void game(int a[], int n) {
	int m, flag = 0;
	int x = 0;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &m);
		for (int j = 0; j < x; j++) {
			if (a[j] == m) {
				flag = 1;
			}
		}
		if (flag == 0) { a[x] = m; x++; }
		else flag = 0;
		read(a, n);
	}
}

//	已知长度为n的非空顺序表a的数据元素按值的大小非递减排列，写一算法删除顺序表中值相同的多余元素
void game2(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] == a[j]) {
				for (int k = i+1; k < n; k++) {
					a[k-1] = a[k];
				}
				n--;
			}
		}
		read(a, n);
	}
}
void del(int a[], int& n) {
	int j, i = 0;
	while (i < n-1) {
		if (a[i] != a[i + 1])i++;
		else {
			for (j = i + 1; j < n; j++)
				a[j - 1] = a[j];
			n--;
		}
	}
}
void del2(int a[], int& n) {
	int i, k = 0;
	if (n > 1) {
		for (i = 1; i < n; i++) {
			if (a[i] != a[k])a[++k] = a[i];
			n = k + 1;
		}
	}
}//	???



////////////////////////////////////////////////////
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}
	a[3] = 7;
	a[5] = 3;
	game2(a, 8);
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
