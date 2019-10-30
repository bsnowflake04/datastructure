// structsection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

struct student {
	char id[12];
	char name[20];
	float score[3];
	float aver;
};

int main()
{
    ////结构体数组，结构体数组的排序
	/*struct person {
		char name[10];
		int score;
	}leader[3] = {
		"a", 0, "b", 0, "c", 0
	};*/

	//char temp[20];
	//for (int i = 0; i < 5; i++) {
	//	scanf_s("%s", temp, sizeof(temp));
	//	for (int j = 0; j < 3; j++) {
	//		if (strcmp(leader[j].name, temp) == 0) { leader[j].score++; break; }//其中leader[i]是一个结构体变量，不是一个结构体指针，无法用->
	//	}
	//}
	//for (int i = 0; i < 3; i++) {
	//	printf("%s %d\n", leader[i].name, leader[i].score);
	//}
	//char* p = temp;
	//for (int i = 0; i < 10; i++) {
	//	printf("%c\n", *p++);
	//}

	////结构体指针
	/*struct person* q;
	for (q = leader; q < leader + 3; q++) {
		printf("%s%d\n", q->name, (*q).score);
	}*/

	////结构体变量和指针传参
	
	/*void input(struct student * p);
	struct student max(struct student* p);
	void print(struct student m);
	struct student person[3] = { {"123", "chris"},{"124", "tom"},{"125", "fish"} };
	struct student* p = person;
	input(p);
	print(max(p));*/

	////共用体和枚举类型

	//union firstu {
	//	int a;
	//	char c;
	//	float b;
	//}x,y,z;
	//x.a = 5; x.c = 'x';
	//printf("%d\n", x.a);

	//enum buding {
	//	x1 = 7,x2 = 5,x3,x4,x5//	未命名元素比之前元素递增
	//}wdj,ndj,tdj;

	//wdj = x3; ndj = x2; tdj = x4;
	//std::cout << wdj << x3 << x4;

	////typedef
	typedef int a;
	a i = 3;
	typedef struct b {}c;
	c *x;//struct b *x
	typedef char* d;
	d c;// char * c
	typedef int e[100];
	e f = {1,2,3,4,5};// int f[100];
	typedef int (*ppp)(int, int);
	ppp q;//int (*q)(int ,int)函数指针
}

void input(struct student *p) {
	
	for (int i = 0; i < 3; i++,p++) {
		scanf_s("%f %f %f", &p->score[0], &p->score[1], &p->score[2]);
		p->aver = (p->score[0]+ p->score[1]+ p->score[2]) / 3;
	}
}
struct student max(struct student* p) {
	struct student* q = p;
	for (int i = 0,j = p++->aver; i < 2; i++,p++) {
		if (j < p->aver) {
			q = p;
			j = p->aver;
		}
	}
	return *q;
}
void print(struct student m) {
	struct student* p = &m;
	printf("%s %s %f %f %f %f", p->id, p->name, p->score[0], p->score[1], p->score[2], p->aver);
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
