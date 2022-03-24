#include <stdio.h>
#include "��ͷ.h"
#include <malloc.h>
void CreateListR(PolyNode*& L, double a[], int b[], int n) /*β�巨��������ʽ������*/
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

void DestroyList(PolyNode*& L) /*�������Ա�*/
{
	PolyNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

void DispPoly(PolyNode* L) /*�������ʽ������*/
{
	PolyNode* p = L->next;
	while (p != NULL)
	{
		printf("(%gx^%d)", p->coef, p->exp);
		p = p->next;
	}
	printf("\n");
}

void Add(PolyNode* ha, PolyNode* hb, PolyNode*& hc) /*�����������ʽ�������������*/
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
			if (c != 0) /*ϵ��֮�Ͳ�Ϊ0ʱ�����½��*/
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
	if (pb != NULL)pa = pb; /*�������µĽ��*/
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