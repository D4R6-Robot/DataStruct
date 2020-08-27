#include "Array.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void Create(Array* array, Long capacity, size_t size)
{
	array->front = calloc(capacity, size);
	array->capacity = capacity;
	array->length = 0;
}

void Store(Array* array, Long index, void* object, size_t size)
{
	// sizeof(void) : unknown size.
	memcpy((char*)(array->front) + (index * size), object, size);
	array->length++;
	return index;
}