#include "slinked_list.h"
#include <stdio.h>
#include <stdlib.h>

HSLinkedList create_slinkedlist(void)
{
    HSLinkedList hslinkedlist = (HSLinkedList)malloc(sizeof(HSLinkedList));

    if(!hslinkedlist)
        return NULL;

    hslinkedlist->size = 0;
    hslinkedlist->node_head = NULL;
    hslinkedlist->node_tail = NULL;
    return hslinkedlist;
}


bool push_back(HSLinkedList hslinkedlist, DATATYPE data)
{   
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if(!new_node)
        return false;

    if(hslinkedlist->node_head == NULL)
        hslinkedlist->node_head = new_node;
    else
        hslinkedlist->node_tail->next_node = new_node;
    
    new_node->data = data;
    new_node->next_node = NULL;
    hslinkedlist->node_tail = new_node;
    ++hslinkedlist->size;

    return true;

}

bool push_front(HSLinkedList hslinkedlist, DATATYPE data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    if(!new_node)
        return false;

    if(hslinkedlist->node_head == NULL)
        hslinkedlist->node_head = new_node;
    else
        new_node->next_node = hslinkedlist->node_head;

    new_node->data = data;
    hslinkedlist->node_head = new_node;
    ++hslinkedlist->size;

    return true;
}

bool insert_idx(HSLinkedList hslinkedlist, size_t idx, DATATYPE data)
{   
    if(hslinkedlist->size < (idx+1))
        return false;
    
    if(idx == 0)
    {
        return push_front(hslinkedlist,data);
    }
    else if(idx + 1 == hslinkedlist->size )
    {
        return push_back(hslinkedlist,data);
    }
    else
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        Node* temp_node = hslinkedlist->node_head; 
        if(!new_node)
            return false;

        while(--idx)
            temp_node = temp_node->next_node;

        new_node->data = data;
        new_node->next_node = temp_node->next_node;
        temp_node->next_node =  new_node;
        ++hslinkedlist->size;
    }
    return true;

}

bool pop_back(HSLinkedList hslinkedlist)
{

    if(!hslinkedlist->node_head)
    {
        return false;
    }
    else if(hslinkedlist->size == 1)
    {
        free(hslinkedlist->node_head);
        hslinkedlist->node_head = NULL;
        hslinkedlist->node_tail = NULL;
        --hslinkedlist->size;
    }
    else
    {
        Node* tnode = hslinkedlist->node_head;
        size_t count = hslinkedlist->size -2;

        while(count--)
            tnode = tnode->next_node;

        free(tnode->next_node);
        tnode->next_node = NULL;
    }

    return true;
}

bool pop_front(HSLinkedList hslinkedlist)
{
    if(!hslinkedlist->node_head)
        return false;
    
    Node* tnode = hslinkedlist->node_head;    
    hslinkedlist->node_head = hslinkedlist->node_head->next_node;
    --hslinkedlist->size;
    free(tnode);
    return true;
}

bool delete_idx(HSLinkedList hslinkedlist, size_t idx)
{
    if(!hslinkedlist->node_head)
        return false;

    if(idx == 0)
    {
        return pop_front(hslinkedlist);
    }
    else if(idx + 1 == hslinkedlist->size )
    {
        return pop_back(hslinkedlist);
    }
    else
    {
        Node* node = hslinkedlist->node_head; 
        Node* tnode;

        while(--idx)
            node = node->next_node;

        tnode = node->next_node;    
        node->next_node = node->next_node->next_node;
        free(tnode);
        --hslinkedlist->size;
    }
    return true;
}

DATATYPE get_idx_value(HSLinkedList hslinkedlist, size_t idx)
{   
    Node* temp_node = hslinkedlist->node_head; 

    while(idx--)
        temp_node = temp_node->next_node;

    return temp_node->data;
}

void display_hslinkedlist(HSLinkedList hslinkedlist)
{   
    Node* tnode = hslinkedlist->node_head;
    while(tnode)
    {
        printf("%d, ",tnode->data);
        tnode = tnode->next_node;
    }
    putchar('\n');
}


void clean_hslinkedlist(HSLinkedList hslinkedlist)
{
    Node* tnode, *temp_node;

    tnode = temp_node = hslinkedlist->node_head;
    while(temp_node)
    {
        temp_node = tnode->next_node;
        free(tnode);
        tnode = temp_node;
    }

    hslinkedlist->node_head = hslinkedlist->node_tail = NULL; 
    hslinkedlist->size = 0;
}

void destroy_hslinkedlist(HSLinkedList hslinkedlist)
{
    clean_hslinkedlist(hslinkedlist);
    free(hslinkedlist);
}
