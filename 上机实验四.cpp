#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>
#define true 1
#define false 0
#define ok 1
#define error 1
#define infeasible -1
#define overflow -2
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
//TElemType �Ƕ���������Ԫ�����ͣ��˳�����Ϊchar��
typedef char TElemType;
//----�������Ķ�������洢��ʾ----
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

char* pstr;
Status CreateBiTree(BiTree& T);
Status CreateBiTreeInPreOrderResult(BiTree& T);
Status CreateBiTreeInBracket(BiTree& T);
Status PrintElement(BiTree t);
Status PreOrderTraverse(BiTree T, Status(* Visit)(BiTree t));
Status InOrderTraverse(BiTree T, Status(* Visit)(BiTree t));
Status PostOrderTraverse(BiTree T, Status(*Visit)(BiTree t)); 
Status DisplayBiTreeInBracket(BiTree T);

Status CreateBiTree(BiTree& T)
{
	int i, len, choice = 0;
	char str[200];
	printf("��ѡ�����������ķ���:\n");
	printf("1.����������Ľ�����������\n");
	printf("2.��Ƕ�����ű�ʾ�����������\n");
	do{
		gets(str);
		choice = atoi(str);
	}while (choice < 1 || choice > 2);
	if (choice == 1)
	{
		printf("��������������������Ľ��������ݴ˽�����������\n");
		printf("����Ҷ�ӽڵ��Կո��ʾ��\n");
		printf("���磺abc_de_g_f_(�س�)���������¶�����:\n");
		printf("		a		\n");
		printf("		/		\n");
		printf("		b		\n");
		printf("		/\\		\n");
		printf("		c	d	\n");
		printf("		/\\		\n");
		printf("		e	f	\n");
		printf("		\\		\n");
		printf("		g		\n");
		pstr = gets(str);
		len = strlen(str);
		for (i = len; i < 180; ++i)
		    str[i] = ' ';
		str[i] = 0;
		CreateBiTreeInPreOrderResult(T); //��ʼ�������� 
	} 
	else
	{
		printf("������Ƕ�����ű�ʾ���Ķ������ͣ�����ݴ˽�����������\n");
		printf("���磺(a(b(c,d(e(,g),f))))(�س�)���������¶�������\n");
		printf("		a		\n");
		printf("		/		\n");
		printf("		b		\n");
		printf("		/\\		\n");
		printf("		c	d	\n");
		printf("		/\\		\n");
		printf("		e	f	\n");
		printf("		\\		\n");
		printf("		g		\n");
		pstr = gets(str);
		CreateBiTreeInBracket(T);
	}
	return ok;
}

Status CreateBiTreeInPreOrderResult(BiTree& T)
{
	if (! (*pstr) || *pstr == ' ')
	{
		T = NULL;
		pstr++;
	}
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)exit(overflow);
		T->data = *(pstr++);
		CreateBiTreeInPreOrderResult(T->lchild);
		CreateBiTreeInPreOrderResult(T->rchild);
	}
	return ok;
}

Status CreateBiTreeInBracket(BiTree& T)
{
	//����Ƕ�����ű�ʾ�����ַ���*str�������Ӵ洢�Ķ�����
	//���磺*pstr="(a(b(c),d(e(,f),g)"
	BiTree stack[100], p;
	int top = 0, k;
	T = NULL;
	while (* pstr){
		switch(* pstr){
			case '(': stack[top++] = p; k = 1; break;
			case ')': stack[top--]; break;
			case ',': k = 2; break;
			case ' ': break;
			default: 
			p = (BiTree)malloc(sizeof(BiTNode));
			p->data = * pstr;
			p->lchild = p->rchild = NULL;
			if (!T)T = p; //���ڵ�
			else{
				switch(k){
					case 1: stack[top - 1]->lchild = p; break;
					case 2: stack[top - 1]->rchild = p; break;
				}
			} 
			
		}
		pstr++;
	} 
	return ok;
}

Status DestroyBiTree(BiTree& T)
{
	if (T){
		if (T->lchild) DestroyBiTree(T->lchild);
		if (T->rchild) DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
		return ok;
	}
	else
	    return ok;
}

Status PrintElement(BiTree t)
{
	printf("%c", t->data);
	return ok;
}

Status PreOrderTraverse(BiTree T, Status(* Visit)(BiTree t)) //���� 
{
	if (T){
		if ((* Visit)(T))
		if (PreOrderTraverse(T->lchild, Visit))
		    if (PreOrderTraverse(T->rchild, Visit))
		        return ok;
		    return error;
	}
	else return ok;
}

Status InOrderTraverse(BiTree T, Status(* Visit)(BiTree t))
{
	//����
	if (T){
		if (InOrderTraverse(T->lchild, Visit))
		    if ((* Visit)(T))
		        if (InOrderTraverse(T->rchild, Visit))
		            return ok;
		        return error;
	}
	else return ok;   
}

Status PostOrderTraverse(BiTree T, Status(* Visit)(BiTree e))
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, PrintElement))
		    if (PostOrderTraverse(T->rchild, PrintElement))
		        if ((* Visit)(T))
		           return ok;
		        return error;
	}
	else return ok;
}

Status DisplayBiTreeInConcave(BiTree T)
{
	BiTree stack[100], p;
	int level[100][2], top, n, i, width = 4;
	char childtype[3] = {'L', 'R', 'D'};
	const int MaxWidth = 30;
	if (T)
	{
		top = 0;
		stack[top] = T; //�������ջ
		level[top][0] = width;
		level[top][1] = 2;
		while (top >= 0)
		{
			p = stack[top];
			n = level[top][0];
			for (i = 1; i <= n; i++)printf(" ");
			printf("%c(%c)", p->data, childtype[level[top][1]]);
			for (i = n + 1; i <= MaxWidth; i += 2) printf("-");
			printf("\n");
			top--;
			if (p->rchild){
				top++;
				stack[top] = p->rchild;
				level[top][0] = n + width;
				level[top][1] = 1; //1��ʾ�������� 
			}
			if (p->lchild){
				top++;
				stack[top] = p->lchild;
				level[top][0] = n + width;
				level[top][1] = 0; //0��ʾ�������� 
			} 
		}  
	} 
	else 
	    printf("�ö�������һ�ſն�������\n");
	return ok; 
}

Status DisplayBiTreeInBracket(BiTree T)
{
	//��Ƕ�����ű�ʾ�����һ�Ŷ�����
	if (T)
	{
		printf("%c", T->data);
		if (T->lchild || T->rchild)
		{
			printf("(");
			if (T->lchild)DisplayBiTreeInBracket(T->lchild);
			if (T->rchild)printf(",");
			if (T->rchild)DisplayBiTreeInBracket(T->rchild);
			printf(")");
		}
	}
	else printf("�ö�������һ�ſն�������");
	return ok;
}

int main()
{
	BiTree T;
	char ch, j;
	char str[200];
	int choice, flag = 1, len, i;
	Status temp;
	printf("������ʵ�ֶ������Ĳ���:\n");
	printf("���Խ��н������������ݹ��������򡢺�������Ȳ�����\n");
	CreateBiTree(T);
	while (flag)
	{
		printf("��ѡ��\n");
		printf("1.�ݹ��������\n");
		printf("2.�ݹ��������\n");
		printf("3.�ݹ�������\n");
		printf("4.�����ʾ�����������\n");
		printf("5.Ƕ�����ű�ʾ�����������\n");
		printf("6.���¹���������\n");
		printf("7.�˳�����\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				if (T)
				{
					printf("���������������");
					PreOrderTraverse(T, PrintElement);
					printf("\n");
				}
				else printf("������Ϊ�գ�\n");
				break;
			case 2:
				if (T)
				{
					printf("�������������:");
					InOrderTraverse(T, PrintElement);
					printf("\n");
				}
				else printf("������Ϊ�գ�\n");
				break;
			case 3:
				if (T)
				{
					printf("�������������:");
					PostOrderTraverse(T, PrintElement);
					printf("\n");
				}
				else printf("�ö�����Ϊ�գ�\n");
				break;
			case 4:
				DisplayBiTreeInConcave(T);
				break;
			case 5:
				printf("(");
				DisplayBiTreeInBracket(T);
				printf(")\n");
				break;
			case 6:
				DestroyBiTree(T);
				CreateBiTree(T);
				break;
			default:
				flag = 0;
				printf("�������н�������������˳���\n");
				getch();
		}
	}
	DestroyBiTree(T);
}

