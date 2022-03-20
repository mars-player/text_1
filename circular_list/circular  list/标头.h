
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}SlinkNode;

void InitList(SlinkNode*& L);/*初始化线性表*/
void DestroyList(SlinkNode*& L);/*销毁线性表*/
int GetLength(SlinkNode* L);/*求线性表的长度*/
int GetElem(SlinkNode* L, int i, ElemType& e);/*求线性表中第i个元素*/
int Locate(SlinkNode* L, ElemType x);/*按值查找运算*/
int InsElem(SlinkNode*& L, ElemType x, int i);/*插入元素*/
int DelElem(SlinkNode*& L, int i);/*删除元素*/
void DispList(SlinkNode* L);/*输出线性表元素*/
/*int Nodes(SlinkNode* L, ElemType x); 求线性表中所有值为x的结点个数* /
/*int Delallx(SlinkNode*& L, ElemType x); 删除所有值为x的结点*/

