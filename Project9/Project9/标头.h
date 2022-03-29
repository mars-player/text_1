typedef int ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QType;

typedef struct qptr
{
	QType* front;
	QType* rear;
}LinkQueue;

void InitQueue(LinkQueue*& lq);
void DestroyQueue(LinkQueue*& lq);
int EnQueue(LinkQueue*& lq, ElemType x);
int GetHead(LinkQueue* lq, ElemType& x);
int QueueEmpty(LinkQueue* lq);
int DeQueue(LinkQueue*& lq, ElemType& x);

