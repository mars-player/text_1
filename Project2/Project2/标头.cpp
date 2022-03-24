#include <stdio.h>
#include "标头.h"
#include <malloc.h>
void CreateListR(PolyNode*& L, double a[], int b[], int n) /*尾插法创建多项式单链表*/
{
	PolyNode* s, * tc;
	int i;
	L = (PolyNode*)malloc(sizeof(PolyNode));
	tc = L;
	for (i = 0; i < n; i++)
	{
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->coef = a[i];
		s->exp = b[i];
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}

void DestroyList(PolyNode*& L) /*销毁线性表*/
{
	PolyNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

void DispPoly(PolyNode* L) /*输出多项式单链表*/
{
	PolyNode* p = L->next;
	while (p != NULL)
	{
		printf("(%gx^%d)", p->coef, p->exp);
		p = p->next;
	}
	printf("\n");
}

void Add(PolyNode* ha, PolyNode* hb, PolyNode*& hc) /*两个有序多项式单链表相加运算*/
{
	PolyNode* pa = ha->next, * pb = hb->next, * s, * tc;
	double c;
	hc = (PolyNode*)malloc(sizeof(PolyNode));
	tc = hc;
	while (pa != NULL && pb != NULL)
	{
		if (pa->exp > pb->exp)
		{
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->exp = pa->exp; s->coef = pa->coef;
			tc->next = s;
			tc = s;
			pa = pa->next;
		}
		else if (pa->exp < pb->exp)
		{
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->exp = pb->exp; s->coef = pb->coef;
			tc->next = s;
			tc = s;
			pb = pb->next;
		}
		else /*pa->exp = pb->exp*/
		{
			c = pa->coef + pb->coef;
			if (c != 0) /*系数之和不为0时创建新结点*/
			{
				s = (PolyNode*)malloc(sizeof(PolyNode));
				s->exp = pa->exp; s->coef = c;
				tc->next = s;
				tc = s;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}
	if (pb != NULL)pa = pb; /*复制余下的结点*/
	while (pa != NULL)
	{
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->exp = pa->exp;
		s->coef = pa->coef;
		tc->next = s; tc = s;
		pa = pa->next;
	}
	tc->next = NULL;
}