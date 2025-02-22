#ifndef DYNAMIC_ARRAY 
#define DYNAMIC_ARRAY

#include <stddef.h>
#include <stdbool.h>

typedef int DATATYPE;

typedef struct TagDArray {

	DATATYPE* darray_head;
	size_t size;
	size_t capacity;

}DArray, * HDArray;


HDArray create_darray(size_t cap);
HDArray create_filled_darray(size_t sz, DATATYPE data);
HDArray create_darray_with_array(const DATATYPE* parray, size_t length);


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
DATATYPE get_idx_value(HDArray hdarray, size_t idx);
void display_darray(HDArray hdarray);
bool shrink(HDArray hdarray);

bool clean_darray(HDArray hdarray);
void destroy_darray(HDArray hdarray);


#endif //DYNAMIC_ARRAY 