//Author: Uður ÜN
//Date:   15.09.24

#include "nutility.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void set_array_random(int* pa, int size)
{
	while (size--)
		*pa++ = rand() % 1000;
}


void print_array(const int* pa, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", pa[i]);

	}
	printf("\n*******************************************************************************");
}

void randomize(void)
{
	srand((unsigned)time(NULL));
}
