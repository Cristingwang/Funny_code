#include "sort.h"
#include"stack.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void PrintArray(int* a, int n)//打印数组
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)//直接插入法
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
void ShellSort(int* a, int n)//希尔排序
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
void BubbleSort(int* a, int n)//冒泡排序
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

void SelectSort(int* a, int left,int right)//选择排序
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
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	InitStack(&st);
	PushStack(&st, end);
	PushStack(&st, begin);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		PopStack(&st);
		int right = StackTop(&st);
		PopStack(&st);
		int keyi = PartSort1(a, left, right);
		if (right > keyi + 1)
		{
			PushStack(&st, right);
			PushStack(&st, keyi + 1);
		}
		if (left < keyi - 1)
		{
			PushStack(&st, keyi - 1);
			PushStack(&st, left);
		}

	}
	DestroyStack(&st);
}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	/*if (left == right)
		return;*/
	if (right - left + 1 <= 10)//最小区间优化
	{
		QuickSort(a, left, right);
		return;
	}
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int start1 = left, end1 = mid;
	int start2 = mid + 1, end2 = right;
	int i = left;
	while (start1 <= end1 && start2 <= end2)
	{
		if (a[start1] <=a[start2])
			tmp[i++] = a[start1++];
		else
			tmp[i++] = a[start2++];
	}
	while (start1 <= end1)
	{
		tmp[i++] = a[start1++];
	}
	while (start2 <= end2)
	{
		tmp[i++] = a[start2++];
	}
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i = i + 2 * gap)
		{
			int start1 = i, end1 = i + gap - 1;
			int start2 = i + gap, end2 = i + 2 * gap - 1;
			if (end1 >= n ||start2 >= n)
				break;
			if (end2 >= n)
				end2 = n - 1;
			while (start1 <= end1 && start2 <= end2)
			{
				if (a[start1] <= a[start2])
					tmp[j++] = a[start1++];
				else
					tmp[j++] = a[start2++];
			}
			while (start1 <= end1)
			{
				tmp[j++] = a[start1++];
			}
			while (start2 <= end2)
			{
				tmp[j++] = a[start2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2-i+1));
		}
		gap *= 2;
	}
	free(tmp);
}
void MergeSortNonR1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{
			int start1 = i, end1 = i + gap - 1;
			int start2 = i + gap, end2 = i + 2 * gap - 1;
			if (end1 >= n)
			{
				end1 = n - 1;
				start2 = n;
				end2 = n - 1;
			}
			else if(start2>=n)
			{
				start2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (start1 <= end1 && start2 <= end2)
			{
				if (a[start1] <= a[start2])
					tmp[j++] = a[start1++];
				else
					tmp[j++] = a[start2++];
			}
			while (start1 <= end1)
			{
				tmp[j++] = a[start1++];
			}
			while (start2 <= end2)
			{
				tmp[j++] = a[start2++];
			}
		}
		memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int gap = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int) * gap);
	memset(tmp, 0, sizeof(int) * gap);
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < gap; i++)
	{
		while (tmp[i]--)
		{
			a[j++] = i + min;
		}
	}
}



