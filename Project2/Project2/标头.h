typedef struct node
{
	float coef; /*ϵ��*/
	int exp; /*ָ��*/
	struct node* next; /*ָ����һ������ָ��*/
}PolyNode;

void CreateListR(PolyNode*& L, double a[], int b[], int n);
void DestroyList(PolyNode*& L);
void DispPoly(PolyNode* L);
void Add(PolyNode* ha, PolyNode* hb, PolyNode*& hc);

