#ifndef SLINKED_LIST
#define SLINKED_LIST

#include <stddef.h>
#include <stdbool.h>

#define DEFAULT_CAPACITY 10

typedef int DATATYPE;


typedef struct tagNode{
    DATATYPE data;
    struct tagNode* next_node;
}Node;

typedef struct TagSLinkedList {
    
    size_t size;
	Node* node_head;
    Node* node_tail;

}SLinkedList, * HSLinkedList;

HSLinkedList create_slinkedlist(void);

bool push_back(HSLinkedList hslinkedlist, DATATYPE data);
bool push_front(HSLinkedList hslinkedlist, DATATYPE data);
bool insert_idx(HSLinkedList hslinkedlist, size_t idx, DATATYPE data);
bool pop_back(HSLinkedList hslinkedlist);
bool pop_front(HSLinkedList hslinkedlist);
bool delete_idx(HSLinkedList hslinkedlist, size_t idx);


static inline size_t get_size(HSLinkedList hslinkedlist)
{
	return hslinkedlist->size;
}

DATATYPE get_idx_value(HSLinkedList hslinkedlist, size_t idx);
void display_hslinkedlist(HSLinkedList hslinkedlist);

void clean_hslinkedlist(HSLinkedList hslinkedlist);
void destroy_hslinkedlist(HSLinkedList hslinkedlist);

#endif //SLINKED_LIST