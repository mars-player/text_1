/*两个顺序串的连接*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTRLEN 255
typedef struct
{
	char* ch;
	int length;
}HString;

void InitString_str(HString& S)
{
	S.ch = (char*)malloc(MAXSTRLEN*sizeof(char));
	if (!S.ch)
	   printf("存储空间分配失败!\n");
	else
	{
		S.length = 0;
		printf("存储空间分配成功!\n");
	}	
}
void StrAssign(HString& S, char t[])
{
	int j;
	for (j = 0; t[j] != '\0'; j++)
	    S.ch[j] = t[j];
	S.length = j;
	for (j = 0; j < S.length; j++)
	    printf("%c", S.ch[j]);
	printf("\n");
	printf("字符串长度: %d\n", S.length);
}

void Concat(HString& S, HString T)
{
	int i;
	for (i = 0; i < T.length; i++)
	    S.ch[S.length + i] = T.ch[i];
	S.ch[S.length + T.length] = '\n';
	S.length = S.length + T.length;
	printf("请输入连接后的字符串:");
	for (i = 0; i < S.length; i++)
	    printf("%c", S.ch[i]);
	printf("\n");
}

int main()
{
	//如何从键盘输入字符串？gets()怎么用？
	char c1[100], c2[100];
	HString S, T;
	InitString_str(S);
	InitString_str(T);
	printf("请输入你想要的字符串c1:");
	gets(c1);
	StrAssign(S, c1);
	printf("请输入你想要的字符串c2:");
	gets(c2);
	StrAssign(T, c2);
	Concat(S, T); 
}

