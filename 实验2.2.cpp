#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define ok 1
#define error 0
#define infeasible -1
#define overflow -2

typedef int Status; //Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int QElemType;
//----��������--���е���ʽ�洢�ṹ---- 
typedef struct QNode //������ṹ 
{
	QElemType data; //������ 
	struct QNode* next; //ָ���� 
}QNode, *QueuePtr;
typedef struct linkqueue //������нṹ 
{
	QueuePtr front; //��ͷָ�� 
	QueuePtr rear; //��βָ�� 
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
	printf("������ʵ����ʽ�ṹ���еĲ�����\n");
	printf("���Խ�������С������еȲ�����\n");
	InitLinkQueue(LQ);
	while(flag)
	{
		printf("��ѡ��:\n");
		printf("1.��ʾ��������Ԫ��:\n");
		printf("2.�����:\n");
		printf("3.������:\n");
		printf("4.����еĳ���:\n");
		printf("5.�˳�����:\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				DisplayLinkQueue(LQ);
				break;
			case 2:
				printf("������Ҫ��ӵ�Ԫ��(һ������):");
				scanf("%d", &e);
				EnLinkQueue(LQ, e);
				DisplayLinkQueue(LQ);
				break;
			case 3:
			    temp = DeLinkQueue(LQ, e);
				if(temp == ok)
				{
					printf("����һ��Ԫ��:%d\n", e);
					DisplayLinkQueue(LQ);
				} 
				else printf("����Ϊ�գ�\n");
				break;
			case 4:
				len = LinkQueueLength(LQ);
				printf("���еĳ���Ϊ:%d\n", len);
				break;
			default:
			    flag = 0;
			    printf("�������н�������������˳���\n");
			    getch();
		} 
	} 
} 

Status InitLinkQueue(LinkQueue& Q) //���г�ʼ��
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL; //����һ��ͷ��㣬������βָ��ָ��ͷ���
	return ok;
}

Status DestroyLinkQueue(LinkQueue& Q) //����һ������
{
	QueuePtr p;
	QElemType e;
	while(Q.front != Q.rear)
	   DeLinkQueue(Q,e);
	free(Q.front);
	Q.front = Q.rear = NULL;
	return ok;
}

int LinkQueueLength(LinkQueue& Q) //���еĳ���
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
	p = (QueuePtr)malloc(sizeof(QNode)); //����һ���½��
    p->data = e; 
    p->next = NULL;
    Q.rear->next = p; //����������β
    Q.rear = p; //�޸Ķ�βָ��
    return ok;
}

Status DeLinkQueue(LinkQueue& Q, QElemType& e) //������
{
	QueuePtr p;
	if (Q.front == Q.rear) return error; //�ж϶����Ƿ��ѿգ��ѿշ���error
	p = Q.front->next; //pָ������е�һ��Ԫ��
	e = p->data; //ȡ�ø�Ԫ��ֵ
	Q.front->next = p->next;  //�޸Ķ�βָ��
	if (Q.rear == p) Q.rear = Q.front;  //�������ѿգ��Ѷ�βָ��ָ��ͷ���
	return ok;  //�ɹ������У�����ok
}

Status DisplayLinkQueue(LinkQueue Q)
{
	QueuePtr p;
	int i = 0;
	p = Q.front->next;
	if (p == NULL) printf("����Ϊ�գ�\n");
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


