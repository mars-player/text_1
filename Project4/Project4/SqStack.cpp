#include"��ͷ.h"
void InitStack(SqStack& st) /*��ʼ��ջ�����㷨*/
{
	st.top = -1;
}

void DestroyStack(SqStack st) /*����ջ����*/
{}

int Push(SqStack& st, ElemType x) /*��ջ����*/
{
	if (st.top == MaxSize - 1)
		return 0;
	else
	{
		st.top++;
		st.data[st.top] = x;
		return 1;
	}
}

int Pop(SqStack& st, ElemType& x) /*��ջ����*/
{
	if (st.top == -1)
		return 0;
	else
	{
		x = st.data[st.top];
		st.top--;
		return 1;
	}
}

int GetTop(SqStack st, ElemType& x) /*ȡջ��Ԫ������*/
{
	if (st.top == -1)
		return 0;
	else
	{
		x = st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st) /*�ж�ջ��Ԫ��*/
{
	if (st.top == -1) return 1;
	else return 0;
}