#include <stdio.h>
#include <malloc.h>
#include "��ͷ.h"
void InitStack(LinkStack*& ls) /*��ʼ�����Ա�*/
{
	ls = NULL;
}

void DestroyStack(LinkStack*& ls) /*����������*/
{
	LinkStack* pre = ls, * p;
	if (pre == NULL)return;
	p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

int Push(LinkStack*& ls, ElemType x) /*��ջ����*/
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = ls;
	ls = p;
	return 1;
}

int Pop(LinkStack*& ls, ElemType& x) /*��ջ����*/
{
	LinkStack* p;
	if (ls == NULL)
		return 0;
	else
	{
		p = ls;
		x = p->data;
		ls = p->next;
		free(p);
		return 1;
	}
}

int GetTop(LinkStack* ls, ElemType& x) /*ȡջ��Ԫ���㷨*/
{
	if (ls == NULL)
		return 0;
	else
	{
		x = ls->data;
		return 1;
	}
}

int StackEmpty(LinkStack* ls) /*�ж�ջ������*/
{
	if (ls == NULL)
		return 1;
	else
		return 0;
}

