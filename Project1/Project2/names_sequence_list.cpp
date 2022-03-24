#include "names_sequence_list.h"
#include <stdio.h>
void InitList(Sqlist& L)
{
	L.length = 0;
}

void DestroyList(Sqlist L)
{  }

int GetLength(Sqlist L)
{
	return L.length;
}

int GetElem(Sqlist L, int i, ElemType &e)
{
	if (i<1 || i>L.length)
		return 0;
	else
	{
		e = L.data[i - 1];
		return 1;
	}
}

int Locate(Sqlist L, ElemType x)
{
	int i = 0;
	while (i < L.length && L.data[i] != x)
		i++;
	if (i >= L.length) return 0;
	else return(i + 1);
}

int InsElem(Sqlist& L, ElemType x, int i)
{
	int j;
	if (i<1 || i>L.length + 1)
		return 0;
	for (j = L.length; j > i - 1; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = x;
	L.length++;
	return 1;
}

int DelElem(Sqlist& L, int i)
{
	int j;
	if (i<1 || i > L.length)
		return 0;
	for (j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return 1;
}

void DispList(Sqlist L)
{
	int i;
	for (i = 0; i < L.length; i++)
		printf(" %d ", L.data[i]);
	printf("\n");
}

void CreateList(Sqlist& L, ElemType a[], int n)
{
	int i, k = 0;
	for (i = 0; i < n; i++)
	{
		L.data[k] = a[i];
		k++;
	}
	L.length = k;
}
