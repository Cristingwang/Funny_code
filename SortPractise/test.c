#include"sort.h"
void TestInsertSort()
{
	int a[] = { 2,5,8,4,6,7,15,26,0,2,4 };
	int n = sizeof(a) / sizeof(int);
	InsertSort(a, n);
	PrintArray(a, n);
}
void TestShellSort()
{
	int a[] = { 2,5,8,4,6,7,15,26,0,2,4 };
	int n = sizeof(a) / sizeof(int);
	ShellSort(a, n);
	PrintArray(a, n);
}
int main()
{
	//TestShellSort();
	int a[] = { 1,9,5,2,7,5,3,4,0,1 };
	int n = sizeof(a) / sizeof(int);
	PrintArray(a, n);
	//BubbleSort(a, n);
	//PrintArray(a, n);
	//SelectSort(a, 0,n-1);
	//HeapSort(a, n);
	QuickSort(a, 0, n - 1);
	PrintArray(a, n);
	return 0;
}