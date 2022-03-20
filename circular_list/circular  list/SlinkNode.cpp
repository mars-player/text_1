#include "标头.h"
#include <malloc.h>
#include <stdio.h>
void InitList(SlinkNode*& L) /*初始化线性表*/
{
	L = (SlinkNode*)malloc(sizeof(SlinkNode));
	L->next = L;
}

int GetLength(SlinkNode* L) /*求线性表的长度*/
{
	int i = 0;
	SlinkNode* p = L->next;
	while (p != L)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(SlinkNode* L, int i, ElemType& e) /*求线性表中第i个元素*/
{
	int j = 1;
	SlinkNode* p = L->next;
	if (i <= 0)return 0;
	while (p != L && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == L)return 0;
	else
	{
		e = p->data;
		return 1;
	}
}

void DestroyList(SlinkNode*& L) /*销毁线性表*/
{
	SlinkNode* pre = L, * p = pre->next;
	while (p != L)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

int Locate(SlinkNode* L, ElemType x) /*按值查找运算算法*/
{
	int i = 1;
	SlinkNode* p = L->next;
	while (p != L && p->data != x)
	{
		p->next;
		i++;
	}
	if (p == L)return 0;
	else return i;
}

int InsElem(SlinkNode*& L, ElemType x, int i) /*插入元素*/
{
	int j = 1;
	SlinkNode* pre = L, * p = pre->next, * s;
	if (i <= 0)return 0;
	while (p != L && j < i)
	{
		j++;
		pre = p; p = p->next;
	}
	if (p == L && i > j + 1)return 0;
	else
	{
		s = (SlinkNode*)malloc(sizeof(SlinkNode));
		s->data = x;
		s->next = pre->next;
		pre->next = s;
		return 1;
	}
}

int DelElem(SlinkNode*& L, int i) /*删除元素*/
{
	int j = 0;
	SlinkNode* p = L, * post;
	if (i <= 0)return 0;
	while (p->next != L && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p->next == L)return 0;
	else
	{
		post = p->next;
		if (post == L)
			return 0;
		else
		{
			p->next = post->next;
			free(post);
			return 1;
		}
	}
}

void DispList(SlinkNode* L) /*输出元素*/
{
	SlinkNode* p = L->next;
	while (p != L)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

	/*int Nodes(SlinkNode* L, ElemType x)
	{
		int i = 0;
		SlinkNode* p = L->next;
		while (p != L)
		{
			if (p->data == x) i++;
			p = p->next;
		}
		return i;
	}*/

	/*int Delallx(SlinkNode*& L, ElemType x)  删除一个递增有序的循环单链表L中所有值为x的结点
	{
		SlinkNode* pre = L, * p = L->next;
		while (p != L && p->data != x)
		{
			pre = p;
			p = p->next;
		}
		if (p == L)return 0;
		while (p!=L && p->data ==x)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		return 1;
	}*/