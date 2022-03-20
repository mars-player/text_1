
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}SlinkNode;

void InitList(SlinkNode*& L);/*��ʼ�����Ա�*/
void DestroyList(SlinkNode*& L);/*�������Ա�*/
int GetLength(SlinkNode* L);/*�����Ա�ĳ���*/
int GetElem(SlinkNode* L, int i, ElemType& e);/*�����Ա��е�i��Ԫ��*/
int Locate(SlinkNode* L, ElemType x);/*��ֵ��������*/
int InsElem(SlinkNode*& L, ElemType x, int i);/*����Ԫ��*/
int DelElem(SlinkNode*& L, int i);/*ɾ��Ԫ��*/
void DispList(SlinkNode* L);/*������Ա�Ԫ��*/
/*int Nodes(SlinkNode* L, ElemType x); �����Ա�������ֵΪx�Ľ�����* /
/*int Delallx(SlinkNode*& L, ElemType x); ɾ������ֵΪx�Ľ��*/

