#include "slinked_list.h"
#include <stdio.h>

int main(void)
{
    HSLinkedList sll1 = create_slinkedlist();
    
    printf("TEST OF PUSH_BACK\n");
    for(int i=0; i<10;++i)
        push_back(sll1,(DATATYPE)i);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF PUSH_FRONT\n");
    push_front(sll1,7);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF INSERT_IDX\n");
    insert_idx(sll1,0,15);
    insert_idx(sll1,11,15);
    insert_idx(sll1,3,15);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF POP_BACK\n");
    pop_back(sll1);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF POP_FRONT\n");
    pop_front(sll1);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    printf("--------------------------------------------------------------------------------------\n");
    
    printf("TEST OF DELETE_IDX\n");
    delete_idx(sll1,0);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    delete_idx(sll1,10);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    delete_idx(sll1,8);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    delete_idx(sll1,1);
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF GET_IDX_VALUE\n");
    printf("idx[3]: %d\n",get_idx_value(sll1,3));
    printf("sll1 size: %zu\n", get_size(sll1));
    display_hslinkedlist(sll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CLEAN\n");
    clean_hslinkedlist(sll1);
    display_hslinkedlist(sll1);

    destroy_hslinkedlist(sll1);
}