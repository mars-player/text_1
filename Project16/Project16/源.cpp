#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct tnode
{
	ElemType data;
	struct tnode* lchild, * rchild;
}BTNode;

void CreateBTree(BTNode*& bt, char* str) //建立二叉链运算
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	bt = NULL;  //建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0')  //str未扫描完时循环
	{
		switch (ch)
		{
		case '(': top++; St[top] = p; k = 1; break;  //处理左孩子结点
		case ')': top--; break;
		case ',': k = 2; break;  //处理右孩子结点
		default: p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (bt == NULL)  //p为二叉树的根节点
				bt = p;
			else             //已建立二叉树根节点
			{
				switch (k)
				{
				case 1: St[top]->lchild = p;
					break;
				case 2: St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void DestroyBTree(BTNode*& bt)  //销毁二叉树bt的运算
{
	if (bt != NULL)
	{
		DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}

int BTHeight(BTNode* bt)  //求二叉树bt的高度
{
	int lchilddep, rchilddep;
	if (bt == NULL) return 0;  //空树的高度为0
	else
	{
		lchilddep = BTHeight(bt->lchild);  //求左子树的高度为lchilddep
		rchilddep = BTHeight(bt->rchild);  //求右子树的高度为rchilddep
		return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
	}
}

int NodeCount(BTNode* bt)  //求二叉树bt的结点个数
{
	int num1, num2;
	if (bt == NULL)  //为空树时返回0
		return 0;
	else
	{
		num1 = NodeCount(bt->lchild);  //求左子树结点个数
		num2 = NodeCount(bt->rchild);  //求右子树结点个数
		return (num1 + num2 + 1);      //返回和加上1
	} 
}

int LeafCount(BTNode* bt)  //求二叉树bt叶子结点个数运算
{
	int num1, num2;
	if (bt == NULL)        //空树返回0
		return 0;
	else if (bt->lchild == NULL && bt->rchild == NULL)
		return 1;          //为叶子结点时返回1
	else
	{
		num1 = LeafCount(bt->lchild);  //求左子树叶子结点个数
		num2 = LeafCount(bt->rchild);  //求右子树叶子结点个数
		return (num1 + num2);          //返回和
	}
}

void DispBTree(BTNode* bt)  
{
	if (bt != NULL)                   //bt为非空时
	{   
		printf("%c", bt->data);       //输出根结点值
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");              //有子树时输出'('
			DispBTree(bt->lchild);    //递归处理左子树
			if (bt->rchild != NULL)   //有右子树输出','
				printf(",");         
			DispBTree(bt->rchild);    //递归处理右子树
			printf(")");              //右子树输出完毕，再输出一个')'
		}
	}
}

int main(void)
{
	BTNode* bt;
	CreateBTree(bt, "A(B(D, E(G, H)), C(, F(I))");
	printf("二叉树bt:"); DispBTree(bt); printf("\n");
	printf("bt的高度:%d\n", BTHeight(bt));
	printf("bt的结点数:%d\n", NodeCount(bt));
	printf("bt的叶子结点数:%d\n", LeafCount(bt));
	DestroyBTree(bt);
}