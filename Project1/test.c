#define _CRT_SECURE_NO_WARNINGS 1
#include"library.h"
void menu()
{
	printf("******************************************\n");
	printf("*******1.����鼮   2.ɾ���鼮************\n");
	printf("*******3.չʾ���  4.�޸��鼮��Ϣ*********\n");
	printf("*******5.�����鼮     6.����     *********\n");
	printf("************        0.�˳�     ***********\n");
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
		printf("��������Ҫ���еĲ���:\n");
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
			printf("�˳�ͼ���\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
