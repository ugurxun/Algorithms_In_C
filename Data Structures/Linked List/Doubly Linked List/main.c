#include "dlinked_list.h"
#include <stdio.h>

int main(void)
{
    HDLinkedList dll1 = create_dlinkedlist();
    
    printf("TEST OF PUSH_BACK\n");
    for(int i=0; i<10;++i)
        push_back(dll1,(DATATYPE)i);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF PUSH_FRONT\n");
    push_front(dll1,7);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");
    
    printf("TEST OF INSERT_IDX\n");
    insert_idx(dll1,0,15);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    insert_idx(dll1,11,15);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    insert_idx(dll1,3,15);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");
    
    printf("TEST OF POP_BACK\n");
    pop_back(dll1);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF POP_FRONT\n");
    pop_front(dll1);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");
    
    printf("TEST OF DELETE_IDX\n");
    delete_idx(dll1,2);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    delete_idx(dll1,0);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    delete_idx(dll1,9);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF GET_IDX_VALUE\n");
    printf("idx[3]: %d\n",get_idx_value(dll1,3));
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF REVERSE\n");
    reverse(dll1);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    printf("--------------------------------------------------------------------------------------\n");

    printf("TEST OF CLEAN\n");
    clean_hdlinkedlist(dll1);
    printf("dll1 size: %zu\n", get_size(dll1));
    display_hdlinkedlist(dll1);
    
    destroy_hdlinkedlist(dll1);

}