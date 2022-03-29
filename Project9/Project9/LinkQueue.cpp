#include "��ͷ.h"
#include <stdio.h>
#include <malloc.h>
void InitQueue(LinkQueue*& lq) /*��ʼ����������*/
{
	lq = (LinkQueue*)malloc(sizeof(LinkQueue));
	lq->rear = lq->front = NULL;
}

void DestroyQueue(LinkQueue*& lq) /*���ٶ�������*/
{
	QType* pre = lq->front, * p;
	if (pre != NULL)            //�ǿնӵ����
	{
		if (pre == lq->rear)    //ֻ��һ�����ݽ������
			free(pre);          //�ͷ�pre���
  		else                    
		{p = pre->next;    
			while (p != NULL)   
			{
				free(pre);      
				pre = p; p = p->next; //pre��pͬ������
			}
			free(pre);          //�ͷ�β���
		}
	}
	free(lq);                   //�ͷ����ӽ��
}

int EnQueue(LinkQueue*& lq, ElemType x) /*��������*/
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

int DeQueue(LinkQueue*& lq, ElemType& x) /*��������*/
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

int GetHead(LinkQueue* lq, ElemType& x) /*ȡ��ͷԪ������*/
{
	if (lq->front == NULL)
		return 0;
	x = lq->front->data;
	return 1;
}

int QueueEmpty(LinkQueue* lq) /*�ж϶ӿ�����*/
{
	if (lq->front == NULL)return 1;
	else return 0;
}

