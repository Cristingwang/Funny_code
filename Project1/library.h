#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_NAME_LEN 50
#define MAX_PUBLISHER_LEN 50
#define DEFAULT_SZ 5
#define INC_SZ 2

enum option
{
    out,
    add,
    del,
    show,
    modify,
    search,
    sort
};


typedef struct book
{
    int Book_id;                            // �鱾ID
    char Book_title[MAX_TITLE_LEN];         // ����
    char Book_author[MAX_AUTHOR_NAME_LEN];  // ����
    char Book_Publisher[MAX_PUBLISHER_LEN]; // ������
    /* char Book_Publication_Date[20];         // �״γ�������
     char Book_language[6];                  // ����
     bool Availability_status;               // ����״̬
     char Borrowing_history[2][10];          // ������ʷ�������������ں͹黹����
     int Book_copies_amount;                 // ��������
     char Book_ISBN[13];                     // ȫ��Ψһ�ı�ʶ�鼮�ı��
     char Book_keywords[10][10];             // �ؼ���
     char Book_category[10];                 // ����
     bool Is_eBook;*/                          // �Ƿ��е�����汾
}BooksInfo;

typedef struct library
{
    BooksInfo* data;//ָ���˴�����ݵĿռ�
    int sz;//��¼�ĵ�ǰ�ŵ���ЧԪ�صĸ���
    int capacity;//ͼ��ݵ�ǰ���������
}library;

//��������
void InitLibrary(library* pc);
void AddLibrary(library* pc);
void DelLibrary(library* pc);
void ShowLibrary(const library* pc);
void SortLibrary(const library* pc);
void SearchLibrary(const library* pc);
void ModifyLibrary(library* pc);
void DestroyLibrary(library* pc);
void SaveLibrary(library* pc);

