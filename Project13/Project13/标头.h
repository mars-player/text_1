typedef struct node
{
	char data;          //����ַ�
	struct node* next;  //ָ����
}LinkString;            //�����������

void Assign(LinkString*& s, char str[]);
void DestroyStr(LinkString*& s);
void StrCopy(LinkString*& s, LinkString* t);
int StrLength(LinkString* s);
int StrEqual(LinkString* s, LinkString* t);
LinkString* Concat(LinkString* s, LinkString* t);
LinkString* SunStr(LinkString* s, int i, int j);
int Index(LinkString* s, LinkString* t);
int InsStr(LinkString*& s, int i, LinkString* t);
int DelStr(LinkString*& s, int i, int j);
LinkString* RepStrAll(LinkString* s, LinkString* s1, LinkString* s2);
void DispStr(LinkString* s);
