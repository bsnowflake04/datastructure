// nodesection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

void fun(int arr[]) {	//	arr[]这里是指针变量 == *arr
	printf("%d\n", *arr);
	arr = arr + 3;//	arr这里是指针变量
	printf("%d\n", *arr);
}

//	本章分为 数组指针，字符指针，函数指针，指针函数，指针数组，多重指针，动态内存分配
int main()
{
	////数组指针
	/*int a[5];
	int* p = a;
	for(int i = 0; i < 5; i++)
		scanf_s("%d", p++);
    std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\Hello World!\n";
	p = a;
	for (int i = 0; i < 5; i++)
		printf("%d  ", *p++);
	putchar('\n');
	fun(a);*/
	
	////二维数组指针
	/*int a[][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int *p;//	这里若a是一维数组则p = a，二维p指向的是*a，都代表第一个元素首地址
	for (p = *a; p < *a + 12; p++) {
		if ((p - *a) % 4 == 0)putchar('\n');
		printf("%4d", *p);
	}*/
	
	////将数组指针做函数参数
	/*
	void search(int (*p)[4], int n);
	void average(int *p, int n);
	float score[3][4] = {
		{65,66,67,68},{77,78,78,79},{88,85,25,55}
	};
	search(score, 2);
	average(*score, 12);*/
	
	////字符指针操作
	//char a[] = "I am stdt", b[20];
	///*int i;
	//for (i = 0; *(a + i) != '\0'; i++) {
	//	*(b + i) = *(a + i);
	//}
	//*(b + i) = '\n';*/
	//char* p = a, * q = b;
	//for (; *p != '\0'; p++, q++) {
	//	*q = *p;
	//}
	//*q = '\0';
	//
	//printf("%s\n", b);
	
	////字符指针做形参和实参
	//void copystr(char from[], char to[]);//形参实参可以不匹配，但是声明要一致
	//char p[] = "i am a fcingboy";
	//char q[] = "youyyyoyoyyoy";
	//char *a = p, *b = q;
	//printf("%s\n%s\n", p,q);
	//copystr(a,b);
	//printf("%s\n%s\n", p, q);

	////指针的输出格式控制
	//char a[] = "%4.2f\n%4.1f\n%5.3f\n";
	//char* p = a;
	//printf(p,1.2554,2.3255,3.3554);

	////函数指针的传参
	//void control(int a, int b, int (*p)(int, int));
	//int max(int a, int b);
	//int min(int a, int b);
	//int (*p)(int,int);//函数指针的类型跟所指函数返回值类型相同
	//int a = 88, b = 44,n = 0,*p1 = &n;
	//char c[] = "%d"; char* p2 = c;
	//scanf_s(c, p1);
	///*if (*p1 == 1) {
	//	p = max; control(a, b, p);
	//}
	//else if (*p1 == 2) {
	//	p = min; control(a, b, p);
	//}*/
	//if (*p1 == 1) {
	//	control(a, b, max);//函数名当作函数指针
	//}
	//else if (*p1 == 2) {
	//	control(a, b, min);
	//}

	////指针函数，这里只用它将二维指针转到一维指针
	/*float* change(float(*p)[4], int n);
	float score[][4] = { {45,45,45,45}, {78,78,78,78}, {98,98,98,98}};
	float* q = change(score, 2);

	for (int i = 0; i < 4; i++) {
		printf("%f\n", *(q + i));
	}*/

	////指针数组的类型 == 指针类型 == 所指类型
	const char* a[] = { "tell me what u want", "what u really", "really really want" };//	其中的数组名a就是双重指针
	const char* b = "abc";//	char *b = "abc";错误
	/*for (int i = 0; i < 3; i++) {
		printf("%s\n", a[i]);
	}*/
	////多重指针
	//int c[] = { 77,88,99,1010 };
	//int* d[] = { &c[0], &c[1], &c[2], &c[3] };//int类型指针数组,每个int指针指向c数组元素
	//int** p = d;
	//while (**d != NULL) { printf("%4d\n", **p++); }//	while里的值取啥？？
	/*const char** p1 = a;
	while(**a != NULL) {printf("%s\n", *p1++);}*/

	////动态内存分配: void指针类型
	void* p;
	p = malloc(100);
	p = calloc(40, 4);
	free(p);
	p = realloc(p, 50);
	
	int* p1;
	p1 = (int*)(malloc(5*sizeof(int)));
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", p1+i);//??
	}

}


float* change(float(*p)[4], int n) {
	return (float*)*(p + n);
}

void control(int a, int b, int (*p)(int, int)) {
	printf("%4d", (*p)(a, b));
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}

//void copystr(char* from, char* to) {//两种形式等同*from和from[]
void copystr(char from[], char to[]){
	for (; *to != '\0'; from++, to++) {
		*from = *to;
	}
	*from = '\0';
	
	/*int i;
	for (i = 0; from[i] != '\0'; i++) {
		from[i] = to[i];
	}
	from[i] = '\0';*/
}

void average(float* p, int n) {
	float* p_end, sum = 0;

	p_end = p + n - 1;
	for (; p <= p_end; p++) {
		printf("%4.2f\n", *p);
		sum += *p;
	}
	sum /= n;
	printf("%4.2f/////////////", sum);
}
void search(float(*p)[4], int n) {//	形参中的是数组行指针--二维指针？
	for (int i = 0; i < 4; i++)
		printf("%4.2f/", *(*(p + n) + i));
	putchar('\n');
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
