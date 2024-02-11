#include "heap.h"
void HeapSort(MyDataType* a,int n)
{
	for (int i = (n - 1 - 1) / 2; i > 0; i--)
		AdjustDown(a, n, i);
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		end--;
		AdjustDown(a, end, 0);
	}
}
