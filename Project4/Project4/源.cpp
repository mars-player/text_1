#include "��ͷ.h"
#include <stdio.h>
int main(void)
{
	SqStack st;
	ElemType e;
	printf("��ʼ��ջst\n");
	InitStack(st);
	printf("ջ%s\n", (StackEmpty(st) == 1 ? "��" : "����"));
	printf("a��ջ\n"); Push(st, 'a');
	printf("b��ջ\n"); Push(st, 'b');
	printf("c��ջ\n"); Push(st, 'c');
	printf("d��ջ\n"); Push(st, 'd');
	printf("ջ%s\n", (StackEmpty(st) == 1 ? "��" : "����"));
	GetTop(st, e);
	printf(" ջ��Ԫ��: %c\n", e);
	printf(" ��ջ����:");
	while (!StackEmpty(st))
	{
		Pop(st, e);
		printf("%c", e);
	}
	printf("\n");
	DestroyStack(st);
}