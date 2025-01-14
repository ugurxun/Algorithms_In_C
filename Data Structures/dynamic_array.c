#include "dynamic_array.h"
#include "stdlib.h"
#include "string.h"


static HDArray resize_capacity(HDArray hdarray)
{
	hdarray->darray_head = realloc(hdarray->darray_head, hdarray->capacity * 2);
	hdarray->capacity *= 2;
}

static bool check_capacity(HDArray hdarray)
{
	return (hdarray->size >= hdarray->capacity) ? false : true;

}


HDArray create_darray(size_t cap)
{
	HDArray hdarray = (HDArray)malloc(sizeof(DArray));
	if (!hdarray)
		return NULL;

	hdarray->darray_head = (DATATYPE*)malloc(cap * sizeof(DATATYPE));
	if (!hdarray->darray_head)
		return NULL;

	hdarray->capacity = cap;
	hdarray->size = 0;

	return hdarray;
}

HDArray create_filled_darray(size_t cap, DATATYPE data)
{
	HDArray hdarray;

	if (!(hdarray = create_darray(cap)))
		return NULL;

	hdarray->size = cap;
	
	for (size_t i = 0; i < hdarray->size;++i)
		*(hdarray->darray_head)++ = data;

	return hdarray;
}

HDArray create_darray_with_array(DATATYPE* parray, size_t asize)
{
	HDArray hdarray;

	if (!(hdarray = create_darray(DEFAULT_CAP)))
		return NULL;

	hdarray->size = asize;

	for (size_t i = 0; i < hdarray->size;++i)
		*(hdarray->darray_head)++ = *parray++;

	return hdarray;
}


bool push_back(HDArray hdarray, DATATYPE data)
{
	while(!check_capacity(hdarray));	
		if (!(hdarray = resize_capacity(hdarray)))
			return false;

	hdarray->darray_head[hdarray->size] = data;
	++hdarray->size;
	return true;
}
bool insert_idx(HDArray hdarray, size_t idx, DATATYPE data)
{
	while (!check_capacity(hdarray));
		if (!(hdarray = resize_capacity(hdarray)))
			return false;

		memmove(hdarray->darray_head + idx + 1, hdarray->darray_head + idx, hdarray->size - idx);
}

bool pop_back(HDArray hdarray)
{
	if (hdarray->size <= 0)
		return false;
	--hdarray->size;
	return true;
}

size_t get_idx_value(HDArray hdarray, size_t idx)
{
	if (hdarray->size < idx)
		return -1;
	return hdarray->darray_head[idx];
}

void print_vector(HDArray hdarray)
{
	for (size_t i = 0; i < hdarray->size; ++i)
		printf("%d\n", *hdarray->darray_head++);
}

HDArray clean_vector(HDArray hdarray)
{
	hdarray->size = 0;
	return hdarray;
}
void destroy_vector(HDArray hdarray)
{
	free(hdarray->darray_head);
	free(hdarray);
}