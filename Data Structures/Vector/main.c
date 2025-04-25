#include<stdio.h>
#include "vector.h"

int main(void)
{   
    printf("TEST OF CREATE_VECTOR\n");
    HVector v1 = create_vector(8);
    printf("v1 size: %zu\n", get_size(v1));
    printf("v1 capacity: %zu\n", get_capacity(v1));
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CAPACITY EXCEEDED\n");
    for(int i = 0;i<10;++i)
        push_back(v1,i);
    printf("v1 size: %zu\n", get_size(v1));
    printf("v1 capacity: %zu\n", get_capacity(v1));
    display_vector(v1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CREATE_FILLED_VECTOR\n");
    HVector v2 = create_filled_vector(20, 4);
    printf("v2 size: %zu\n", get_size(v2));
    printf("v2 capacity: %zu\n", get_capacity(v2));
    display_vector(v2);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CREATE_VECTOR_WITH_ARRAY\n");
    const DATATYPE a[5] = {0,1,2,3,4};
    HVector v3 = create_vector_with_array(a,5);
    printf("v3 size: %zu\n", get_size(v3));
    printf("v3 capacity: %zu\n", get_capacity(v3));
    display_vector(v3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF PUSH_BACK\n");
    push_back(v3,12);
    printf("v3 size: %zu\n", get_size(v3));
    printf("v3 capacity: %zu\n", get_capacity(v3));
    display_vector(v3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF INSERT_IDX\n");
    for(int i = 0;i<10;++i)
        insert_idx(v3 ,2,8);
    printf("v3 size: %zu\n", get_size(v3));
    printf("v3 capacity: %zu\n", get_capacity(v3));
    display_vector(v3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF POP_BACK\n");
    pop_back(v3);
    printf("v3 size: %zu\n", get_size(v3));
    printf("v3 capacity: %zu\n", get_capacity(v3));
    display_vector(v3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF GET_IDX_VALUE\n");
    printf("idx[3]: %d\n",get_idx_value(v3 ,3));
    printf("v3  size: %zu\n", get_size(v3));
    printf("v3  capacity: %zu\n", get_capacity(v3));
    display_vector(v3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF SHRINK\n");
    shrink(v3);
    printf("v3  size: %zu\n", get_size(v3));
    printf("v3  capacity: %zu\n", get_capacity(v3));
    display_vector(v3);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CLEAN_VECTOR\n");
    clean_vector(v3);
    printf("v3 size: %zu\n", get_size(v3));
    printf("v3 capacity: %zu\n", get_capacity(v3));
    display_vector(v3);
    printf("--------------------------------------------------------------------------------------\n");

    destroy_vector(v1);
    destroy_vector(v2);
    destroy_vector(v3);

}