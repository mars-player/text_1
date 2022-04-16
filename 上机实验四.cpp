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
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
//TElemType 是二叉树数据元素类型，此程序定义为char型
typedef char TElemType;
//----二叉树的二叉链表存储表示----
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
	printf("请选择建立二叉树的方法:\n");
	printf("1.按先序遍历的结果输入二叉树\n");
	printf("2.按嵌套括号表示法输入二叉树\n");
	do{
		gets(str);
		choice = atoi(str);
	}while (choice < 1 || choice > 2);
	if (choice == 1)
	{
		printf("请输入先序遍历二叉树的结果，程序据此建立二叉树。\n");
		printf("对于叶子节点以空格表示。\n");
		printf("例如：abc_de_g_f_(回车)，建立如下二叉树:\n");
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
		CreateBiTreeInPreOrderResult(T); //初始化二叉树 
	} 
	else
	{
		printf("请输入嵌套括号表示法的而产生和，程序据此建立二叉树。\n");
		printf("例如：(a(b(c,d(e(,g),f))))(回车)，建立如下二叉树：\n");
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
	//根据嵌套括号表示法的字符串*str生成链接存储的二叉树
	//例如：*pstr="(a(b(c),d(e(,f),g)"
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
			if (!T)T = p; //根节点
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

Status PreOrderTraverse(BiTree T, Status(* Visit)(BiTree t)) //先序 
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
	//中序
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
		stack[top] = T; //根结点入栈
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
				level[top][1] = 1; //1表示是右子树 
			}
			if (p->lchild){
				top++;
				stack[top] = p->lchild;
				level[top][0] = n + width;
				level[top][1] = 0; //0表示是左子树 
			} 
		}  
	} 
	else 
	    printf("该二叉树是一颗空二叉树！\n");
	return ok; 
}

Status DisplayBiTreeInBracket(BiTree T)
{
	//以嵌套括号表示法输出一颗二叉树
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
	else printf("该二叉树是一颗空二叉树！");
	return ok;
}

int main()
{
	BiTree T;
	char ch, j;
	char str[200];
	int choice, flag = 1, len, i;
	Status temp;
	printf("本程序实现二叉树的操作:\n");
	printf("可以进行建立二叉树，递归先序、中序、后序遍历等操作。\n");
	CreateBiTree(T);
	while (flag)
	{
		printf("请选择：\n");
		printf("1.递归先序遍历\n");
		printf("2.递归中序遍历\n");
		printf("3.递归后序遍历\n");
		printf("4.凹入表示法输出二叉树\n");
		printf("5.嵌套括号表示法输出二叉树\n");
		printf("6.重新构建二叉树\n");
		printf("7.退出程序\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				if (T)
				{
					printf("先序遍历二叉树：");
					PreOrderTraverse(T, PrintElement);
					printf("\n");
				}
				else printf("二叉树为空！\n");
				break;
			case 2:
				if (T)
				{
					printf("中序遍历二叉树:");
					InOrderTraverse(T, PrintElement);
					printf("\n");
				}
				else printf("二叉树为空！\n");
				break;
			case 3:
				if (T)
				{
					printf("后序遍历二叉树:");
					PostOrderTraverse(T, PrintElement);
					printf("\n");
				}
				else printf("该二叉树为空！\n");
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
				printf("程序运行结束，按任意键退出！\n");
				getch();
		}
	}
	DestroyBiTree(T);
}

