

#include <stdio.h>
#include "util.h"

#define SIZE 20

int main()
{
    
    int a[SIZE];
    
    randomize();

    for (int i = 0; i < SIZE;++i)
    {
        a[i] = (rand() % 2 ? 1 : -1) * rand() % 1000;
    }
    printf("Array: ");
    print_array(a, SIZE);
    
    int max_sum = a[0];
    int cur_sum = a[0];
    int idx_s = 0;
    int idx_e = 0;
    int idx_t = 0;

    for (int i = 1; i < SIZE;++i)
    {
        
        if (cur_sum + a[i] < a[i])
        {
            cur_sum = a[i];
            idx_t = i;
        }
        else
        {
            cur_sum += a[i];
        }

        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
            idx_s = idx_t;
            idx_e = i;
        }
    }

    printf("max sub array is between %d. index to %d. index, and the sum = %d \n", idx_s, idx_e, max_sum);
    print_array(a + idx_s, idx_e - idx_s + 1);

}

