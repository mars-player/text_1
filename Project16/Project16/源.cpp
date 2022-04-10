#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct tnode
{
	ElemType data;
	struct tnode* lchild, * rchild;
}BTNode;

void CreateBTree(BTNode*& bt, char* str) //��������������
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	bt = NULL;  //�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0')  //strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(': top++; St[top] = p; k = 1; break;  //�������ӽ��
		case ')': top--; break;
		case ',': k = 2; break;  //�����Һ��ӽ��
		default: p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (bt == NULL)  //pΪ�������ĸ��ڵ�
				bt = p;
			else             //�ѽ������������ڵ�
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

void DestroyBTree(BTNode*& bt)  //���ٶ�����bt������
{
	if (bt != NULL)
	{
		DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}

int BTHeight(BTNode* bt)  //�������bt�ĸ߶�
{
	int lchilddep, rchilddep;
	if (bt == NULL) return 0;  //�����ĸ߶�Ϊ0
	else
	{
		lchilddep = BTHeight(bt->lchild);  //���������ĸ߶�Ϊlchilddep
		rchilddep = BTHeight(bt->rchild);  //���������ĸ߶�Ϊrchilddep
		return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
	}
}

int NodeCount(BTNode* bt)  //�������bt�Ľ�����
{
	int num1, num2;
	if (bt == NULL)  //Ϊ����ʱ����0
		return 0;
	else
	{
		num1 = NodeCount(bt->lchild);  //��������������
		num2 = NodeCount(bt->rchild);  //��������������
		return (num1 + num2 + 1);      //���غͼ���1
	} 
}

int LeafCount(BTNode* bt)  //�������btҶ�ӽ���������
{
	int num1, num2;
	if (bt == NULL)        //��������0
		return 0;
	else if (bt->lchild == NULL && bt->rchild == NULL)
		return 1;          //ΪҶ�ӽ��ʱ����1
	else
	{
		num1 = LeafCount(bt->lchild);  //��������Ҷ�ӽ�����
		num2 = LeafCount(bt->rchild);  //��������Ҷ�ӽ�����
		return (num1 + num2);          //���غ�
	}
}

void DispBTree(BTNode* bt)  
{
	if (bt != NULL)                   //btΪ�ǿ�ʱ
	{   
		printf("%c", bt->data);       //��������ֵ
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");              //������ʱ���'('
			DispBTree(bt->lchild);    //�ݹ鴦��������
			if (bt->rchild != NULL)   //�����������','
				printf(",");         
			DispBTree(bt->rchild);    //�ݹ鴦��������
			printf(")");              //�����������ϣ������һ��')'
		}
	}
}

int main(void)
{
	BTNode* bt;
	CreateBTree(bt, "A(B(D, E(G, H)), C(, F(I))");
	printf("������bt:"); DispBTree(bt); printf("\n");
	printf("bt�ĸ߶�:%d\n", BTHeight(bt));
	printf("bt�Ľ����:%d\n", NodeCount(bt));
	printf("bt��Ҷ�ӽ����:%d\n", LeafCount(bt));
	DestroyBTree(bt);
}