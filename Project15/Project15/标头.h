#define MaxSize 100  //�����з���Ԫ�ص�������
#define M 6
#define N 7
typedef int ElemType;  
typedef struct        
{ 
	int r;  //�к�
	int c;  //�к�
	ElemType d;  //Ԫ��ֵΪElemType����
}TupNode;   //��Ԫ�鶨��
typedef struct
{
	int rows;  //����
	int cols;  //����
	int nums;  //����Ԫ�ظ���
	TupNode data[MaxSize];
}TSMatrix;     //��Ԫ��˳�����

void CreatMat(TSMatrix& t, ElemType A[M][N]);
int Value(TSMatrix& t, ElemType x, int i, int j);
int Assign(TSMatrix t, ElemType& x, int i, int j);
void DispMat(TSMatrix t);
