#include <stdio.h>
#include <malloc.h>
#define MaxSize 100 
typedef int ElemType;
typedef struct tnode
{
	ElemType data;
	struct tnode* lchild, * rchild;
}BTNode;

void PreOrder(BTNode* bt)  //先序遍历 
{
	if (bt != NULL)
	{
		printf(" %c ", bt->data);  //访问根结点 
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void InOrder(BTNode* bt)  //中序遍历 
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		printf(" %c ", bt->data);  //访问根节点 
		InOrder(bt->rchild);
	}
}

void PostOrder(BTNode* bt)  //后序遍历 
{
	if (bt != NULL)
    {
    	PostOrder(bt->lchild);
    	PostOrder(bt->rchild);
    	printf(" %c ", bt->data);  //访问根节点 
	}
}

void LevelOrder(BTNode* bt)  //层次遍历 
{
	BTNode* p;
	BTNode* qu[MaxSize];  //定义循环队列，存放二叉链结点指针 
	int front, rear;      //定义队头和队尾指针 
	front = rear = 0;     //置队列为空队列 
	rear++; qu[rear] = bt;  //根节点指针进入队列 
	while (front != rear)   //队列不为空循环 
    {
    	front = (front + 1) % MaxSize;
    	p = qu[front];    //出队结点p 
    	printf(" %c ", p->data);  //访问该结点 
    	if (p->lchild != NULL)    //有左孩子时进队 
    	{
    		rear = (rear + 1) % MaxSize;  
    		qu[rear] = p->lchild;
		}  
		if (p->rchild != NULL)    //有右孩子时进队 
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
 } 
 
void CreateBTree(BTNode*& bt, char* str)  //建立二叉链运算 
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	bt = NULL;                            //建立的二叉树初始时为空 
	ch = str[j]; 
	while (ch != '\0')                    //str未扫描完时循环 
	{
		switch(ch)
		{
			case '(': top++; St[top] = p; k = 1; break;  //处理左孩子结点 
			case ')': top--; break;
			case ',': k = 2; break;                      //处理右孩子结点 
			default: p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (bt == NULL)               //p为二叉树的根节点 
			    bt = p;
			else                          //已建立二叉树根节点 
			{
				switch(k)
				{
					case 1: St[top]->lchild = p; break;
					case 2: St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
 } 
 
 
 void DispBTree(BTNode* bt)
 {
 	if (bt != NULL)
 	{
 		printf("%c", bt->data);
 		if (bt->lchild != NULL || bt->rchild != NULL)
 		{
 			printf("(");
 			DispBTree(bt->lchild);
 			if (bt->rchild != NULL)
 			    printf(",");
 			DispBTree(bt->rchild );
 			printf(")");
		 }
	 }
 }
 
 void DestroyBTree(BTNode*& bt)
 {
 	if (bt != NULL)
 	{
 		DestroyBTree(bt->lchild);
 		DestroyBTree(bt->rchild);
 		free(bt);
	 }
 }
 int main(void)
 {
 	BTNode* bt;
 	CreateBTree(bt, "A(B(D, E(G, H)), C(, F(I)))");
 	printf("二叉树bt:"); DispBTree(bt); printf("\n");
 	printf("先序遍历序列:"); PreOrder(bt); printf("\n");
 	printf("中序遍历序列:"); InOrder(bt); printf("\n");
 	printf("后序遍历序列:"); PostOrder(bt); printf("\n");
	printf("层次遍历序列:"); LevelOrder(bt); printf("\n");
	DestroyBTree(bt); 
 }
