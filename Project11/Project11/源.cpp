#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
	QType* front; //ָ���ͷ���˽��
	QType* rear;  //ָ���β���
}LQueue;          //������������
typedef struct Lnode
{
	char data[10]; //��Ż�������
	struct Lnode* next; //ָ����
}QType;            //�����н������

//----��ʼ�����������㷨----
void InitQueue(LQueue*& lq)
{
	lq = (LQueue*)malloc(sizeof(LQueue*));
	lq->rear = lq->front = NULL; //��ʼʱ��ͷ�Ͷ�βָ���Ϊ��
}

//----��������----
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

//----���������㷨----
void EnQueue(LQueue*& lq, char x[])
{
	QType* s;
	s = (QType*)malloc(sizeof(QType*)); //�����½�㣬���뵽���ӵ�ĩβ
	strcpy(s->data, x); s->next = NULL; 
	if (lq->front == NULL)  //ԭ��Ϊ�նӵ����
		lq->rear = lq->front = s; //front��rear��ָ��s���
	else                    //ԭ�Ӳ�Ϊ�նӵ����
	{
		lq->rear->next = s; //�����s������β
		lq->rear = s;       //rearָ����s
	}
}

//----���������㷨----
int DeQueue(LQueue*& lq, char x[])
{
	QType* p;
	if (lq->front == NULL) //ԭ��Ϊ�յ����
		return 0;      
	p = lq->front;         //pָ���ͷ���
	strcpy(x, p->data);    //ȡ��ͷԪ��ֵ
	if (lq->rear == lq->front) //��ԭ������ֻ��һ����㣬ɾ������б��
		lq->rear = lq->front = NULL;
	else                   //ԭ�������������Ͻ������
		lq->front = lq->front->next;
	free(p);
	return 1;
}

//----�ж϶ӿ������㷨----
int QueueEmpty(LQueue* lq)
{
	if (lq->front == NULL)return 1;
	else return 0;
}

//----�����������Ԫ�ص��㷨----
int DispQueue(LQueue* lq)
{
	QType* p;
	if (QueueEmpty(lq))return 0; //�ӿշ���0
	else
	{
		p = lq->front;
		while (p != NULL)
		{
			printf("%s ", p->data);
			p = p->next;
		}
		printf("\n");
		return 1;                //�Ӳ��շ���1
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
		printf("1:�Ŷ� 2:��ҽ�� 3:�鿴�Ŷ� 0:�°� ��ѡ��:");
		scanf_s("%d", &sel);
		switch (sel)
		{
		case 0:
			if (!QueueEmpty(lq))
				printf("	>>���ŶӵĻ��������ҽ\n");
			DestroyQueue(lq);
			flag = 0;
			break;
		case 1:
			printf("	>>���뻼������:");
			scanf_s("%s", name);
			EnQueue(lq, name);
			break;
		case 2:
			if (!DeQueue(lq, name))
				printf("	>>û���ŶӵĻ���\n");
			else
				printf("	>>����%s��ҽ��\n", name);
			break;
		case 3:
			printf("	>>�Ŷӻ���:");
			if (!DispQueue(lq))
				printf("	>>û���ŶӵĻ���\n");
			break;
		}
	}
}