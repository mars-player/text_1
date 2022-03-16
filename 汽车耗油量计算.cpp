#include <stdio.h>
#include <stdlib.h>
#define Gallon_TO_Litre 3.785
#define MILE_TO_KM 1.609
int main(void)
{
	float range,oil;
	printf("Please input the range you traveled(in mile):");
	scanf("%f",&range);
	printf("Please input the oil you spend(in gallon):");
	scanf("%f",&oil);
	printf("In UAS,your oil wear is %.1fM/G\n",range/oil);
	printf("In Europe,your oil wear is %.1fL/KM\n",(oil*Gallon_TO_Litre)/(range*MILE_TO_KM));
	system("pause");
	return 0;
}
