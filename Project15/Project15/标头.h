#define MaxSize 100  //矩阵中非零元素的最多个数
#define M 6
#define N 7
typedef int ElemType;  
typedef struct        
{ 
	int r;  //行号
	int c;  //列号
	ElemType d;  //元素值为ElemType类型
}TupNode;   //三元组定义
typedef struct
{
	int rows;  //行数
	int cols;  //列数
	int nums;  //非零元素个数
	TupNode data[MaxSize];
}TSMatrix;     //三元组顺序表定义

void CreatMat(TSMatrix& t, ElemType A[M][N]);
int Value(TSMatrix& t, ElemType x, int i, int j);
int Assign(TSMatrix t, ElemType& x, int i, int j);
void DispMat(TSMatrix t);
