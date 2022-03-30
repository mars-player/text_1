#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
	QType* front; //指向队头病人结点
	QType* rear;  //指向队尾结点
}LQueue;          //病人链队类型
typedef struct Lnode
{
	char data[10]; //存放患者姓名
	struct Lnode* next; //指针域
}QType;            //链队中结点类型

//----初始化队列运算算法----
void InitQueue(LQueue*& lq)
{
	lq = (LQueue*)malloc(sizeof(LQueue*));
	lq->rear = lq->front = NULL; //初始时队头和队尾指针均为空
}

//----销毁链表----
void DestroyQueue(LQueue*& lq)
{
	QType* pre = lq->front, * p;
	if (pre != NULL)
	{
		if (pre = lq->rear)
			free(pre);
		else
		{
			p = pre->next;
			while (p != NULL)
			{
				free(pre);
				pre = p; p = p->next;
			}
		}
		free(pre);
	}
	free(lq);
}

//----进队运算算法----
void EnQueue(LQueue*& lq, char x[])
{
	QType* s;
	s = (QType*)malloc(sizeof(QType*)); //创建新结点，插入到链队的末尾
	strcpy(s->data, x); s->next = NULL; 
	if (lq->front == NULL)  //原队为空队的情况
		lq->rear = lq->front = s; //front和rear均指向s结点
	else                    //原队不为空队的情况
	{
		lq->rear->next = s; //将结点s链到队尾
		lq->rear = s;       //rear指向结点s
	}
}

//----出队运算算法----
int DeQueue(LQueue*& lq, char x[])
{
	QType* p;
	if (lq->front == NULL) //原队为空的情况
		return 0;      
	p = lq->front;         //p指向队头结点
	strcpy(x, p->data);    //取队头元素值
	if (lq->rear == lq->front) //若原队列中只有一个结点，删除后队列变空
		lq->rear = lq->front = NULL;
	else                   //原队有两个或以上结点的情况
		lq->front = lq->front->next;
	free(p);
	return 1;
}

//----判断队空运算算法----
int QueueEmpty(LQueue* lq)
{
	if (lq->front == NULL)return 1;
	else return 0;
}

//----输出队中所有元素的算法----
int DispQueue(LQueue* lq)
{
	QType* p;
	if (QueueEmpty(lq))return 0; //队空返回0
	else
	{
		p = lq->front;
		while (p != NULL)
		{
			printf("%s ", p->data);
			p = p->next;
		}
		printf("\n");
		return 1;                //队不空返回1
	}
}

int main(void)
{
	int sel, flag = 1;
	char name[10];
	LQueue* lq;
	InitQueue(lq);
	while (flag == 1)
	{
		printf("1:排队 2:看医生 3:查看排队 0:下班 请选择:");
		scanf_s("%d", &sel);
		switch (sel)
		{
		case 0:
			if (!QueueEmpty(lq))
				printf("	>>请排队的患者明天就医\n");
			DestroyQueue(lq);
			flag = 0;
			break;
		case 1:
			printf("	>>输入患者姓名:");
			scanf_s("%s", name);
			EnQueue(lq, name);
			break;
		case 2:
			if (!DeQueue(lq, name))
				printf("	>>没有排队的患者\n");
			else
				printf("	>>患者%s看医生\n", name);
			break;
		case 3:
			printf("	>>排队患者:");
			if (!DispQueue(lq))
				printf("	>>没有排队的患者\n");
			break;
		}
	}
}