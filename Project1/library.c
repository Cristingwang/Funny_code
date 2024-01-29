#define _CRT_SECURE_NO_WARNINGS 1
#include"library.h"
int CheckCapacity(library* pc);
void LoadLibrary(library* pc)
{
	FILE* pf = fopen("my_library.data", "rb");
	if (pf == NULL)
	{
		perror("LoadLibrary");
		return;
	}
	BooksInfo temp = { 0 };
	while (fread(&temp, sizeof(BooksInfo), 1, pf))
	{
		if (!CheckCapacity(pc))
		{
			return;
		}
		pc->data[pc->sz] = temp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}
void InitLibrary(library* pc)
{
	assert(pc);
	pc->data = (BooksInfo*)malloc(DEFAULT_SZ * sizeof(BooksInfo));
	if (pc->data == NULL)
	{
		perror("InitLibrary");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	LoadLibrary(pc);
}
int CheckCapacity(library* pc)
{
	if (pc->sz == pc->capacity)
	{
		BooksInfo* ptr = (BooksInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(BooksInfo));
		if (ptr == NULL)
		{
			perror("CheckCapacity");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
			return 1;
		}
	}
	return 1;
}
void AddLibrary(library* pc)
{
	assert(pc);
	if (0 == CheckCapacity(pc))
	{
		printf("图书馆已满，不能添加\n");
		return;
	}
	printf("请输入书本ID：>");
	scanf("%d", &(pc->data[pc->sz].Book_id));
	printf("请输入书名：>");
	scanf("%s", pc->data[pc->sz].Book_title);
	printf("请输入作者：>");
	scanf("%s", pc->data[pc->sz].Book_author);
	printf("请输入出版社：>");
	scanf("%s", pc->data[pc->sz].Book_Publisher);
	pc->sz++;
	printf("添加成功\n");
	return;

}
void ShowLibrary(const library* pc)
{
	int i = 0;
	printf("%-15s\t%-10s\t%-5s\t%-10s\n", "书名", "作者名", "ID号", "出版商");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-15s\t%-10s\t%-5d\t%-10s\n",
			pc->data[i].Book_title,
			pc->data[i].Book_author,
			pc->data[i].Book_id,
			pc->data[i].Book_Publisher);

	}
}

static int FindByTitle(const library* pc, char title[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].Book_title, title) == 0)
		{
			return i;
		}
	}
	return -1;

}

void DelLibrary(library* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("没有藏书，无法删除\n");
		return;
	}
	char title[MAX_TITLE_LEN];
	printf("请输入要删除的书籍名称\n");
	scanf("%s", title);
	int del = FindByTitle(pc, title);
	if (del == -1)
	{
		printf("没有找到该书籍\n");
		return;

	}
	int i = 0;
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除书籍成功\n");
}

void SearchLibrary(const library* pc)
{
	assert(pc);
	char title[MAX_TITLE_LEN];
	printf("请输入你要查找的书籍名称\n");
	scanf("%s", title);
	int search = FindByTitle(pc, title);
	if (search == -1)
	{
		printf("没有找到你想要的书籍\n");
		return;
	}
	printf("找到了\n");
	printf("书的名称是:>%s\n", pc->data[search].Book_title);
	printf("书的作者是:>%s\n", pc->data[search].Book_author);
	printf("书的ID是:>%d\n", pc->data[search].Book_id);
	printf("书的出版商是:>%s\n", pc->data[search].Book_Publisher);
}

void ModifyLibrary(library* pc)
{
	assert(pc);
	char title[MAX_TITLE_LEN];
	printf("请输入要修改的书籍名称:>");
	scanf("%s", title);
	int mod = FindByTitle(pc, title);
	if (mod == -1)
	{
		printf("没有找到该书籍\n");
		return;
	}
	printf("请你重新录入一遍信息\n");
	printf("请输入书本ID：>");
	scanf("%d", &(pc->data[pc->sz].Book_id));
	printf("请输入书名：>");
	scanf("%d", pc->data[pc->sz].Book_title);
	printf("请输入作者：>");
	scanf("%d", pc->data[pc->sz].Book_author);
	printf("请输入出版社：>");
	scanf("%d", pc->data[pc->sz].Book_Publisher);

	printf("修改成功！\n");
}


void SortLibrary(const library* pc)
{
	int i, j = 0;
	BooksInfo temp_book;
	for (i = 0; i < pc->sz - 1; i++)
	{
		int count = 0;
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (pc->data[j].Book_id > pc->data[j + 1].Book_id)
			{
				temp_book = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = temp_book;
				count = 1;
			}
		}
		if (count == 0)
			break;
	}
	printf("按照书的ID号排序成功\n");
	int k = 0;
	printf("%-15s\t%-10s\t%-5s\t%-10s\n", "书名", "作者名", "ID号", "出版商");
	for (k = 0; k < pc->sz; k++)
	{
		printf("%-15s\t%-10s\t%-5d\t%-10s\n",
			pc->data[k].Book_title,
			pc->data[k].Book_author,
			pc->data[k].Book_id,
			pc->data[k].Book_Publisher);

	}
}
void DestroyLibrary(library* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;

}
void SaveLibrary(library* pc)
{
	FILE* pf = fopen("my_library.data", "wb");
	if (pf == NULL)
	{
		perror("SaveLibrary");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(BooksInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
