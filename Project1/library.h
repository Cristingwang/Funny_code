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
    int Book_id;                            // 书本ID
    char Book_title[MAX_TITLE_LEN];         // 书名
    char Book_author[MAX_AUTHOR_NAME_LEN];  // 作者
    char Book_Publisher[MAX_PUBLISHER_LEN]; // 出版社
    /* char Book_Publication_Date[20];         // 首次出版日期
     char Book_language[6];                  // 语言
     bool Availability_status;               // 借阅状态
     char Borrowing_history[2][10];          // 借阅历史，包括借阅日期和归还日期
     int Book_copies_amount;                 // 副本数量
     char Book_ISBN[13];                     // 全球唯一的标识书籍的编号
     char Book_keywords[10][10];             // 关键词
     char Book_category[10];                 // 种类
     bool Is_eBook;*/                          // 是否有电子书版本
}BooksInfo;

typedef struct library
{
    BooksInfo* data;//指向了存放数据的空间
    int sz;//记录的当前放的有效元素的个数
    int capacity;//图书馆当前的最大容量
}library;

//函数申明
void InitLibrary(library* pc);
void AddLibrary(library* pc);
void DelLibrary(library* pc);
void ShowLibrary(const library* pc);
void SortLibrary(const library* pc);
void SearchLibrary(const library* pc);
void ModifyLibrary(library* pc);
void DestroyLibrary(library* pc);
void SaveLibrary(library* pc);

