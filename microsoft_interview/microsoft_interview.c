//Author: Uður ÜN
//Date:   27.10.24

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define SIZE 1000

int icmp(const void* vp1, const void* vp2)
{
	return (*(const int*)vp1 > *(const int*)vp2) ? 1 : (*(const int*)vp1 < *(const int*)vp2) ? -1 : 0;
}


int main()
{

	int a[SIZE];
	int b[SIZE];
	int c[SIZE];

	int key = 242;
	
	
	randomize();
	set_array_random(a, SIZE);// 0 - 1 000 000  
	set_array_random(b, SIZE);// 0 - 1 000 000  
	set_array_random(c, SIZE);// 0 - 1 000 000  

	
	qsort(c, SIZE, sizeof *c, icmp);

	int* retval;
	int cnt = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		for (int k = 0; k < SIZE; ++k)
		{   
			int cval = key - a[i] - b[k];

			if (cval >= 0 && (retval = (int*)bsearch(&cval, c, SIZE, sizeof * c, icmp)))
			{
				printf("%Founded a[%d] = %d, b[%d] = %d, c[%zu] = %d \n", i, a[i], k, b[k], retval - c, *retval);
				++cnt;
			}
				
		}
	}

	if (cnt)
		printf("%d times\n", cnt);
	else
		printf("Not Founded !");

	printf("complexity = O(n^2logn)");
	
}

