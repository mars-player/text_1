#include <stdio.h>
#include <malloc.h>
#include "标头.h"
void InitStack(LinkStack*& ls) /*初始化线性表*/
{
	ls = NULL;
}

void DestroyStack(LinkStack*& ls) /*销毁线运算*/
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

int Push(LinkStack*& ls, ElemType x) /*进栈运算*/
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = ls;
	ls = p;
	return 1;
}

int Pop(LinkStack*& ls, ElemType& x) /*出栈运算*/
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

int GetTop(LinkStack* ls, ElemType& x) /*取栈顶元素算法*/
{
	if (ls == NULL)
		return 0;
	else
	{
		x = ls->data;
		return 1;
	}
}

int StackEmpty(LinkStack* ls) /*判断栈空运算*/
{
	if (ls == NULL)
		return 1;
	else
		return 0;
}

