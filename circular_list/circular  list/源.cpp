#include "��ͷ.h"
#include <stdio.h>
int main()
{
	int i; ElemType e;
	SlinkNode* L;
	InitList(L);
	InsElem(L, 1, 1);
	InsElem(L, 3, 2);
	InsElem(L, 1, 3);
	InsElem(L, 5, 4);
	InsElem(L, 4, 5);
	InsElem(L, 2, 6);
	printf("���Ա�:"); DispList(L);
	printf("����:%d\n", GetLength(L));
	i = 3; GetElem(L, i, e);
	printf("��%d��Ԫ��:%d\n", i, e);
	e = 1;
	printf("Ԫ��%d�ǵ�%d��Ԫ��\n", e, Locate(L, e));
	i = 4; printf("ɾ����%d��Ԫ��\n", i);
	DelElem(L, i);
	printf("���Ա�:"); DispList(L);
	DestroyList(L);
}