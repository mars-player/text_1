#include "标头.h"
#include <stdio.h>
int main()
{
	int i;
	ElemType e;
	DLinkNode* L, * L1, * L2;
	printf("测试1\n");
	InitList(L);
	InsElem(L, 1, 1);
	InsElem(L, 3, 2);
	InsElem(L, 1, 3);
	InsElem(L, 5, 4);
	InsElem(L, 4, 5);
	InsElem(L, 2, 6);
	printf("	L:	"); DispList(L);
	printf("	长度:%d\n", GetLength(L));
	i = 3; GetElem(L, i, e);
	printf("	第%d个元素:%d\n", i, e);
	e = 1;
	printf("	元素%d是第%d个元素:\n", e, Locate(L, e));
	i = 4; printf("	删除第%d个元素\n", i);
	DelElem(L, i);
	printf("	L:	"); DispList(L);
	printf("测试2\n");
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("	由1~5采用头插法创建L1\n");
	CreateListF(L1, a, n);
	printf("	L1:	"); DispList(L1);
	printf("测试3\n");
	printf("由1~5采用尾插法创建L2\n");
	CreateListR(L2, a, n);
	printf("	L2:	"); DispList(L2);
	printf("销毁L、L1和L2\n");
	DestroyList(L);
	DestroyList(L1);
	DestroyList(L2);

}