#include "标头.h"
#include <stdio.h>
int main(void)
{
	LinkQueue* lq;
	ElemType e;
	printf("初始化队列\n");
	InitQueue(lq);
	printf("队%s\n", (QueueEmpty(lq) == 1 ? "空" : "不空"));
	printf("a 进队\n"); EnQueue(lq, 'a');
	printf("b 进队\n"); EnQueue(lq, 'b');
	printf("c 进队\n"); EnQueue(lq, 'c');
	printf("d 进队\n"); EnQueue(lq, 'd');
	printf("队%s\n", (QueueEmpty(lq) == 1 ? "空" : "不空"));
	GetHead(lq, e);
	printf("队头元素:%c\n", e);
	printf("出队次序:");
	while (!QueueEmpty(lq))
	{
		DeQueue(lq, e);
		printf("%c", e);
	}
	printf("\n");
	DestroyQueue(lq);
}