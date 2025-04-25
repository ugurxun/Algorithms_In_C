#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


HVector create_vector()
{
	HVector hvector = (HVector)malloc(sizeof(Vector));

	if(!hvector)
		return NULL;

	if(!(hvector->vector_head = (DATATYPE*)malloc(DEFAULT_CAP * sizeof(DATATYPE))))
		return NULL;
	
	hvector->size = 0; 
	hvector->capacity = DEFAULT_CAP;

	return hvector; 
}


HVector create_filled_vector(size_t sz, DATATYPE data)
{
	HVector hvector = (HVector)malloc(sizeof(Vector));
	size_t cap = sz * 2;

	if(!hvector)
		return NULL;

	if(!(hvector->vector_head = (DATATYPE*)malloc(cap * sizeof(DATATYPE))))
		return NULL;
	
	hvector->size = sz ;
	hvector->capacity = cap;

	for(size_t i=0; i<sz; ++i)
		hvector->vector_head[i] = data;

	return hvector; 
}


HVector create_vector_with_array(const DATATYPE* parray, size_t length)
{
	HVector hvector = (HVector)malloc(sizeof(Vector));
	
	size_t cap = length * 2;

	if(!hvector)
		return NULL;

	if(!(hvector->vector_head = (DATATYPE*)malloc(cap * sizeof(DATATYPE))))
		return NULL;
	
	hvector->size = length; 
	hvector->capacity = cap;

	for(size_t i=0; i<length; ++i)
		hvector->vector_head[i] = parray[i];

	return hvector; 
}


bool push_back(HVector hvector, DATATYPE data)
{
	if(hvector->capacity <= hvector->size)
	{
		if(!(hvector->vector_head = (DATATYPE*)realloc(hvector->vector_head , 2 * hvector->capacity * sizeof(DATATYPE))))
			return false;
		hvector->capacity *= 2;
	}
	
	hvector->vector_head[hvector->size++] = data;
	return true;
}		

bool insert_idx(HVector hvector, size_t idx, DATATYPE data)
{
	if(hvector->capacity <= hvector->size)
	{
		if(!(hvector->vector_head = (DATATYPE*)realloc(hvector->vector_head , 2 * hvector->capacity * sizeof(DATATYPE))))
			return false;
		hvector->capacity *= 2;
	}

	if(!memmove(hvector->vector_head + idx + 1, hvector->vector_head + idx, sizeof(DATATYPE) * ((hvector->size) - idx)))
		return false;
	
	hvector->vector_head[idx] = data;
	++hvector->size;
	return true;
}

bool pop_back(HVector hvector)
{
	if(hvector->size <= 0)
		return false;

	--hvector->size;
	return true;
}

DATATYPE get_idx_value(HVector hvector, size_t idx)
{
	return	hvector->vector_head[idx];
}
void display_vector(HVector hvector)
{
	for(size_t i=0; i<hvector->size; ++i)
		printf("%d, ", hvector->vector_head[i]);
	putchar('\n');
}

bool shrink(HVector hvector)
{
	if(!(hvector->vector_head = (DATATYPE*)realloc(hvector->vector_head,hvector->size * sizeof(DATATYPE))))
		return false;
	hvector->capacity = hvector->size;
}

bool clean_vector(HVector hvector)
{
	if(hvector->size <= 0)
		return false;

	hvector->size = 0;
	return true;
}
void destroy_vector(HVector hvector)
{
	free(hvector->vector_head);
	free(hvector);
}

