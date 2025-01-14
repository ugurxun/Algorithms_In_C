#ifndef DYNAMIC_ARRAY 
#define DYNAMIC_ARRAY

#include <stdio.h>
#include <stdbool.h>

#define DEFAULT_CAP 1000

typedef int DATATYPE;

typedef struct TagDArray {

	DATATYPE* darray_head;
	size_t size;
	size_t capacity;

}DArray, * HDArray;


HDArray create_darray(size_t cap);
HDArray create_filled_darray(size_t cap, DATATYPE data);
HDArray create_darray_with_array(DATATYPE* parray);


bool push_back(HDArray hdarray, DATATYPE data);
bool insert_idx(HDArray hdarray, size_t idx, DATATYPE data);
bool pop_back(HDArray hdarray);

static inline size_t get_size(HDArray hdarray)
{
	return hdarray->size;
}
static inline size_t get_capacity(HDArray hdarray)
{
	return hdarray->capacity;
}
size_t get_idx_value(HDArray hdarray, size_t idx);
void print_vector(HDArray hdarray);

HDArray clean_vector(HDArray hdarray);
void destroy_vector(HDArray hdarray);


#endif // !DYNAMIC_ARRAY 

