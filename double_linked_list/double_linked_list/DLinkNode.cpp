#include <malloc.h>
#include "��ͷ.h"
void InitList(DLinkNode*& L) /*��ʼ��˫����*/
{
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
}

void DestroyList(DLinkNode*& L) /*�������Ա�*/
{
	DLinkNode* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(p);
}

int GetLength(DLinkNode* L) /*�����Ա���*/
{
	int i = 0;
	DLinkNode* p = L->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(DLinkNode* L, int i, ElemType& e) /*�����Ա��е�i��Ԫ��*/
{
	int j = 0;
	DLinkNode* p = L;
	if (i <= 0)return 0;
	while (p != NULL && j<i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)return 0;
	else {
		e = p->data;
		return 1;
	}
}

int Locate(DLinkNode* L, ElemType e) /*��ֵ��������*/
{
	DLinkNode* p = L->next;
	int i = 1;
	while (p != NULL && p->data != e)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)return 0;
	else return i;
}

int InsElem(DLinkNode*& L, ElemType x, int i) /*����Ԫ��*/
{
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0)return 0;
	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)return 0;
	else
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = x;
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior= s;
		s->prior = p;
		p->next = s;
		return 1;
	}
}

int DelElem(DLinkNode*& L, int i) /*ɾ�����*/
{
	int j = 0;
	DLinkNode* p = L, * pre;
	if (i <= 0)return 0;
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)return 0;
	else
	{
		pre = p->prior;
		if (p->next != NULL)
			p->next->prior = pre;
		pre->next = p->next;
		free(p);
		return 1;
	}
}

void DispList(DLinkNode* L) /*������Ա�*/
{
	DLinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreateListF(DLinkNode*& L, ElemType a[], int n) /*ͷ�巨��������˫����*/
{
	DLinkNode* s;  int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		s->prior = L;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
	}
}

void CreateListR(DLinkNode*& L, ElemType a[], int n) /*β�巨��������˫����*/
{
	DLinkNode* s, * tc; int i;
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
	tc->next = NULL;
}

void Delmax(DLinkNode*& L) /*ɾ�������е�һ�����ֵ*/
{
	DLinkNode* p = L->next, * maxp = p, * pre, * post;
	while (p != NULL)
	{
		if (p->data > maxp->data)
			maxp = p;
		p = p->next;
	}
	pre = maxp->prior;
	post = maxp->next;
	pre->next = post;
	if (post != NULL)
		post->prior = pre;
	free(maxp);
}

int Swap(DLinkNode* L, ElemType x) /*���ҵ�һ��Ԫ��ֵΪx�Ľ�㣬�������̽ڵ���н���*/
{
	DLinkNode* p = L->next, * post;
	while (p != NULL && p->data != x)
	
		p = p->next;
		if (p == NULL)
			return 0;
		else
		{
			post = p->next;
			if (post != NULL)
			{
				p->prior->next = post;
				post->prior = p->prior;
				p->next = post->next;
				if (post->next != NULL)
					post->next->prior = p;
				post->next = p;
				p->prior = post;
				return 1;
			}
			else return 0;
		}
}
