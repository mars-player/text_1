#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

void Assign(SqString& s, char str[]);
void DestroyStr(SqString);
void StrCopy(SqString& s, SqString t);
int StrLength(SqString s);
int StrEqual(SqString s, SqString);
SqString Concat(SqString s, SqString t);
SqString SubStr(SqString s, int i, int j);
int Index(SqString s, SqString t);
int InsStr(SqString& s, int i, SqString t);
int DelStr(SqString& s, int i, int j);
SqString RepStrAll(SqString s, SqString sl, SqString s2);
void DispStr(SqString s);
int Strcmp(SqString s, SqString t);
int Count(SqString s, SqString t);
