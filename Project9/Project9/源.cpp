#include "��ͷ.h"
#include <stdio.h>
int main(void)
{
	LinkQueue* lq;
	ElemType e;
	printf("��ʼ������\n");
	InitQueue(lq);
	printf("��%s\n", (QueueEmpty(lq) == 1 ? "��" : "����"));
	printf("a ����\n"); EnQueue(lq, 'a');
	printf("b ����\n"); EnQueue(lq, 'b');
	printf("c ����\n"); EnQueue(lq, 'c');
	printf("d ����\n"); EnQueue(lq, 'd');
	printf("��%s\n", (QueueEmpty(lq) == 1 ? "��" : "����"));
	GetHead(lq, e);
	printf("��ͷԪ��:%c\n", e);
	printf("���Ӵ���:");
	while (!QueueEmpty(lq))
	{
		DeQueue(lq, e);
		printf("%c", e);
	}
	printf("\n");
	DestroyQueue(lq);
}