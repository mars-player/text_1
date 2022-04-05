#include "��ͷ.h"
#include <stdio.h>
void CreatMat(TSMatrix& t, ElemType A[M][N]) //��һ����άϡ����󴴽�����Ԫ���ʾ
{
	int i, j;
	t.rows = M; t.cols = N; t.nums = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			if (A[i][j] != 0)  //ֻ�洢����Ԫ��
			{
				t.data[t.nums].r = i; t.data[t.nums].c = j;
				t.data[t.nums].d = A[i][j]; t.nums++;
			}
	}
}

int Value(TSMatrix& t, ElemType x, int i, int j)  //��Ԫ��Ԫ�ظ�ֵ����ϡ�����Aִ��A[i][j] = x����
{
	int k = 0, k1;
	if (i >= t.rows || j >= t.cols)
		return 0;
	while (k < t.nums && i > t.data[k].r) k++; //������
	while (k < t.nums && i == t.data[k].r && j > t.data[k].c) k++; //������
	if (k < t.nums && t.data[k].r == i && t.data[k].c == j) //����������Ԫ��
		t.data[k].d = x;
	else //������������Ԫ��ʱ����һ��Ԫ��
	{
		for (k1 = t.nums - 1; k1 >= k; k1--)
		{
			t.data[k1 + 1].r = t.data[k1].r;
			t.data[k1 + 1].c = t.data[k1].c;
			t.data[k1 + 1].d = t.data[k1].d;
		}
		t.data[k].r = i; t.data[k].c = j; t.data[k].d = x;
		t.nums++;
	}
	return 1; //�ɹ�ʱ����1
}

int Assign(TSMatrix t, ElemType& x, int i, int j) //��ָ��λ��Ԫ��ֵ��������
{
	int k = 0;
	if (i >= t.rows || j >= t.cols)
		return 0;  //��������ʱ����0
	while (k < t.nums && i > t.data[k].r)k++; //������
	while (k < t.nums && i == t.data[k].r && j > t.data[k].c)k++; //������
	if (k < t.nums && i == t.data[k].r && j == t.data[k].c) 
		x = t.data[k].d;
	else
		x = 0;  //����Ԫ����û���ҵ���ʾ����Ԫ��
	return 1;  //�ɹ�ʱ����1
}

void DispMat(TSMatrix t) //�����Ԫ�������㷨
{
	int i;
	if (t.nums <= 0)
		return;  //û�з���Ԫ��ʱ����
	printf("\t%d\t%d\t%d\n", t.rows, t.cols, t.nums);
	printf("\t--------------------------------------\n");
	for (i = 0; i < t.nums; i++)
		printf("\t%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].d);
}

