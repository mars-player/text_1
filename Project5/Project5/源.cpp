#include "��ͷ.h"
#include <stdio.h>
int main(void)
{
	ElemType e;
	LinkStack* st;
	printf("��ʼ��ջst\n");
	InitStack(st);
	printf("ջ%s\n", (StackEmpty(st) == 1 ? "��" : "����"));
	printf("��ջa\n"); Push(st, 'a');
	printf("��ջb\n"); Push(st, 'b');
	printf("��ջc\n"); Push(st, 'c');
	printf("��ջd\n"); Push(st, 'd');
	printf("ջ%s\n", (StackEmpty(st) == 1 ? "��" : "����"));
	GetTop(st, e);
	printf("ջ��Ԫ��:%c\n", e);
	printf("��ջ����:");
	while (!StackEmpty(st)) /*ջ����ѭ��*/
	{
		Pop(st, e); /*��ջԪ��e�����*/
		printf("%c", e);
	}
	printf("\n");
	DestroyStack(st);
}