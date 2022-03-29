typedef int ElemType;
#define MaxSize 20
typedef struct
{
	ElemType data[MaxSize];
	int front;
	int count;
}SQueue;

//----�ӳ�ʼ���㷨----
void InitQueue(SQueue& qu)
{
	qu.front = qu.count = 0;
}

//----���ٶ����㷨----
void DestroyQueue(SQueue qu)
{};

//----Ԫ�ؽ����㷨----
int EnQueue(SQueue& sq, ElemType x)
{
	if (sq.count == MaxSize)return 0;
	sq.count++;
	sq.data[(sq.front + sq.count) % MaxSize] = x;
	return 1;
}

//----����Ԫ���㷨----
int DeQueue(SQueue& sq, ElemType& x)
{
	if (sq.count == 0)return 0;
	sq.count--;
	sq.front = (sq.front + 1) % MaxSize;
	x = sq.data[sq.front];
	return 1;
}

//----ȡ��ͷԪ���㷨----
int GetHead(SQueue sq, ElemType& x)
{
	if (sq.count == 0)return 0;
	x = sq.data[(sq.front + 1) % MaxSize];
	return 1; 
}

//----�жϿ��㷨----
int QueueEmpty(SQueue sq)
{
	if (sq.count == 0)return 1;
	else return 0;
}