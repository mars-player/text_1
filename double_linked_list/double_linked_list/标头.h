#include <stdio.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* prior, * next;
}DLinkNode;

void InitList(DLinkNode*& L);
void DestroyList(DLinkNode*& L);
int GetLength(DLinkNode* L);
int GetElem(DLinkNode* L, int i, ElemType& e);
int Locate(DLinkNode* L, ElemType e);
int InsElem(DLinkNode*& L, ElemType x, int i);
int DelElem(DLinkNode*& L, int i);
void DispList(DLinkNode* L);
void CreateListF(DLinkNode*& L, ElemType a[], int n);
void CreateListR(DLinkNode*& L, ElemType a[], int n);
void Delmax(DLinkNode*& L);
int Swap(DLinkNode* L, ElemType x);
