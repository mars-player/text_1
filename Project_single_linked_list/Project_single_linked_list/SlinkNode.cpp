#include <stdio.h>
#include <malloc.h>
#include "link.h"

void InitList(SlinkNode*& L)
{
	L = (SlinkNode*)malloc(sizeof(SlinkNode));
	L->next = NULL;
}

void DestroyList(SlinkNode*& L)
{
	SlinkNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);	
}

int GetLength(SlinkNode* L)
{
	int i = 0;
	SlinkNode* p = L->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(SlinkNode* L, int i, ElemType& e)
{
	int j = 0;
	SlinkNode* p = L;
	if (i <= 0) return 0;
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL) return 0;
	else
	{
		e = p->data;
		return 1;
	}
}

int Locate(SlinkNode* L, ElemType e)
{
	SlinkNode* p = L->next;
	int j = 1;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return 0;
	else return (j);
}

int InsElem(SlinkNode*& L, ElemType x, int i)
{
	int j = 0;
	SlinkNode* p = L, * s;
	if (i <= 0) return 0;
	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL) return 0;
	else {
		s = (SlinkNode*)malloc(sizeof(SlinkNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}

int DelElem(SlinkNode*& L, int i)
{
	int j = 0;
	SlinkNode* p = L, * q;
	if (i <= 0) return 0;
	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL) return 0;
	else {
		q = p->next;
		if (q == NULL) return 0;
		else {
			p->next = q->next;
			free(q);
			return 1;
		}
	}
}

void DispList(SlinkNode* L)
{
	SlinkNode* p = L->next;
	while (p != NULL)
	{
		printf(" %d ", p->data);
		p = p->next;
	}
	printf("\n");

}

void CreateListF(SlinkNode*& L, ElemType a[], int n)
{
	SlinkNode* s; int i;
	L = (SlinkNode*)malloc(sizeof(SlinkNode));
	L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (SlinkNode*)malloc(sizeof(SlinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateListR(SlinkNode*& L, ElemType a[], int n)
{
	SlinkNode* s, * tc; int i;
	L = (SlinkNode*)malloc(sizeof(SlinkNode));
	tc = L;
	for (i = 0; i < n; i++)
	{
		s = (SlinkNode*)malloc(sizeof(SlinkNode));
		s->data = a[i];
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}


