#define MaxSize 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& st);
void DestroyStack(SqStack st);
int Push(SqStack& st, char x);
int Pop(SqStack& st, ElemType& x);
int GetTop(SqStack st, ElemType& x);
int StackEmpty(SqStack st);
 
