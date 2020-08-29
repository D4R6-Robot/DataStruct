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

void Destory(Array* array)
{
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
}

Long Store(Array* array, Long index, void* object, size_t size)
{
	// sizeof(void) : unknown size.
	memcpy((char*)(array->front) + (index * size), object, size);
	array->length++;
	return index;
}

Long GetAt(Array* array, Long index, size_t size)
{
	return *((char*)(array->front) + (index * sizeof(Long)));
}

Long Insert(Array* array, Long index, void* object, size_t size)
{
	void(*temp);
	Long i = 0;
	Long j = 0;
	Long capacity = array->capacity + 1;

	temp = calloc(capacity, size);

	while (i < index) {
		memcpy((char*)temp + (i * size),
			((char*)array->front) + (i * size),
			size);
		i++;
		j++;
	}

	i++;

	while (j < array->length) {
		memcpy((char*)temp + (i * size),
			((char*)array->front) + (i * size),
			size);
		i++;
		j++;
	}

	if (array->front != NULL) {
		array->front = temp;
		array->capacity++;
		memcpy(((char*)array->front) + (index * size),
			object,
			size);

		array->length++;
		return index;
	}
}