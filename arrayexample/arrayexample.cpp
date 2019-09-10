// arrayexample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void print(int(*a)[5], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << '\n';
	}
}
//	void ar(int a[][n], int n){ 错误，
//	二维数组传参？？
void arrayexample(int (*a)[5], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}

	int i = 0, j = n / 2;
	for (int num = 1; num <= n * n; num++) {
		if (i < 0 && j < 0 || a[i][j] > 0) {
			i = i + 2;
			j++;
		}
		if (i < 0 && j >= 0)i = n - 1;
		if (i >= 0 && j < 0)j = n - 1;

		a[i--][j--] = num;

	}

	print(a, n);

}

int main()
{
	int b[][5] = { 0 };
	arrayexample(b, 5);
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
