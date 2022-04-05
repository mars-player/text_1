void TransaMat(int A[MAX], int B[][MAX], int m, int n) //求m*n型数组A的转置矩阵B
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			B[i][j] = A[j][i];
}

void MutMat(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int k)
{  //实现一个m*n的整型数组A和一个n*k的整型数组B的相乘运算
	int i, j, l;
	for (i = 0; i < m; i++)
		for (j = 0; j < k; j++)
		{
			C[i][j] = 0;
			for (l = 0; l < n; l++)
				C[i][j] += A[i][l] * B[l][j];
		}
}