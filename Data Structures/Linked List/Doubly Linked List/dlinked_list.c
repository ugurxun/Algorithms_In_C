#include "dlinked_list.h"
#include <stdio.h>
#include <stdlib.h>

HDLinkedList create_dlinkedlist(void)
{
    HDLinkedList hdlinkedlist = (HDLinkedList)malloc(sizeof(HDLinkedList));

    if(!hdlinkedlist)
        return NULL;

    hdlinkedlist->size = 0;
    hdlinkedlist->node_head = NULL;
    hdlinkedlist->node_tail = NULL;

    return hdlinkedlist;
}

bool push_back(HDLinkedList hdlinkedlist , DATATYPE data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(!new_node)
        return false;

    new_node->data = data;

    if(hdlinkedlist->node_head == NULL)
    {
        hdlinkedlist->node_head = hdlinkedlist->node_tail = new_node;
        new_node->next_node = NULL;
        new_node->prev_node = NULL;
        ++hdlinkedlist->size;
    }
    else
    {
        hdlinkedlist->node_tail->next_node = new_node;
        new_node->next_node = NULL;
        new_node->prev_node = hdlinkedlist->node_tail;
        hdlinkedlist->node_tail = new_node;
        ++hdlinkedlist->size;
    }

    return true;

}

bool push_front(HDLinkedList hdlinkedlist , DATATYPE data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(!new_node)
        return false;

    new_node->data = data;

    if(hdlinkedlist->node_head == NULL)
    {
        hdlinkedlist->node_head = hdlinkedlist->node_tail = new_node;
        new_node->next_node = NULL;
        new_node->prev_node = NULL;
        ++hdlinkedlist->size;
    }
    else
    {
        hdlinkedlist->node_head->prev_node = new_node;
        new_node->next_node = hdlinkedlist->node_head;
        new_node->prev_node = NULL;
        hdlinkedlist->node_head = new_node;
        ++hdlinkedlist->size;
    }

    return true;
}

bool insert_idx(HDLinkedList hdlinkedlist , size_t idx, DATATYPE data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(!new_node)
        return false;

    new_node->data = data;

    if(idx == 0)
    {
        push_front(hdlinkedlist,data);
    }
    else if(idx == hdlinkedlist->size - 1)
    {
        push_back(hdlinkedlist, data);
    }
    else
    {
        Node* tnode = hdlinkedlist->node_head;

        while(--idx)
        {
            tnode = tnode->next_node;
        }

        new_node->next_node = tnode->next_node;
        tnode->next_node->prev_node = new_node;
        new_node->prev_node = tnode;
        tnode->next_node = new_node;
        ++hdlinkedlist->size;
    }

    return true;
}

bool pop_back(HDLinkedList hdlinkedlist )
{   
    Node* tnode = hdlinkedlist->node_tail;

    if(hdlinkedlist->node_head == NULL)
    {
        return false;
    }
    else if(hdlinkedlist->node_head == hdlinkedlist->node_tail)
    {
        hdlinkedlist->node_head = NULL;
        hdlinkedlist->node_tail = NULL;
        --hdlinkedlist->size;
        free(tnode);
    }
    else
    {   
        hdlinkedlist->node_tail = hdlinkedlist->node_tail->prev_node;
        hdlinkedlist->node_tail->next_node = NULL;
        --hdlinkedlist->size;
        free(tnode);
    }

    return true;
}

bool pop_front(HDLinkedList hdlinkedlist)
{   
    Node* tnode = hdlinkedlist->node_head;

    if(hdlinkedlist->node_head == NULL)
    {
        return false;
    }
    else if(hdlinkedlist->node_head == hdlinkedlist->node_tail)
    {
        hdlinkedlist->node_head = NULL;
        hdlinkedlist->node_tail = NULL;
        --hdlinkedlist->size;
        free(tnode);
    }
    else
    {   
        hdlinkedlist->node_head = hdlinkedlist->node_head->next_node;
        hdlinkedlist->node_head->prev_node = NULL;
        --hdlinkedlist->size;
        free(tnode);
    }

    return true;
}

bool delete_idx(HDLinkedList hdlinkedlist , size_t idx)
{
    if(idx == 0)
    {
        pop_front(hdlinkedlist);
    }
    else if(idx == hdlinkedlist->size - 1)
    {
        pop_back(hdlinkedlist);
    }
    else
    {
        Node* tnode = hdlinkedlist->node_head;

        while(idx--)
            tnode = tnode->next_node;

        tnode->prev_node->next_node = tnode->next_node;
        tnode->next_node->prev_node = tnode->prev_node;
        --hdlinkedlist->size;
        free(tnode);

        return true;
    }
}

DATATYPE get_idx_value(HDLinkedList hdlinkedlist , size_t idx)
{
    Node* tnode = hdlinkedlist->node_head;

    while(idx--)
        tnode = tnode->next_node;

    return tnode->data;
}

void reverse(HDLinkedList hdlinkedlist)
{
    Node* t_hnode = hdlinkedlist->node_head;
    Node* t_tnode = hdlinkedlist->node_tail;
    DATATYPE tdata;


    for(size_t i = 0; i < (hdlinkedlist->size/2) ;++i)
    {
        tdata = t_hnode->data;
        t_hnode->data = t_tnode->data;
        t_tnode->data = tdata;

        t_hnode = t_hnode->next_node;
        t_tnode = t_tnode->prev_node;
    }

}

void display_hdlinkedlist (HDLinkedList hdlinkedlist )
{
    Node* tnode =  hdlinkedlist->node_head;

    while(tnode)
    {
        printf("%d, ", tnode->data);
        tnode = tnode->next_node;
    } 

    putchar('\n');
}

void clean_hdlinkedlist (HDLinkedList hdlinkedlist )
{
    Node* node, *tnode;

    node = tnode = hdlinkedlist->node_head;
    while(tnode)
    {
        tnode = node->next_node;
        free(node);
        node = tnode;
    }

    hdlinkedlist->node_head = hdlinkedlist->node_tail = NULL; 
    hdlinkedlist->size = 0;
    
}

void destroy_hdlinkedlist (HDLinkedList hdlinkedlist )
{
    clean_hdlinkedlist(hdlinkedlist);
    free(hdlinkedlist);
}