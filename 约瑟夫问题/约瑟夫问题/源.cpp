#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int no;
	struct node* next;
}Child;
void CreateList(Child*& L, int n)
{
	int i;
	Child* p, * tc;
	L = (Child*)malloc(sizeof(Child));
	L->no = 1;
	tc = L;
	for (i = 2; i <= n; i++)
	{
		p = (Child*)malloc(sizeof(Child));
		p->no = i;
		tc->next = p; tc = p;
	}
	tc->next = L;
}

void Joseph(int n, int m)
{
	int i, j;
	Child* L, * p, * q;
	CreateList(L, n);
	for (i =1;i<= n; i++)
	{
		p = L; j = 1;
		while (j < m - 1)
		{
			j++;
			p = p->next;
		}
		q = p->next;
		printf("%d ", q->no);
		p->next = q->next;
		free(q);
		L = p->next;
	}
}

void main()
{
	int n = 6, m = 5;
	printf("n = %d, m = %dµÄÔ¼Éª·òÐòÁÐ:", n, m);
	Joseph(n, m); printf("\n");
}
