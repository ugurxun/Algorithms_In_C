#include "dynamic_array.h"
#include "stdlib.h"
#include "string.h"


HDArray create_darray(size_t cap)
{
	HDArray hdarray = (HDArray)malloc(sizeof(DArray));

	if(!hdarray)
		return NULL;

	if(!(hdarray->darray_head = (DATATYPE*)malloc(cap * sizeof(DATATYPE))))
		return NULL;
	
	hdarray->size = 0; 
	hdarray->capacity = cap;

	return hdarray; 
}


HDArray create_filled_darray(size_t sz, DATATYPE data)
{
	HDArray hdarray = (HDArray)malloc(sizeof(DArray));
	size_t cap = sz * 2;

	if(!hdarray)
		return NULL;

	if(!(hdarray->darray_head = (DATATYPE*)malloc(cap * sizeof(DATATYPE))))
		return NULL;
	
	hdarray->size = sz ;
	hdarray->capacity = cap;

	for(size_t i=0; i<sz; ++i)
		hdarray->darray_head[i] = data;

	return hdarray; 
}


HDArray create_darray_with_array(const DATATYPE* parray, size_t length)
{
	HDArray hdarray = (HDArray)malloc(sizeof(DArray));
	
	size_t cap = length * 2;

	if(!hdarray)
		return NULL;

	if(!(hdarray->darray_head = (DATATYPE*)malloc(cap * sizeof(DATATYPE))))
		return NULL;
	
	hdarray->size = length; 
	hdarray->capacity = cap;

	for(size_t i=0; i<length; ++i)
		hdarray->darray_head[i] = parray[i];

	return hdarray; 
}


bool push_back(HDArray hdarray, DATATYPE data)
{
	if(hdarray->capacity <= hdarray->size)
	{
		if(!(hdarray->darray_head = (DATATYPE*)realloc(hdarray->darray_head , 2 * hdarray->capacity * sizeof(DATATYPE))))
			return false;
		hdarray->capacity *= 2;
	}
	
	hdarray->darray_head[hdarray->size++] = data;
	return true;
}		

bool insert_idx(HDArray hdarray, size_t idx, DATATYPE data)
{
	if(hdarray->capacity <= hdarray->size)
	{
		if(!(hdarray->darray_head = (DATATYPE*)realloc(hdarray->darray_head , 2 * hdarray->capacity * sizeof(DATATYPE))))
			return false;
		hdarray->capacity *= 2;
	}

	if(!memmove(hdarray->darray_head + idx + 1, hdarray->darray_head + idx, sizeof(DATATYPE) * ((hdarray->size) - idx)))
		return false;
	
	hdarray->darray_head[idx] = data;
	++hdarray->size;
	return true;
}

bool pop_back(HDArray hdarray)
{
	if(hdarray->size <= 0)
		return false;

	--hdarray->size;
	return true;
}

DATATYPE get_idx_value(HDArray hdarray, size_t idx)
{
	return	hdarray->darray_head[idx];
}
void display_darray(HDArray hdarray)
{
	for(size_t i=0; i<hdarray->size; ++i)
		printf("%d, ", hdarray->darray_head[i]);
	putchar('\n');
}

bool shrink(HDArray hdarray)
{
	if(!(hdarray->darray_head = (DATATYPE*)realloc(hdarray->darray_head,hdarray->size * sizeof(DATATYPE))))
		return false;
	hdarray->capacity = hdarray->size;
}

bool clean_darray(HDArray hdarray)
{
	if(hdarray->size <= 0)
		return false;

	hdarray->size = 0;
	return true;
}
void destroy_darray(HDArray hdarray)
{
	free(hdarray->darray_head);
	free(hdarray);
}

