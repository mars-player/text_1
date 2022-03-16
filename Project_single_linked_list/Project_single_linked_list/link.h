typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}SlinkNode;

void InitList(SlinkNode*& L);
void DestroyList(SlinkNode*& L);
int GetLength(SlinkNode* L);
int GetElem(SlinkNode* L, int i, ElemType& e);
int Locate(SlinkNode* L, ElemType e);
int InsElem(SlinkNode*& L, ElemType x, int i);
int DelElem(SlinkNode*& L, int i);
void DispList(SlinkNode* L);
void CreateListF(SlinkNode*& L, ElemType a[], int n);
void CreateListR(SlinkNode*& L, ElemType a[], int n);
