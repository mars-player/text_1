#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;
//----栈的顺序存储表示----
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
 
typedef struct
{
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;

Status InitStack(SqStack& S);
Status DestroyStack(SqStack& S);
Status StackDisplay(SqStack& S);
Status GetTop(SqStack S, SElemType& e);
Status Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
Status StackEmpty(SqStack S);

Status InitStack(SqStack& S) //构造一个空栈S 
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE* sizeof(SElemType));
	if (!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack& S) //销毁栈S 
{
	if (S.base)free(S.base);
	S.top = S.base = NULL;
	return OK;
}

Status StackDisplay(SqStack& S) //显示栈S 
{
	SElemType* p = S.base;
	int i = 0;
	if (S.base == S.top)
	{
		printf("堆栈已空!\n");
		return OK;
	}
	while (p < S.top)
		printf("[%d:%d]", ++i, *p++);
	printf("\n");
	return OK;
	
}

Status GetTop(SqStack S, SElemType& e) //若栈不空，则用e返回S的栈顶元素，并返回OK 
{
	if(S.top == S.base)return ERROR; //否则返回ERROR 
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack& S, SElemType e) //插入元素e为新的栈顶元素 
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (! S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top ++= e;
	return OK;
}

Status Pop(SqStack& S, SElemType& e) //若栈不为空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR 
{
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
} 

Status StackEmpty(SqStack S) //若S为空栈，则返回TRUE，否则返回FALSE 
{
	if (S.top == S.base) return TRUE;
	else return FALSE;
}

int main()
{
	SqStack St;
	Status temp;
	int flag = 1, ch;
	int e;
	printf("本程序实现顺序结构的堆栈操作。\n");
	printf("可以进行入栈，出栈，取栈顶元素等操作。\n");
	InitStack(St);
	while(flag)
	{
		printf("请选择:\n");
		printf("1.显示栈中所有元素	\n");
		printf("2.入栈				\n");
		printf("3.出栈				\n");
		printf("4.取栈顶元素		\n");
		printf("5.退出程序			\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				StackDisplay(St);
				break;
			case 2:
				printf("请输入一个要入栈的元素(一个元素):");
				scanf("%d", &e);
				temp = Push(St, e);
				if(temp != OK) printf("堆栈已满！入栈失败!\n");
				else
				{
					printf("成功入栈！\n");
					StackDisplay(St);
				} 
				break;
			case 3:
				temp = Pop(St, e);
				if (temp == ERROR) printf("堆栈已空！\n");
				else
				{
					printf("成功出栈一个元素:%d\n", e);
					StackDisplay(St);
				}\
				break;
			case 4:
				temp = GetTop(St, e);
				if (temp == ERROR) printf("堆栈已空！\n");
				else printf("栈顶元素是:%d\n", e);
				break;
			default:
				flag = 0;
				printf("程序结束，按任意键退出!\n");
				getch();
		} 
	}
	DestroyStack(St);
}
