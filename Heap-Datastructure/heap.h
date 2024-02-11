#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int MyDataType;
typedef struct Heap
{
	MyDataType* a;
	int capacity;
	int size;
}HP;

void AdjustUp(MyDataType* a,int child);
void AdjustDown(MyDataType* a, int n, int parent);
void Swap(MyDataType* x, MyDataType* y);
void HeapPrint(HP* php);


void InitHeap(HP*php);
void DestroyHeap(HP*php);
void PushHeap(HP*php ,MyDataType x);
void PopHeap(HP*php);
MyDataType HeapTop(HP*php);
bool HeapEmpty(HP*php);
