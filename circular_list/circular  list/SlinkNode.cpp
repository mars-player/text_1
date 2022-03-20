#include "��ͷ.h"
#include <malloc.h>
#include <stdio.h>
void InitList(SlinkNode*& L) /*��ʼ�����Ա�*/
{
	L = (SlinkNode*)malloc(sizeof(SlinkNode));
	L->next = L;
}

int GetLength(SlinkNode* L) /*�����Ա�ĳ���*/
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

int GetElem(SlinkNode* L, int i, ElemType& e) /*�����Ա��е�i��Ԫ��*/
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

void DestroyList(SlinkNode*& L) /*�������Ա�*/
{
	SlinkNode* pre = L, * p = pre->next;
	while (p != L)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

int Locate(SlinkNode* L, ElemType x) /*��ֵ���������㷨*/
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

int InsElem(SlinkNode*& L, ElemType x, int i) /*����Ԫ��*/
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

int DelElem(SlinkNode*& L, int i) /*ɾ��Ԫ��*/
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

void DispList(SlinkNode* L) /*���Ԫ��*/
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

	/*int Delallx(SlinkNode*& L, ElemType x)  ɾ��һ�����������ѭ��������L������ֵΪx�Ľ��
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