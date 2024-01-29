#define _CRT_SECURE_NO_WARNINGS 1
#include"library.h"
void menu()
{
	printf("******************************************\n");
	printf("*******1.添加书籍   2.删除书籍************\n");
	printf("*******3.展示书库  4.修改书籍信息*********\n");
	printf("*******5.查找书籍     6.排序     *********\n");
	printf("************        0.退出     ***********\n");
	printf("******************************************\n");

}

void test()
{
	int input = 0;
	library lib;
	InitLibrary(&lib);
	do
	{
		menu();
		printf("请输入你要进行的操作:\n");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddLibrary(&lib);
			break;
		case del:
			DelLibrary(&lib);
			break;
		case show:
			ShowLibrary(&lib);
			break;
		case modify:
			ModifyLibrary(&lib);
			break;
		case search:
			SearchLibrary(&lib);
			break;
		case sort:
			SortLibrary(&lib);
			break;
		case out:
			SaveLibrary(&lib);
			DestroyLibrary(&lib);
			printf("退出图书馆\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
