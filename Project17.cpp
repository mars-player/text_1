#include <stdio.h>
#include <malloc.h>
#define MaxSize 100 
typedef int ElemType;
typedef struct tnode
{
	ElemType data;
	struct tnode* lchild, * rchild;
}BTNode;

void PreOrder(BTNode* bt)  //������� 
{
	if (bt != NULL)
	{
		printf(" %c ", bt->data);  //���ʸ���� 
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void InOrder(BTNode* bt)  //������� 
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		printf(" %c ", bt->data);  //���ʸ��ڵ� 
		InOrder(bt->rchild);
	}
}

void PostOrder(BTNode* bt)  //������� 
{
	if (bt != NULL)
    {
    	PostOrder(bt->lchild);
    	PostOrder(bt->rchild);
    	printf(" %c ", bt->data);  //���ʸ��ڵ� 
	}
}

void LevelOrder(BTNode* bt)  //��α��� 
{
	BTNode* p;
	BTNode* qu[MaxSize];  //����ѭ�����У���Ŷ��������ָ�� 
	int front, rear;      //�����ͷ�Ͷ�βָ�� 
	front = rear = 0;     //�ö���Ϊ�ն��� 
	rear++; qu[rear] = bt;  //���ڵ�ָ�������� 
	while (front != rear)   //���в�Ϊ��ѭ�� 
    {
    	front = (front + 1) % MaxSize;
    	p = qu[front];    //���ӽ��p 
    	printf(" %c ", p->data);  //���ʸý�� 
    	if (p->lchild != NULL)    //������ʱ���� 
    	{
    		rear = (rear + 1) % MaxSize;  
    		qu[rear] = p->lchild;
		}  
		if (p->rchild != NULL)    //���Һ���ʱ���� 
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
 } 
 
void CreateBTree(BTNode*& bt, char* str)  //�������������� 
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	bt = NULL;                            //�����Ķ�������ʼʱΪ�� 
	ch = str[j]; 
	while (ch != '\0')                    //strδɨ����ʱѭ�� 
	{
		switch(ch)
		{
			case '(': top++; St[top] = p; k = 1; break;  //�������ӽ�� 
			case ')': top--; break;
			case ',': k = 2; break;                      //�����Һ��ӽ�� 
			default: p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (bt == NULL)               //pΪ�������ĸ��ڵ� 
			    bt = p;
			else                          //�ѽ������������ڵ� 
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
 	printf("������bt:"); DispBTree(bt); printf("\n");
 	printf("�����������:"); PreOrder(bt); printf("\n");
 	printf("�����������:"); InOrder(bt); printf("\n");
 	printf("�����������:"); PostOrder(bt); printf("\n");
	printf("��α�������:"); LevelOrder(bt); printf("\n");
	DestroyBTree(bt); 
 }
