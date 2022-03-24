#define MaxSize 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}Sqlist;
void InitList(Sqlist& L);
void DestroyList(Sqlist L);
int GetLength(Sqlist L);
int GetElem(Sqlist L, int i, ElemType& e);
int Locate(Sqlist L, ElemType x);
int InsElem(Sqlist& L, ElemType x, int i);
int DelElem(Sqlist& L, int i);
void DispList(Sqlist L);
void CreateList(Sqlist& L, ElemType a[], int n);
