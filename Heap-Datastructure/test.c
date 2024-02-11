#include"heap.h"
void Test1()
{
	HP hp;
	InitHeap(&hp);
	PushHeap(&hp, 7);
	PushHeap(&hp, 12);
	PushHeap(&hp, 90);
	PushHeap(&hp, 78);
	PushHeap(&hp, 23);
	printf("%d\n", HeapTop(&hp));
	HeapPrint(&hp);
	PopHeap(&hp);
	PopHeap(&hp);
	HeapPrint(&hp);
	DestroyHeap(&hp);
}
int main()
{
	Test1();
	return 0;
}
