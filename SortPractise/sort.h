#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void Swap(int* a, int* b);
void PrintArray(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void BubbleSort(int* a, int n);
void SelectSort(int* a, int left,int right);
void HeapSort(int* a, int n);
void QuickSort(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);
void MergeSort(int* a, int n);
void MergeSortNonR(int* a, int n);
void CountSort(int* a, int n);

