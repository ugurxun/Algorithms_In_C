#ifndef DLINKED_LIST
#define DLINKED_LIST

#include <stddef.h>
#include <stdbool.h>

#define DEFAULT_CAPACITY 10

typedef int DATATYPE;


typedef struct tagNode{
    DATATYPE data;
    struct tagNode* prev_node;
    struct tagNode* next_node;
}Node;

typedef struct TagSLinkedList {
    
    size_t size;
	Node* node_head;
    Node* node_tail;

}DLinkedList, * HDLinkedList;

HDLinkedList create_dlinkedlist(void);

bool push_back(HDLinkedList hdlinkedlist , DATATYPE data);
bool push_front(HDLinkedList hdlinkedlist , DATATYPE data);
bool insert_idx(HDLinkedList hdlinkedlist , size_t idx, DATATYPE data);
bool pop_back(HDLinkedList hdlinkedlist );
bool pop_front(HDLinkedList hdlinkedlist );
bool delete_idx(HDLinkedList hdlinkedlist , size_t idx);

static inline size_t get_size(HDLinkedList hdlinkedlist )
{
	return hdlinkedlist ->size;
}

DATATYPE get_idx_value(HDLinkedList hdlinkedlist , size_t idx);
void reverse(HDLinkedList hdlinkedlist);
void display_hdlinkedlist (HDLinkedList hdlinkedlist );

void clean_hdlinkedlist (HDLinkedList hdlinkedlist );
void destroy_hdlinkedlist (HDLinkedList hdlinkedlist );

#endif //DLINKED_LIST