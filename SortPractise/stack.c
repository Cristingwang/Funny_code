#include "stack.h"
void  InitStack(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void  PushStack(ST* ps, MyDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int NewSize = ps->top == 0 ? 4 : ps->capacity * 2;
		MyDataType* temp = (MyDataType*)realloc(ps->a, sizeof(MyDataType) * NewSize);
		if (temp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = NewSize;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void  PopStack(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
		--ps->top;
}
void DestroyStack(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
MyDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top-1];
}
int StackSize(ST* ps)
{
	assert(ps);
	assert(ps->top >= 0);
	return ps->top ;
}