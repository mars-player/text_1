#include <stdio.h>
#include "names_sequence_list.h"
int main()
{
	int i;
	ElemType e;
	Sqlist L, L1;
	InitList(L);
	InsElem(L, 5, 1);
	InsElem(L, 8, 2);
	InsElem(L, 1, 3);
	InsElem(L, 3, 4);
	InsElem(L, 6, 5);
	InsElem(L, 2, 6);
	printf("测试 1\n");
	printf("	L:	"); DispList(L);
	printf("	长度:%d\n", GetLength(L));
	i = 3; GetElem(L, i, e);
	printf("	第%d个元素:%d\n", i, e);
	e = 1;
	printf("	元素%d是第%d个元素\n", e, Locate(L, e));
	i = 4; printf("	删除第%d个元素\n", i);
	DelElem(L, i);
	printf("	L:	"); DispList(L);
	printf("测试 2\n");
	int a[] = { 2,5,4,5,6,5,3,1 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("	整体创建 L1\n");
	CreateList(L1, a, n);
	printf("	L1:	"); DispList(L1);
	int x = 5;
	printf("	第一个值为%d元素的位置是%d\n", x, Locate(L1, x));
	printf("销毁 L 和 L1\n");
	DestroyList(L);
	DestroyList(L1);
	getchar();
}

