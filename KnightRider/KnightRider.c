
//Author: Ugur UN
//Date:   08.01.25

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdint.h>

void bit_print(uint32_t seq)
{
	for (int i = 31; i >= 0; i--)
	{
		uint32_t bit = (seq >> i) & 1;
		putchar(bit + '0');
	}
}


int main()
{
	uint32_t seq = 1 << 31;
	uint32_t flag = 0;

	for (;;)
	{
		if (seq == 1 << 31)
			flag = 0;

		if (seq == 1)
			flag = 1;

		bit_print(!flag ? (seq >>= 1) : (seq <<= 1));
		Sleep(10);
		system("cls");

	}

}


