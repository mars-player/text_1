#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define ok 1
#define error 0
#define infeasible -1
#define overflow -2

typedef int Status; //Status是函数的类型，其值是函数结果状态代码
typedef int QElemType;
//----单链队列--队列的链式存储结构---- 
typedef struct QNode //定义结点结构 
{
	QElemType data; //数据域 
	struct QNode* next; //指针域 
}QNode, *QueuePtr;
typedef struct linkqueue //定义队列结构 
{
	QueuePtr front; //队头指针 
	QueuePtr rear; //队尾指针 
}LinkQueue;

Status InitLinkQueue(LinkQueue&);
Status DestroyLinkQueue(LinkQueue&);
int LinkQueueLength(LinkQueue& Q);
Status EnLinkQueue(LinkQueue&, QElemType);
Status DeLinkQueue(LinkQueue&, QElemType&);
Status DisplayLinkQueue(LinkQueue);

int main()
{
	LinkQueue LQ;
	QElemType e;
	int flag = 1, ch, len;
	Status temp;
	printf("本程序实现链式结构队列的操作。\n");
	printf("可以进行入队列、出队列等操作。\n");
	InitLinkQueue(LQ);
	while(flag)
	{
		printf("请选择:\n");
		printf("1.显示队列所有元素:\n");
		printf("2.入队列:\n");
		printf("3.出队列:\n");
		printf("4.求队列的长度:\n");
		printf("5.退出程序:\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				DisplayLinkQueue(LQ);
				break;
			case 2:
				printf("请输入要入队的元素(一个整数):");
				scanf("%d", &e);
				EnLinkQueue(LQ, e);
				DisplayLinkQueue(LQ);
				break;
			case 3:
			    temp = DeLinkQueue(LQ, e);
				if(temp == ok)
				{
					printf("出队一个元素:%d\n", e);
					DisplayLinkQueue(LQ);
				} 
				else printf("队列为空！\n");
				break;
			case 4:
				len = LinkQueueLength(LQ);
				printf("队列的长度为:%d\n", len);
				break;
			default:
			    flag = 0;
			    printf("程序运行结束，按任意键退出！\n");
			    getch();
		} 
	} 
} 

Status InitLinkQueue(LinkQueue& Q) //队列初始化
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL; //生成一个头结点，并把首尾指针指向头结点
	return ok;
}

Status DestroyLinkQueue(LinkQueue& Q) //销毁一个队列
{
	QueuePtr p;
	QElemType e;
	while(Q.front != Q.rear)
	   DeLinkQueue(Q,e);
	free(Q.front);
	Q.front = Q.rear = NULL;
	return ok;
}

int LinkQueueLength(LinkQueue& Q) //队列的长度
{
	int i = 0;
	QueuePtr p = Q.front;
	while(p != Q.rear)
	{
		++i;
		p = p->next;
	  }  
	return i;
}

Status EnLinkQueue(LinkQueue& Q, QElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode)); //生成一个新结点
    p->data = e; 
    p->next = NULL;
    Q.rear->next = p; //插入至队列尾
    Q.rear = p; //修改队尾指针
    return ok;
}

Status DeLinkQueue(LinkQueue& Q, QElemType& e) //出队列
{
	QueuePtr p;
	if (Q.front == Q.rear) return error; //判断队列是否已空，已空返回error
	p = Q.front->next; //p指向队列中第一个元素
	e = p->data; //取得该元素值
	Q.front->next = p->next;  //修改队尾指针
	if (Q.rear == p) Q.rear = Q.front;  //若队列已空，把队尾指针指向头结点
	return ok;  //成功出队列，返回ok
}

Status DisplayLinkQueue(LinkQueue Q)
{
	QueuePtr p;
	int i = 0;
	p = Q.front->next;
	if (p == NULL) printf("队列为空！\n");
	else
	{
		while(p)
		{
			printf("[%d:%d]", ++i, p->data);
			p = p->next;
		}
		printf("\n");
	}
	return ok;
}


