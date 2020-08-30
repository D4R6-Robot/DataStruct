#include "Array.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

void Create(Array* array, Int64 capacity, size_t size)
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

Int64 Store(Array* array, Int64 index, void* object, size_t size)
{
	// sizeof(void) : unknown size.
	memcpy((char*)(array->front) + (index * size), object, size);
	array->length++;
	return index;
}

Int64 GetAt(Array* array, Int64 index, size_t size)
{
	return *((char*)(array->front) + (index * size));
}

Int64 Insert(Array* array, Int64 index, void* object, size_t size)
{
	void(*temp);
	Int64 i = 0;
	Int64 j = 0;

	temp = calloc(array->capacity + 1, size);

	while (i < index) {
		memcpy(((char*)temp) + (i * size),
			((char*)array->front) + (j * size),
			size);
		i++;
		j++;
	}

	i++;

	while (j < array->length) {
		memcpy(((char*)temp) + (i * size),
			((char*)array->front) + (j * size),
			size);
		i++;
		j++;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}

	array->front = temp;
	array->capacity++;
	memcpy(((char*)array->front) + (index * size),
		object,
		size);

	array->length++;
	return index;
}

Int64 AppendFromFront(Array* array, void* object, size_t size)
{
	void(*temp);
	Int64 index = 0;
	Int64 i = 0;

	temp = calloc(array->capacity + 1, size);

	while (i < array->length)
	{
		memcpy(((char*)temp) + ((i + 1) * size),
			((char*)array->front) + (i * size),
			size);

		i = i + 1;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}

	array->front = temp;
	array->capacity = array->capacity + 1;
	memcpy(((char*)array->front) + (index * size),
		object,
		size);
	array->length = array->length + 1;

	return index;
}

Int64 AppendFromRear(Array* array, void* object, size_t size)
{
	void(*temp);
	Int64 index = 0;

	temp = calloc(array->capacity + 1, size);

	while (index < array->length)
	{
		memcpy(((char*)temp) + (index * size),
			((char*)array->front) + (index * size),
			size);

		index = index + 1;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}

	array->front = temp;
	array->capacity = array->capacity + 1;
	memcpy(((char*)array->front) + (index * size),
		object,
		size);
	array->length = array->length + 1;

	return index;
}

Int64 Delete(Array* array, Int64 index, size_t size)
{
	void(*temp);
	Int64 i = 0;
	Int64 j = 0;

	if (array->capacity > 1) {
		temp = calloc(array->capacity - 1, size);
	}

	while (i < array->length) {
		if (i != index) {
			memcpy(((char*)temp) + (j * size),
				((char*)array->front) + (i * size),
				size);
			j++;
		}
		i++;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	
	if (array->capacity > 1) {
		array->front = temp;
	}
	array->length = array->length - 1;
	array->capacity = array->capacity - 1;
	index = 0;
	
	return index;
}