#include "标头.h"
#include <stdio.h>
#include <malloc.h>
void Assign(LinkString*& s, char str[]) //串赋值运算
{
	int i = 0;
	LinkString* p, * tc;
	s = (LinkString*)malloc(sizeof(LinkString));
	tc = s;  //tc指向s串的尾结点
	while (str[i] != '\0')
	{
		p = (LinkString*)malloc(sizeof(LinkString));
		p->data = str[i];
		tc->next = p; tc = p;
		i++;
	}
	tc->next = NULL; //尾结点的next置NULL
}

void DestroyStr(LinkString*& s) //销毁串运算
{
	LinkString* pre = s, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next; //pre、p同步后移
	}
	free(pre);
}

void StrCopy(LinkString*& s, LinkString* t)  //串复制运算
{
	LinkString* p = t->next, * q, * tc;
	s = (LinkString*)malloc(sizeof(LinkString));
	tc = s;            //tc指向串s的尾结点
	while (p != NULL)  //复制t的所有结点
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		tc->next = q; tc = q;
		p = p->next;
	}
	tc->next = NULL;   //尾结点的next置NULL
}

int StrLength(LinkString* s) //求串长运算
{
	int n = 0;
	LinkString* p = s->next;
	while (p != NULL)  //扫描链串s的所有数据结点
	{
		n++;
		p = p->next;
	}
	return n;
}

int StrEqual(LinkString* s, LinkString* t) //判断串相等运算
{
	LinkString* p = s->next, * q = t->next;
	while (p != NULL && q != NULL)  //比较两串的当前结点
	{
		if (p->data != q->data)     //data域不等时返回0
			return 0;
		p = p->next;                //p、q均后移一个结点
		q = q->next;
	}
	if (p != NULL || q != NULL)     //两串长度不等时返回0
		return 0;               
	else return 1;                  //两串相等时返回1
}

LinkString* Concat(LinkString* s, LinkString* t) //串连接运算
{
	LinkString* p = s->next, * q, * tc, * r;
	r = (LinkString*)malloc(sizeof(LinkString));
	tc = r;   //tc总是指向新链串的尾结点
	while (p != NULL)  //将s串复制给r
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		tc->next = q; tc = q;
		p = p->next;
	}
	p = t->next;
	while (p != NULL)  //将t串复制给r
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		tc->next = q; tc = q;
		p = p->next;
	}
	tc->next = NULL;
	return r;
}

LinkString* SunStr(LinkString* s, int i, int j) //求子串运算
{
	int k = 1;
	LinkString* r, * p = s->next, * q, * tc;
	r = (LinkString*)malloc(sizeof(LinkString));
	r->next = NULL;  //先置r为一个空串
	if (i < 1) return r;  //i参数错误返回空串
	tc = r;  //tc总是指向新链串的尾结点
	while (k < i && p != NULL)  //在s中找第i个结点p
	{
		p = p->next;
		k++;
	}
	if (p == NULL) return r;  //i参数错误返回空串
	k = 1; q = p; 
	while (k < j && q != NULL) //判断j参数是否正确
	{
		q = q->next;
		k++;
	}
	if (q == NULL) return r;  //j参数错误返回空串
	k = 1;
	while (k <= j && p != NULL)  //复制从p结点开始的j个结点到r中
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		tc->next = q; tc = q;
		p = p->next;
		k++;
	}
	tc->next = NULL;
	return r;
}

int Index(LinkString* s, LinkString* t)  //查找子串位置运算
{
	LinkString* p = s->next, * p1, * q, * q1;
	int i = 1;
	while (p != NULL)  //遍历s的每个结点
	{
		q = t->next;   //总是从t的第一个字符开始比较
		if (p->data == q->data) //判定两串当前字符相等
		{  //若首字符相同，则判定s其后字符是否与t之后字符依次相同
			p1 = p->next;  //p1、p2同时后移一个结点
			q1 = q->next;
			while (p1 != NULL && q1 != NULL && p1->data == q1->data)
			{
				p1 = p1->next;  //p1、p2同时后移一个结点
				q1 = q1->next;
			}
			if (q1 == NULL)  //若都相同，则返回相同的子串的起始位置
				return i;
		}
		p = p->next; i++;
	}
	return 0;  //若不时子串，返回0
}

int InsStr(LinkString*& s, int i, LinkString* t) //子串t插入链串s的第i个位置
{
	LinkString* p = s, * q, * r;  //p指向s的头结点
	int k = 1;
	if (i < 1) return 0;  //参数i错误返回0
	while (k < i && p != NULL)  //从头结点开始找第i个结点即第i-1个数据结点p
	{
		k++;
		p = p->next;
	}
	if (p == NULL) return 0;  //参数i错误返回0
	q = t->next;   //q指向t的第一个数据结点
	while (q != NULL)  //参数正确将t的所有结点复制并插入到结点p之后
	{
		r = (LinkString*)malloc(sizeof(LinkString));
		r->data = q->data;
		r->next = p->next;
		p->next = r;
		p = p->next;
		q = q->next;
	}
	return 1;
}

int DelStr(LinkString*& s, int i, int j) //删除串s中从第i个位置开始的j个字符
{
	LinkString* p = s, * q;  //p指向s的头结点
	int k = 1;
	if (i < 1 || j < 1)return 0; //i、j参数错误返回0
	while (k < i && p != NULL)  //从头结点开始找第i-1个数据结点p
	{
		p = p->next;
		k++;
	}
	if (p == NULL) return 0;
	k = 1;
	q = p->next;
	while (k < j && q != NULL)  //判断j参数是否正确
	{
		q = q->next;
		k++;
	}
	if (q == NULL) return 0;  //j参数错误返回空串
	k = 1;
	while (k <= j)  //删除p结点之后的j个结点
	{
		q = p->next;
		if (q->next == NULL) //若结点q是尾结点
		{
			free(q);         //释放q结点
			p->next = NULL;  //p结点成为尾结点
		}
		else                 //若q不是尾结点
		{
			p->next = q->next; //删除q结点
			free(q);  //释放q结点
		}
		k++;
	}
	return 1;  //成功删除返回1
}

LinkString* RepStrAll(LinkString* s, LinkString* s1, LinkString* s2) //将链串s中所有出现的子串s1均替换成s2，返回被替换后的结果链串
{
	int i;
	i = Index(s, s1);
	while (i > 0)
	{
		DelStr(s, i, StrLength(s1)); //删除子串s1
		InsStr(s, i, s2);            //插入子串s2
		i = Index(s, s1);
	}
	return s;
}

void DispStr(LinkString* s)  //输出串运算
{
	LinkString* p = s->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

