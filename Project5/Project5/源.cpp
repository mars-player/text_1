#include "标头.h"
#include <stdio.h>
int main(void)
{
	ElemType e;
	LinkStack* st;
	printf("初始化栈st\n");
	InitStack(st);
	printf("栈%s\n", (StackEmpty(st) == 1 ? "空" : "不空"));
	printf("进栈a\n"); Push(st, 'a');
	printf("进栈b\n"); Push(st, 'b');
	printf("进栈c\n"); Push(st, 'c');
	printf("进栈d\n"); Push(st, 'd');
	printf("栈%s\n", (StackEmpty(st) == 1 ? "空" : "不空"));
	GetTop(st, e);
	printf("栈顶元素:%c\n", e);
	printf("出栈次序:");
	while (!StackEmpty(st)) /*栈不空循环*/
	{
		Pop(st, e); /*出栈元素e并输出*/
		printf("%c", e);
	}
	printf("\n");
	DestroyStack(st);
}