void TransaMat(int A[MAX], int B[][MAX], int m, int n) //��m*n������A��ת�þ���B
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			B[i][j] = A[j][i];
}

void MutMat(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int k)
{  //ʵ��һ��m*n����������A��һ��n*k����������B���������
	int i, j, l;
	for (i = 0; i < m; i++)
		for (j = 0; j < k; j++)
		{
			C[i][j] = 0;
			for (l = 0; l < n; l++)
				C[i][j] += A[i][l] * B[l][j];
		}
}