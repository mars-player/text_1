#include "标头.h"
#include <stdio.h>
int main(void)
{
	SqQueue sq;
	ElemType e;
	printf("初始化队列\n");
	InitQueue(sq);
	printf("队%s\n", (QueueEmpty(sq) == 1 ? "空" : "不空"));
	printf("进队h\n"); EnQueue(sq, 'h');
	printf("进队b\n"); EnQueue(sq, 'b');
	printf("进队c\n"); EnQueue(sq, 'c');
	printf("进队d\n"); EnQueue(sq, 'd');
	printf("%s\n", (QueueEmpty(sq) == 1 ? "空" : "不空"));
	GetHead(sq, e);
	printf("队头元素:%c\n", e);
	printf("出队次序:");
	while (!QueueEmpty(sq))
	{
		DeQueue(sq, e);
		printf("%c ", e);
	}
	printf("\n");
	DestroyQueue(sq);
}
