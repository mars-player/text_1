typedef int ElemType;
#define MaxSize 20
typedef struct
{
	ElemType data[MaxSize];
	int front;
	int count;
}SQueue;

//----队初始化算法----
void InitQueue(SQueue& qu)
{
	qu.front = qu.count = 0;
}

//----销毁队列算法----
void DestroyQueue(SQueue qu)
{};

//----元素进队算法----
int EnQueue(SQueue& sq, ElemType x)
{
	if (sq.count == MaxSize)return 0;
	sq.count++;
	sq.data[(sq.front + sq.count) % MaxSize] = x;
	return 1;
}

//----出队元素算法----
int DeQueue(SQueue& sq, ElemType& x)
{
	if (sq.count == 0)return 0;
	sq.count--;
	sq.front = (sq.front + 1) % MaxSize;
	x = sq.data[sq.front];
	return 1;
}

//----取队头元素算法----
int GetHead(SQueue sq, ElemType& x)
{
	if (sq.count == 0)return 0;
	x = sq.data[(sq.front + 1) % MaxSize];
	return 1; 
}

//----判断空算法----
int QueueEmpty(SQueue sq)
{
	if (sq.count == 0)return 1;
	else return 0;
}