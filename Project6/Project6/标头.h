#define MaxSize 20
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue& sq);
void DestroyQueue(SqQueue sq);
int EnQueue(SqQueue& sq, ElemType x);
int DeQueue(SqQueue& sq, ElemType& x);
int GetHead(SqQueue sq, ElemType& x);
int QueueEmpty(SqQueue sq);

