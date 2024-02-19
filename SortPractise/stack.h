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

void  InitStack(ST*ps);//ջ�ĳ�ʼ��
void  PushStack(ST* ps,MyDataType x);//�������ݵ�ջ
void  PopStack(ST* ps);//��ջ��ɾ������
void DestroyStack(ST* ps);//ջ������
bool StackEmpty(ST* ps);//ջ���п�
MyDataType StackTop(ST* ps);//��ȡջ��Ԫ��
int StackSize(ST* ps);//��ȡջ��Ԫ�ظ���

