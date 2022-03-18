#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	char name[10];
	int score;
	struct node* next;
}StudList;

void CreateStudent(StudList*& sl) /*采用尾插法创建学生单链表*/
{
	int n, i;
	StudList* s, * tc;
	sl = (StudList*)malloc(sizeof(StudList));
	tc = sl;
	printf("	学生人数:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		s = (StudList*)malloc(sizeof(StudList));
		printf("	第%d个学生姓名和成绩:", i + 1);
		scanf("%s", s->name);
		scanf("%d", &s->score);
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}

void DestroyList(StudList*& L) /*销毁学生单链表*/
{
	StudList* pre = L, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}

void DispList(StudList* L) /*输出学生单链表*/
{
	StudList* p = L->next;
	int i = 1;
	printf("	名次	姓名	成绩\n");
	while (p != NULL)
	{
		printf("	%d\t", i++);
		printf("%s\t", p->name);
		printf("%d\n", p->score);
		p = p->next;
	}
}

void SortList(StudList*& L) /*学生单链表按成绩递减排序*/
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
	printf("(1)建立学生单链表\n");
	CreateStudent(st);
	printf("(2)按成绩递减排序\n");
	SortList(st);
	printf("(3)排序后的结果\n"); DispList(st);
	printf("(4)销毁学生单链表\n"); DestroyList(st);
}
