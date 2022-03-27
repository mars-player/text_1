typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}LinkStack;

void InitStack(LinkStack*& ls);
void DestroyStack(LinkStack*& ls);
int Push(LinkStack*& ls, ElemType x);
int Pop(LinkStack*& ls, ElemType& x);
int GetTop(LinkStack* ls, ElemType& x);
int StackEmpty(LinkStack* ls);

