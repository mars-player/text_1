#include "��ͷ.h"
#include <stdio.h>
int main(void)
{
	SqQueue sq;
	ElemType e;
	printf("��ʼ������\n");
	InitQueue(sq);
	printf("��%s\n", (QueueEmpty(sq) == 1 ? "��" : "����"));
	printf("����h\n"); EnQueue(sq, 'h');
	printf("����b\n"); EnQueue(sq, 'b');
	printf("����c\n"); EnQueue(sq, 'c');
	printf("����d\n"); EnQueue(sq, 'd');
	printf("%s\n", (QueueEmpty(sq) == 1 ? "��" : "����"));
	GetHead(sq, e);
	printf("��ͷԪ��:%c\n", e);
	printf("���Ӵ���:");
	while (!QueueEmpty(sq))
	{
		DeQueue(sq, e);
		printf("%c ", e);
	}
	printf("\n");
	DestroyQueue(sq);
}
