#include"SqStack.cpp"
#include <stdio.h>
void trans(int d, char b[])
{
	SqStack st;
	InitStack(st);
	char ch;
	int i = 0;
	while (d!= 0)
	{
		ch = '0' + d % 2;
		Push(st, ch);
		d /= 2;
	}
	while (!StackEmpty(st))
	{
		Pop(st, ch);
		b[i] = ch;
		i++;
	}
	b[i] = '\0';
	DestroyStack(st);
}

int main()
{
	int d;
	char str[MaxSize];
	do
	{
		printf("输入一个正整数:");
		scanf_s("%d", &d);
	} while (d < 0);
	trans(d, str);
	printf("对应的二进制数:%s\n", str);
}