#include<stdio.h>
#include "dynamic_array.h"

int main(void)
{   
    printf("TEST OF CREATE_DARRAY\n");
    HDArray d1 = create_darray(8);
    printf("d1 size: %zu\n", get_size(d1));
    printf("d1 capacity: %zu\n", get_capacity(d1));
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CAPACITY EXCEEDED\n");
    for(int i = 0;i<10;++i)
        push_back(d1,i);
    printf("d1 size: %zu\n", get_size(d1));
    printf("d1 capacity: %zu\n", get_capacity(d1));
    display_darray(d1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CREATE_FILLED_DARRAY\n");
    HDArray d2 = create_filled_darray(20, 4);
    printf("d2 size: %zu\n", get_size(d2));
    printf("d2 capacity: %zu\n", get_capacity(d2));
    display_darray(d2);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CREATE_DARRAY_WITH_ARRAY\n");
    const DATATYPE a[5] = {0,1,2,3,4};
    HDArray d3 = create_darray_with_array(a,5);
    printf("d3 size: %zu\n", get_size(d3));
    printf("d3 capacity: %zu\n", get_capacity(d3));
    display_darray(d3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF PUSH_BACK\n");
    push_back(d3,12);
    printf("d3 size: %zu\n", get_size(d3));
    printf("d3 capacity: %zu\n", get_capacity(d3));
    display_darray(d3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF INSERT_IDX\n");
    for(int i = 0;i<10;++i)
        insert_idx(d3,2,8);
    printf("d3 size: %zu\n", get_size(d3));
    printf("d3 capacity: %zu\n", get_capacity(d3));
    display_darray(d3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF POP_BACK\n");
    pop_back(d3);
    printf("d3 size: %zu\n", get_size(d3));
    printf("d3 capacity: %zu\n", get_capacity(d3));
    display_darray(d3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF GET_IDX_VALUE\n");
    printf("idx[3]: %d\n",get_idx_value(d3,3));
    printf("d3 size: %zu\n", get_size(d3));
    printf("d3 capacity: %zu\n", get_capacity(d3));
    display_darray(d3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF SHRINK\n");
    shrink(d3);
    printf("d3 size: %zu\n", get_size(d3));
    printf("d3 capacity: %zu\n", get_capacity(d3));
    display_darray(d3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CLEAN_DARRAY\n");
    clean_darray(d3);
    printf("d3 size: %zu\n", get_size(d3));
    printf("d3 capacity: %zu\n", get_capacity(d3));
    display_darray(d3);
    printf("--------------------------------------------------------------------------------------\n");

    destroy_darray(d1);
    destroy_darray(d2);
    destroy_darray(d3);

}