#ifndef VECTOR
#define VECTOR

#include <stddef.h>
#include <stdbool.h>

#define DEFAULT_CAP 8

typedef int DATATYPE;

typedef struct TagVector {

	DATATYPE* vector_head;
	size_t size;
	size_t capacity;

}Vector, * HVector;


HVector create_vector();
HVector create_filled_vector(size_t sz, DATATYPE data);
HVector create_vector_with_array(const DATATYPE* parray, size_t length);


bool push_back(HVector HVector, DATATYPE data);
bool insert_idx(HVector HVector, size_t idx, DATATYPE data);
bool pop_back(HVector HVector);

static inline size_t get_size(HVector HVector)
{
	return HVector->size;
}
static inline size_t get_capacity(HVector HVector)
{
	return HVector->capacity;
}
DATATYPE get_idx_value(HVector HVector, size_t idx);
void display_vector(HVector HVector);
bool shrink(HVector HVector);

bool clean_vector(HVector HVector);
void destroy_vector(HVector HVector);


#endif //VECTOR