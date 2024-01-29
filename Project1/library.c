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
			printf("���ݳɹ�\n");
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
		printf("ͼ����������������\n");
		return;
	}
	printf("�������鱾ID��>");
	scanf("%d", &(pc->data[pc->sz].Book_id));
	printf("������������>");
	scanf("%s", pc->data[pc->sz].Book_title);
	printf("���������ߣ�>");
	scanf("%s", pc->data[pc->sz].Book_author);
	printf("����������磺>");
	scanf("%s", pc->data[pc->sz].Book_Publisher);
	pc->sz++;
	printf("��ӳɹ�\n");
	return;

}
void ShowLibrary(const library* pc)
{
	int i = 0;
	printf("%-15s\t%-10s\t%-5s\t%-10s\n", "����", "������", "ID��", "������");
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
		printf("û�в��飬�޷�ɾ��\n");
		return;
	}
	char title[MAX_TITLE_LEN];
	printf("������Ҫɾ�����鼮����\n");
	scanf("%s", title);
	int del = FindByTitle(pc, title);
	if (del == -1)
	{
		printf("û���ҵ����鼮\n");
		return;

	}
	int i = 0;
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���鼮�ɹ�\n");
}

void SearchLibrary(const library* pc)
{
	assert(pc);
	char title[MAX_TITLE_LEN];
	printf("��������Ҫ���ҵ��鼮����\n");
	scanf("%s", title);
	int search = FindByTitle(pc, title);
	if (search == -1)
	{
		printf("û���ҵ�����Ҫ���鼮\n");
		return;
	}
	printf("�ҵ���\n");
	printf("���������:>%s\n", pc->data[search].Book_title);
	printf("���������:>%s\n", pc->data[search].Book_author);
	printf("���ID��:>%d\n", pc->data[search].Book_id);
	printf("��ĳ�������:>%s\n", pc->data[search].Book_Publisher);
}

void ModifyLibrary(library* pc)
{
	assert(pc);
	char title[MAX_TITLE_LEN];
	printf("������Ҫ�޸ĵ��鼮����:>");
	scanf("%s", title);
	int mod = FindByTitle(pc, title);
	if (mod == -1)
	{
		printf("û���ҵ����鼮\n");
		return;
	}
	printf("��������¼��һ����Ϣ\n");
	printf("�������鱾ID��>");
	scanf("%d", &(pc->data[pc->sz].Book_id));
	printf("������������>");
	scanf("%d", pc->data[pc->sz].Book_title);
	printf("���������ߣ�>");
	scanf("%d", pc->data[pc->sz].Book_author);
	printf("����������磺>");
	scanf("%d", pc->data[pc->sz].Book_Publisher);

	printf("�޸ĳɹ���\n");
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
	printf("�������ID������ɹ�\n");
	int k = 0;
	printf("%-15s\t%-10s\t%-5s\t%-10s\n", "����", "������", "ID��", "������");
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
