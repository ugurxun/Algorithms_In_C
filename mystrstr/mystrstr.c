//Author: Uður ÜN
//Date:   14.10.24

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define SIZE 100


char* mystrstr(const char* ps1, const char* ps2)
{
	size_t s1 = strlen(ps1);
	size_t s2 = strlen(ps2);
	size_t k = 0;
	const char* ptemp1 = ps1;
	const char* ptemp2 = ps2;

	while(s1--)
	{
		if (*ps1++ == *ps2++)
		{
			if (++k == s2)
				return ps1-s2;
		}	
		else
		{
			ps2 = ptemp2;
			k=0;
		}
			
	}

	if (!*ps2)
		return ptemp1;
	
	return NULL;
}

int main(void)
{

	char str[SIZE];
	char skey[SIZE];
	printf("Please enter main string: "); 
	sgets(str); 
	printf("Please enter the string to be searched: ");
	sgets(skey);
	printf("(%s) seraching in (%s) ...\n", skey, str);

	char* pfound = mystrstr(str, skey);
	if (pfound) {
		printf("Founded idx = %zu\n", pfound - str);                         
		puts(pfound);                                  
	}
	else
		printf("Not Founded !\n");
}

