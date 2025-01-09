//Author: Uður ÜN
//Date:   20.10.24

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define SIZE    20

int icmp(const void* vp1, const void* vp2)
{	
	return (*(const int*)vp1 > *(const int*)vp2)  ? 1 : (*(const int*)vp1 < *(const int*)vp2)  ? -1 : 0;
}

int main(void)
{

	int a[SIZE];
	
	randomize();

	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = rand() % 20;
		printf("%d ", a[i]);
	}

	printf("\n ");

	qsort(a,SIZE,sizeof(*a),icmp);

	printf("\n");
	printf("uniques: ");
	
	int prev = 0;
	int post = 2;
	for (int i = 1; i < SIZE-1; ++i)
	{
		if (a[i] != a[prev++] && a[i] != a[post++])
			printf("%d ", a[i]);

	}
	
	printf("\n");
	printf("algorithm complexity: O(nlogn)");


}
