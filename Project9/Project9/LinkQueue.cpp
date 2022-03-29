#include "标头.h"
#include <stdio.h>
#include <malloc.h>
void InitQueue(LinkQueue*& lq) /*初始化队列运算*/
{
	lq = (LinkQueue*)malloc(sizeof(LinkQueue));
	lq->rear = lq->front = NULL;
}

void DestroyQueue(LinkQueue*& lq) /*销毁队列运算*/
{
	QType* pre = lq->front, * p;
	if (pre != NULL)            //非空队的情况
	{
		if (pre == lq->rear)    //只有一个数据结点的情况
			free(pre);          //释放pre结点
  		else                    
		{p = pre->next;    
			while (p != NULL)   
			{
				free(pre);      
				pre = p; p = p->next; //pre、p同步后移
			}
			free(pre);          //释放尾结点
		}
	}
	free(lq);                   //释放链队结点
}

int EnQueue(LinkQueue*& lq, ElemType x) /*进队运算*/
{
	QType* s;
	s = (QType*)malloc(sizeof(QType));
	s->data = x; s->next = NULL;
	if (lq->front == NULL)
		lq->rear = lq->front = s;
	else
	{
		lq->rear->next = s;
		lq->rear = s;
	}
	return 1;
}

int DeQueue(LinkQueue*& lq, ElemType& x) /*出队运算*/
{
	QType* p;
	if (lq->front == NULL)
		return 0;
	p = lq->front;
	x = p->data;
	if (lq->rear == lq->front)
		lq->rear = lq->front = NULL;
	else
		lq->front = lq->front->next;
	free(p);
	return 1; 
}

int GetHead(LinkQueue* lq, ElemType& x) /*取队头元素运算*/
{
	if (lq->front == NULL)
		return 0;
	x = lq->front->data;
	return 1;
}

int QueueEmpty(LinkQueue* lq) /*判断队空运算*/
{
	if (lq->front == NULL)return 1;
	else return 0;
}

