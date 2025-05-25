#ifndef SORTING_H
#define SORTING_H

#define data_type int
#define sort_type int    
#define ASCENDING   1
#define DESCENDING -1
#include <stddef.h>

void bubble_sort(data_type* seq, size_t len, sort_type type);
void display(data_type* seq, size_t len);



#endif //SORTING_H