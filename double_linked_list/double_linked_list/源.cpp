#include "��ͷ.h"
int main(void)
{
	int i;
	ElemType e;
	DLinkNode* L, * L1, * L2;
	printf("����1\n");
	InitList(L);
	InsElem(L, 1, 1);
	InsElem(L, 3, 2);
	InsElem(L, 1, 3);
	InsElem(L, 5, 4);
	InsElem(L, 4, 5);
	InsElem(L, 2, 6);
	printf("	L:	"); DispList(L);
	printf("	����:%d\n", GetLength(L));
	i = 3; GetElem(L, i, e);
	printf("	Ԫ��%d�ǵ�%d��Ԫ��\n", e, Locate(L, e));
	i = 4; printf("	ɾ����%d��Ԫ��\n", i);
	DelElem(L, i);
	printf("	L:	"); DispList(L);
	printf("����2:\n");
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("	��1-5����β�巨����L2\n");
	CreateListR(L2, a, n);
	printf("	L2:	"); DispList(L2);
	printf("����L��L1����L2\n");
	DestroyList(L);
	DestroyList(L1);
	DestroyList(L2);
}