#include "sorting.h"
#include <stdio.h>

void bubble_sort(data_type* seq, size_t len, sort_type type)
{   
    for(size_t i=0; i<len-1; ++i)
            for(size_t k=0; k<len-i-1; ++k)
                if(type * seq[k] > type * seq[k+1])
                {
                    data_type temp = seq[k];
                    seq[k] = seq[k+1];
                    seq[k+1] = temp;
                }        
}

void display(data_type* seq, size_t len)
{   
    if (seq[len-1] >= seq[0])
        printf("ASCENDING:\n");
    else
        printf("DESCENDING:\n");
        
    for(size_t i=0; i<len; ++i)
    {
        if(i!=0 && i%20 == 0)
            putchar('\n');
        printf("%d, ",seq[i]);
    }
    putchar('\n');
}
