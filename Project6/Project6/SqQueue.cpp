#include "��ͷ.h"
#include <stdio.h>
void InitQueue(SqQueue& sq) /*��ʼ����������*/
{
	sq.rear = sq.front = 0;
}

void DestroyQueue(SqQueue sq)
{}

int DeQueue(SqQueue& sq, ElemType& x) /*��������*/
{
	if (sq.rear == sq.front)
		return 0;
	sq.front = (sq.front + 1) % MaxSize;
	x = sq.data[sq.front];
	return 1;
}

int EnQueue(SqQueue& sq, ElemType x) /*��������*/
{
	if ((sq.rear + 1) % MaxSize == sq.front)
		return 0;
	sq.rear = (sq.rear + 1) % MaxSize;
	sq.data[sq.rear] = x;
	return 1;
}

int GetHead(SqQueue sq, ElemType& x) /*ȡ��ͷԪ���㷨*/
{
	if (sq.rear = sq.front)
		return 0;
	x = sq.data[(sq.front + 1) % MaxSize];
		return 1;
}

int QueueEmpty(SqQueue sq) /*�ж϶ӿ�����*/
{
	if (sq.rear == sq.front) return 1;
	else return 0;
}