#include <cstddef>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}QNode;

//----��ʼ�����������㷨----
void InitQueue(QNode*& lq)
{
	lq == NULL;
}

//----��������----
void DestroyQueue(QNode*& lq)
{
	QNode* pre, * p;
	if (lq != NULL)
	{
		if (lq->next == lq) //ԭ����ֻ��һ�����
			free(lq);
		else                //ԭ���������������ϵĽ��
		{ 
			pre = lq;
			p = pre->next;
			while (p != lq)
			{
				free(pre);
				pre = p;
				p = p->next;
			}
			free(pre);
		}
	}
}

//----���������㷨----
void EnQueue(QNode*& lq, ElemType x)
{
	QNode* s;
	s = (QNode*)malloc(sizeof(QNode));
	s->data = x;
	if (lq == NULL)  //ԭΪ�ն�
	{
		lq = s;
		lq->next = lq; //����ѭ��������
	}
	else            //ԭ�Ӳ��գ����s�嵽��β������lqָ����
	{
		s->next = lq->next;
		lq->next = s;
		lq = s;     //lqָ����s
	}
}

//----����Ԫ���㷨----
int DeQueue(QNode*& lq, ElemType& x)
{
	QNode* s;
	if (lq == NULL)return 0;
	if (lq->next == lq)
	{
		x = lq->data;
		free(lq);
		lq = NULL;
	}
	else
	{
		s = lq->next;
		x = s->data;
		lq->next = s->next;
		free(s);
	}
	return 1;
}

//----ȡ��ͷԪ���㷨----
int GetHead(QNode* lq, ElemType& x)
{
	if (lq == NULL)return 0;
	x = lq->next->data;
	return 1;
}

//----�ж϶ӿ�Ԫ���㷨----
int QueueEmpty(QNode* lq)
{
	if (lq == NULL)return 1;
	else return 0;
}