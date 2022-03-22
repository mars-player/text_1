#include <stdio.h>
#include "��ͷ.h"
void InitList(DLinkNode*& L) /*��ʼ������*/
{
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = L;
}

void DestroyList(DLinkNode*& L) /*��������*/
{
	DLinkNode* pre = L, * p = pre->next;
	while (p!=L)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

int GetLength(DLinkNode* L) /*�����Ա���*/
{
	int i = 0;
	DLinkNode* p = L->next;
	while (p != L)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(DLinkNode* L, int i, ElemType& e) /*��ֵ��������*/
{
	int j = 1;
	DLinkNode* p = L->next;
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

int InsElem(DLinkNode*& L, ElemType x, int i) /*����Ԫ��*/
{
	int j = 1;
	DLinkNode* p = L->next, * pre, * s;
	if (i <= 0)return 0;
	while (p != L && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == L && i > j + 1)return 0;
	else
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = x;
		pre = p->prior;
		s->prior = pre; pre->next = s;
		p->prior = s; s->next = p;
		return 1;
	}
}

void DispList(DLinkNode* L) /*������Ա�*/
{
	DLinkNode* p = L->next;
	while (p != L)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void Reverse(DLinkNode*& L) /*����ͷ����˫����L�еĽ������*/
{
	DLinkNode* p = L->next, * q;
	L->next = L->prior = L;
	while (p != L)
	{
		q = p->next;
		p->next = L->next;
		L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;
	}
}

int Symmetric(DLinkNode* L)
{
	int flag = 1;
	DLinkNode* p = L->next, * q = L->prior;
	while (flag == 1)
	{
		if (p->data != q->data)
			flag = 0;
		else
		{
			if (p == q || p->next == q)
				break;
			p = p->next;
			q = q->prior;
		}
	}
	return flag;
}

int Locate(DLinkNode* L, ElemType x) /*���һ��ֵΪx�����߼����*/
{
	int i = 1;
	DLinkNode* p = L->next;
	while (p != NULL && p->data != x)
	{
		p = p->next;
		i++;
	}
	if (p == L)return 0;
	else return i;
}

int DelElem(DLinkNode*& L, int i) /*ɾ����i�����*/
{
	int j = 1;
	DLinkNode* p = L->next, * pre;
	if (i <= 0)return 0;
	if (L->next == L)return 0;
	while (p != L && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == L)return 0;
	else
	{
		pre = p->prior;
		p->next->prior = pre;
		pre->next = p->next;
		free(p);
		return 1;
	}
}

void CreateListF(DLinkNode*& L, ElemType a[], int n) /*ͷ�巨����ѭ��˫����L*/
{
	DLinkNode* s;  int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = L;
	L->prior = L;
	for (i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

void CreateListR(DLinkNode*& L, ElemType a[], int n) /*β�巨����ѭ��˫����L*/
{
	DLinkNode* s, * tc;
	int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	tc = L;
	for (i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		tc->next = s;
		s->prior = tc;
		tc = s;
	}
	tc->next = L;
	L->prior = tc;
}