#include "标头.h"
#include <stdio.h>
void InitQueue(SqQueue& sq) /*初始化队列运算*/
{
	sq.rear = sq.front = 0;
}

void DestroyQueue(SqQueue sq)
{}

int DeQueue(SqQueue& sq, ElemType& x) /*出队运算*/
{
	if (sq.rear == sq.front)
		return 0;
	sq.front = (sq.front + 1) % MaxSize;
	x = sq.data[sq.front];
	return 1;
}

int EnQueue(SqQueue& sq, ElemType x) /*进队运算*/
{
	if ((sq.rear + 1) % MaxSize == sq.front)
		return 0;
	sq.rear = (sq.rear + 1) % MaxSize;
	sq.data[sq.rear] = x;
	return 1;
}

int GetHead(SqQueue sq, ElemType& x) /*取队头元素算法*/
{
	if (sq.rear = sq.front)
		return 0;
	x = sq.data[(sq.front + 1) % MaxSize];
		return 1;
}

int QueueEmpty(SqQueue sq) /*判断队空运算*/
{
	if (sq.rear == sq.front) return 1;
	else return 0;
}