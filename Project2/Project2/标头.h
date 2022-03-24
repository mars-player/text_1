typedef struct node
{
	float coef; /*系数*/
	int exp; /*指数*/
	struct node* next; /*指向下一个结点的指针*/
}PolyNode;

void CreateListR(PolyNode*& L, double a[], int b[], int n);
void DestroyList(PolyNode*& L);
void DispPoly(PolyNode* L);
void Add(PolyNode* ha, PolyNode* hb, PolyNode*& hc);

