/*����˳�򴮵�����*/
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
	   printf("�洢�ռ����ʧ��!\n");
	else
	{
		S.length = 0;
		printf("�洢�ռ����ɹ�!\n");
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
	printf("�ַ�������: %d\n", S.length);
}

void Concat(HString& S, HString T)
{
	int i;
	for (i = 0; i < T.length; i++)
	    S.ch[S.length + i] = T.ch[i];
	S.ch[S.length + T.length] = '\n';
	S.length = S.length + T.length;
	printf("���������Ӻ���ַ���:");
	for (i = 0; i < S.length; i++)
	    printf("%c", S.ch[i]);
	printf("\n");
}

int main()
{
	//��δӼ��������ַ�����gets()��ô�ã�
	char c1[100], c2[100];
	HString S, T;
	InitString_str(S);
	InitString_str(T);
	printf("����������Ҫ���ַ���c1:");
	gets(c1);
	StrAssign(S, c1);
	printf("����������Ҫ���ַ���c2:");
	gets(c2);
	StrAssign(T, c2);
	Concat(S, T); 
}

