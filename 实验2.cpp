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
//----ջ��˳��洢��ʾ----
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

Status InitStack(SqStack& S) //����һ����ջS 
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE* sizeof(SElemType));
	if (!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack& S) //����ջS 
{
	if (S.base)free(S.base);
	S.top = S.base = NULL;
	return OK;
}

Status StackDisplay(SqStack& S) //��ʾջS 
{
	SElemType* p = S.base;
	int i = 0;
	if (S.base == S.top)
	{
		printf("��ջ�ѿ�!\n");
		return OK;
	}
	while (p < S.top)
		printf("[%d:%d]", ++i, *p++);
	printf("\n");
	return OK;
	
}

Status GetTop(SqStack S, SElemType& e) //��ջ���գ�����e����S��ջ��Ԫ�أ�������OK 
{
	if(S.top == S.base)return ERROR; //���򷵻�ERROR 
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack& S, SElemType e) //����Ԫ��eΪ�µ�ջ��Ԫ�� 
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

Status Pop(SqStack& S, SElemType& e) //��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR 
{
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
} 

Status StackEmpty(SqStack S) //��SΪ��ջ���򷵻�TRUE�����򷵻�FALSE 
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
	printf("������ʵ��˳��ṹ�Ķ�ջ������\n");
	printf("���Խ�����ջ����ջ��ȡջ��Ԫ�صȲ�����\n");
	InitStack(St);
	while(flag)
	{
		printf("��ѡ��:\n");
		printf("1.��ʾջ������Ԫ��	\n");
		printf("2.��ջ				\n");
		printf("3.��ջ				\n");
		printf("4.ȡջ��Ԫ��		\n");
		printf("5.�˳�����			\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				StackDisplay(St);
				break;
			case 2:
				printf("������һ��Ҫ��ջ��Ԫ��(һ��Ԫ��):");
				scanf("%d", &e);
				temp = Push(St, e);
				if(temp != OK) printf("��ջ��������ջʧ��!\n");
				else
				{
					printf("�ɹ���ջ��\n");
					StackDisplay(St);
				} 
				break;
			case 3:
				temp = Pop(St, e);
				if (temp == ERROR) printf("��ջ�ѿգ�\n");
				else
				{
					printf("�ɹ���ջһ��Ԫ��:%d\n", e);
					StackDisplay(St);
				}\
				break;
			case 4:
				temp = GetTop(St, e);
				if (temp == ERROR) printf("��ջ�ѿգ�\n");
				else printf("ջ��Ԫ����:%d\n", e);
				break;
			default:
				flag = 0;
				printf("�����������������˳�!\n");
				getch();
		} 
	}
	DestroyStack(St);
}
