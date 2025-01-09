//Author: Uður ÜN
//Date:   15.09.24

#include <stdio.h>
#include "nutility.h"

#define SIZE    20

int main(void)
{

	int a[SIZE];

	randomize();

	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = rand() % 20 + 1;
		printf("%d ", a[i]);
	}
	printf("\n");

	
	for (int i = SIZE; i > 0; --i)
	{
		for (int k = 0; k < SIZE; ++k)
		{
			if (i <= a[k])
				putchar('*');
			else
				putchar(' ');
		}
		putchar('\n');
	}

	printf("algorithm complexity: O(n^2)");

}
