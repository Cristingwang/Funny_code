#include "sort.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void PrintArray(int* a, int n)//´òÓ¡Êý×é
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)//Ö±½Ó²åÈë·¨
{
	for (int i = 1; i < n; i++)
	{
		int tmp = a[i];
		int end = i - 1;
		while (end >= 0)
		{
			if (tmp >=a[end])
				break;
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)//Ï£¶ûÅÅÐò
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int tmp = a[i + gap];
			int end = i;
			while (end >= 0)
			{
				if (a[end] <= tmp)
				{
					break;
				}
				else
				{
					a[end + gap] = a[end];
					end -= gap;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void BubbleSort(int* a, int n)//Ã°ÅÝÅÅÐò
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j] < a[j - 1])
				Swap(&a[j], &a[j - 1]);
		}
	}
}

void SelectSort(int* a, int left,int right)//Ñ¡ÔñÅÅÐò
{
	int mini = left;
	int maxi = left;
	while (left < right)
	{
		for (int i = left; i <= right ; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[left], &a[mini]);
		if (left == maxi)
		{
			maxi = mini;
		}
		Swap(&a[right], &a[maxi]);
		left++;
		right--;
	} 
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n&&a[child + 1] > a[child])
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDown(a, n, i);
	int end = n - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
int PartSort1(int* a, int begin, int end)
{
	int keyi = begin;
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			end--;
		while (begin < end && a[begin] <= key)
			begin++;
		Swap(&a[end], &a[begin]);
	}
	Swap(&a[end], &a[keyi]);
	return end;
}
int PartSort2(int* a, int begin, int end)
{
	int key= a[begin];
	int hole = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			end--;
		a[hole] = a[end];
		hole = end;
		while (begin < end && a[begin] <= key)
			begin++;
		a[hole] = a[begin];
		hole = begin;
	}
	a[hole] = key;
}
int PartSort3(int* a, int begin, int end)
{
	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < key)
		{
			prev++;
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[begin], &a[prev]);
	return prev;
}


void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyi=PartSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

