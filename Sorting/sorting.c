#include "sorting.h"
#include <stdio.h>

void bubble_sort(data_type* seq, size_t len, sort_type type)
{   
    
    for(size_t i=0; i<len-1; ++i)
    {       
        int is_sorted = 1;
        for(size_t k=0; k<len-i-1; ++k)
            if(type * seq[k] > type * seq[k+1])
            {
                data_type temp = seq[k];
                seq[k] = seq[k+1];
                seq[k+1] = temp;
                is_sorted = 0;
            }
        if(is_sorted)
            break;
    }               
}

void selection_sort(data_type* seq, size_t len, sort_type type)
{
    for(size_t i=0; i<len-1; ++i)
    {   
        data_type* x = seq + i;

        for(size_t k=i+1; k<len; ++k)
        {
            if(type * *x < type * seq[k])
                x = seq + k;
        }

        if(x != seq + i)
        {    
            data_type temp = seq[i];
            seq[i] = *x;
            *x = temp;
        }
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
