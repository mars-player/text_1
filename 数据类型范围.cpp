//ʹ��limit.h��floatͷ�ļ��ж������ʾ����
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
int main(void)
{
	printf("Biggest int: %d\n",INT_MAX);
	printf("Smallest long long: %lld\n",LLONG_MAX);
	printf("One byte = %d bits on this system.\n",CHAR_BIT);
	printf("Largest double: %e\n",DBL_MAX);
	printf("Smallest normal float: %e\n",FLT_MIN);
	printf("float precision = %d digits\n",FLT_DIG);
	printf("double precision = %d digits\n",DBL_DIG);
	printf("float epsilon = %e\n",FLT_EPSILON);
	system("pause");
	return 0; 
 } 
