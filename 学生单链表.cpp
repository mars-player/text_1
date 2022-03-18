#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	char name[10];
	int score;
	struct node* next;
}StudList;

void CreateStudent(StudList*& sl)
{
	int n, i;
	StudList* s, * tc;
	sl = (StudList*)malloc(sizeof(StudList));
	tc = sl;
	printf("	ѧ������:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		s = (StudList*)malloc(sizeof(StudList));
		printf("	��%d��ѧ�������ͳɼ�:", i + 1);
		scanf("%s", s->name);
		scanf("%d", &s->score);
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}

void DestroyList(StudList*& L)
{
	StudList* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

void DispList(StudList* L)
{
	StudList* p = L->next;
	int i = 1;
	printf("	����	����	�ɼ�\n");
	while (p != NULL)
	{
		printf("	%d\t", i++);
		printf("%s\t", p->name);
		printf("%d\n", p->score);
		p = p->next;
	}
}

void SortList(StudList*& L)
{
	StudList* p, * pre, * q;
	p = L->next ->next;
	L->next->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->score > p->score)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

int main()
{
	StudList* st;
	printf("(1)����ѧ��������\n");
	CreateStudent(st);
	printf("(2)���ɼ��ݼ�����\n");
	SortList(st);
	printf("(3)�����Ľ��\n"); DispList(st);
	printf("(4)����ѧ��������\n"); DestroyList(st);
}