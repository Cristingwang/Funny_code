#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int MyDataType;
typedef struct Stack
{
	MyDataType* a;
	int capacity;
	int top;
}ST;

void  InitStack(ST*ps);//栈的初始化
void  PushStack(ST* ps,MyDataType x);//插入数据到栈
void  PopStack(ST* ps);//从栈中删除数据
void DestroyStack(ST* ps);//栈的销毁
bool StackEmpty(ST* ps);//栈的判空
MyDataType StackTop(ST* ps);//读取栈顶元素
int StackSize(ST* ps);//读取栈中元素个数

