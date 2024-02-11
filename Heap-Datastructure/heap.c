#include "heap.h"
void Swap(MyDataType*x,MyDataType*y)
{
	MyDataType temp = 0;
	temp = *x;
	*y = *x;
	*y = temp;
}
void InitHeap(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void DestroyHeap(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	free(php);
}
void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < (php->size - 1); i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
void AdjustUp(MyDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(MyDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (parent < n)
	{
		if (child + 1 < n&&a[child+1]<a[child])
		{
			child +=1;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child],& a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void PushHeap(HP*php,MyDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int Newsize = php->capacity == 0 ? 4:php->capacity * 2;
		MyDataType* tmp = (MyDataType*)realloc(php->a, Newsize);
		if (tmp == NULL)
		{
			perror("perror fail");
			exit(-1);
		}
		php->a = tmp;
	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
	
}
void PopHeap(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
MyDataType HeapTop(HP*php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}
bool HeapEmpty(HP*php)
{
	if (php->a == NULL)
		return true;
	else
		return false;
}
