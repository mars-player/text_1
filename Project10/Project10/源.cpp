#include <cstddef>
#include <malloc.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}QNode;

//----初始化队列运算算法----
void InitQueue(QNode*& lq)
{
	lq == NULL;
}

//----销毁链队----
void DestroyQueue(QNode*& lq)
{
	QNode* pre, * p;
	if (lq != NULL)
	{
		if (lq->next == lq) //原队中只有一个结点
			free(lq);
		else                //原队中有两个或以上的结点
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

//----进队运算算法----
void EnQueue(QNode*& lq, ElemType x)
{
	QNode* s;
	s = (QNode*)malloc(sizeof(QNode));
	s->data = x;
	if (lq == NULL)  //原为空队
	{
		lq = s;
		lq->next = lq; //构成循环单链表
	}
	else            //原队不空，结点s插到队尾，并由lq指向它
	{
		s->next = lq->next;
		lq->next = s;
		lq = s;     //lq指向结点s
	}
}

//----出队元素算法----
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

//----取队头元素算法----
int GetHead(QNode* lq, ElemType& x)
{
	if (lq == NULL)return 0;
	x = lq->next->data;
	return 1;
}

//----判断队空元素算法----
int QueueEmpty(QNode* lq)
{
	if (lq == NULL)return 1;
	else return 0;
}