#include "标头.h"
#include <stdio.h>
#define MAX 10
int main(void)
{
	PolyNode* Poly1, * Poly2, * Poly3;
	double a[MAX];
	int b[MAX], n;
	/*--------创建第一个多项式单链表--------*/
	a[0] = 3.2; b[0] = 5;
	a[1] = 2.0; b[1] = 3;
	a[2] = -6.0; b[2] = 1;
	a[3] = 10.0; b[3] = 0;
	n = 4;
	CreateListR(Poly1, a, b, n);
	printf("第2个多项式:"); DispPoly(Poly1);
	/*--------创建第二个多项式单链表--------*/
	a[0] = 1.8; b[0] = 5;
	a[1] = -2.5; b[1] = 4;
	a[2] = -2; b[2] = 3;
	a[3] = 1.0; b[3] = 2;
	a[4] = 6.0; b[4] = 1;
	a[5] = -5.0; b[6] = 0;
	n = 6;
	CreateListR(Poly2, a, b, n);
	printf("第2个多项式:"); DispPoly(Poly2);
	Add(Poly1, Poly2, Poly3);
	printf("相加后多项式:"); DispPoly(Poly3);
	DestroyList(Poly1);
	DestroyList(Poly2);
	DestroyList(Poly3);
}