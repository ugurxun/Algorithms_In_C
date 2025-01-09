
#include <stdio.h>
#include "nutility.h"

#define SIZE    20

int main(void)
{

	int a[SIZE];
	int flags[SIZE] = { 0 };

	randomize();

	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = rand() % 20;
		flags[a[i]]++;
		printf("%d ", a[i]);
	}

	printf("\n");
	printf("uniques: ");

	for (int i = 0; i < SIZE; ++i)
	{
		if (flags[i] == 1)
			printf("%d ", i);
	}

	printf("\n");
	printf("algorithm complexity: O(n)");


}
