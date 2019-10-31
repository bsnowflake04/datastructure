// filesection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
////预编译：分为宏定义(单纯的字符替换) 条件编译（根据指定的标识符是否被定义过，确定在程序预编译阶段编译哪一段程序）， 文件包含
#define MAX(x,y) (x>y):(x)?(y)//	简化了函数
#define LETTER 1

struct student {
	int id;
	char name[10];
	int sex;
}stu[3] = { {1, "wjh", 5},{1, "cck", 5 }, {1,"kkk0, ", 5} };
int main()
{
    ////顺序读写文件
	//FILE* fp = NULL;
	//errno_t error = 0;
	//char filename[30] = /*"3.txt"*/"D:\\github\\testfile\\3.txt", ch;
	///*if ((error = fopen_s(&fp, filename, "w")) == 0) {
	//	printf("error");
	//	exit(0);//	这种方法会在fputc上显示异常？？
	//}*/
	//if (fopen_s(&fp, filename, "w") != NULL) {
	//	printf("error");
	//	exit(0);
	//}
	//while ((ch = getchar()) != '#') {
	//	fputc(ch, fp);
	//	putchar(ch);
	//}
	//fclose(fp);

	////两文件之间顺序读写
	/*FILE* fp1, * fp2;
	char filename1[30] = "D:\\github\\testfile\\3.txt", filename2[30] = "3.txt";
	char ch;
	if (fopen_s(&fp1, filename1, "r") != NULL) {
		printf("error1");
		exit(0);
	}
	if (fopen_s(&fp2, filename2, "w") != NULL) {
		printf("error2");
		exit(0);
	}
	while (!feof(fp1)) {
		ch = fgetc(fp1);
		putchar(ch);
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);*/

	////其他fio方法
	//FILE* f;
	//char filename1[30] = "D:\\github\\testfile\\3.txt", filename2[30] = "3.txt";
	//char textputs[3][30] = { "i wanna rock", "and i really really want", "so what do u want?" }, tex[1000] = "1";
	//if (fopen_s(&f, filename1, "a") != NULL) {
	//	printf("eroor00");
	//	exit(0);
	//}
	//fputs(textputs[2], f); fputs("\n", f);
	//for (int i = 0; i < 3; i++) {
	//	if ((fwrite(&stu[i], sizeof(struct student), 1, f) != 1)) {
	//		printf("error");
	//	}
	//}
	////fputs("hhh", f);
	////rewind(f);
	////fgets(tex, 1000, f);//有疑问？？
	////printf("%s", tex);
	//fprintf(f, "%d\n%s", 5, textputs[1]);

	//for (int i = 0; i < 3; i++) {
	//	fseek(f, i * sizeof(struct student), 1);
	//	fwrite(&stu[i], sizeof(struct student), 1, f);
	//}
	//fclose(f);
	//
	//////位运算 |= ^= &= <<= >>= 位段:
	//struct packed_data {
	//	unsigned a : 2;
	//	unsigned b : 1;
	//	unsigned : 0;//	储存单元分隔符	
	//	unsigned c : 2;

	//};
	char testifdef[50] = " ni shuo ni haoxiang daiwo hui qu nid jia xiang", ch;
	for (int i = 0; (ch = testifdef[i]) != '\0'; i++) {
	#if LETTER
		if (ch >= 'a' && ch <= 'z')ch -= 32;
	#else
		if (ch >= 'A' && ch <= 'Z')ch += 32;
	#endif
		printf("%c", ch);
	}
	printf("\n%s", testifdef);
	#ifdef printf("tiaoshi");
	#endif
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
