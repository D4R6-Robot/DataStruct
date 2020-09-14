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

void PrintAll(Array* array, size_t size)
{
	Int64 i = 0;

	while (i < array->length) {
		printf("[%lld] %ld\n", i, *((char*)(array->front) + (i * size)));
		i++;
	}
}

Int64 Insert(Array* array, Int64 index, void* object, size_t size)
{
	void(*temps);
	Int64 i = 0;
	Int64 j = 0;

	temps = calloc(array->capacity + 1, size);

	while (i < index) {
		memcpy(((char*)temps) + (i * size),
			((char*)array->front) + (j * size),
			size);
		i++;
		j++;
	}

	i++;

	while (j < array->length) {
		memcpy(((char*)temps) + (i * size),
			((char*)array->front) + (j * size),
			size);
		i++;
		j++;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}

	array->front = temps;
	array->capacity++;
	memcpy(((char*)array->front) + (index * size),
		object,
		size);

	array->length++;
	return index;
}

Int64 AppendFromFront(Array* array, void* object, size_t size)
{
	void(*temps);
	Int64 index = 0;
	Int64 i = 0;

	temps = calloc(array->capacity + 1, size);

	while (i < array->length)
	{
		memcpy(((char*)temps) + ((i + 1) * size),
			((char*)array->front) + (i * size),
			size);

		i = i + 1;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}

	array->front = temps;
	array->capacity = array->capacity + 1;
	memcpy(((char*)array->front) + (index * size),
		object,
		size);
	array->length = array->length + 1;

	return index;
}

Int64 AppendFromRear(Array* array, void* object, size_t size)
{
	void(*temps);
	Int64 index = 0;

	temps = calloc(array->capacity + 1, size);

	while (index < array->length)
	{
		memcpy(((char*)temps) + (index * size),
			((char*)array->front) + (index * size),
			size);

		index = index + 1;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}

	array->front = temps;
	array->capacity = array->capacity + 1;
	memcpy(((char*)array->front) + (index * size),
		object,
		size);
	array->length = array->length + 1;

	return index;
}

Int64 Delete(Array* array, Int64 index, size_t size)
{
	void(*temps) = NULL;
	Int64 i = 0;
	Int64 j = 0;

	if (array->capacity > 1) {
		temps = calloc(array->capacity - 1, size);
	}

	while (i < array->length) {
		if (i != index) {
			memcpy(((char*)temps) + (j * size),
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
		array->front = temps;
	}
	array->length --;
	array->capacity --;
	index = -1;
	
	return index;
}

Int64 DeleteFromFront(Array* array, size_t size)
{
	void(*temps) = NULL;
Int64 index = 1;

if (array->capacity > 1) {
	temps = calloc(array->capacity - 1, size);
}

while (index < array->length) {
	memcpy(((char*)temps) + ((index - 1) * size),
		((char*)array->front) + (index * size),
		size);
	index++;
}

if (array->front != NULL) {
	free(array->front);
	array->front = NULL;
}

if (array->capacity > 1) {
	array->front = temps;
}

array->length--;
array->capacity--;
index = -1;

return index;
}

Int64 DeleteFromRear(Array* array, size_t size)
{
	void(*temps) = NULL;
	Int64 index = 0;

	if (array->capacity > 1) {
		temps = calloc(array->capacity - 1, size);
	}

	while (index < array->length - 1) {
		memcpy(((char*)temps) + (index * size),
			((char*)array->front) + (index * size),
			size);
		index++;
	}

	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}

	if (array->capacity > 1) {
		array->front = temps;
	}

	array->length--;
	array->capacity--;
	index = -1;

	return index;
}

Int64 Modify(Array* array, Int64 index, void* object, size_t size)
{
	memcpy((char*)(array->front) + (index * size), object, size);

	return index;
}

void Clear(Array* array)
{
	if (array->front != NULL) {
		free(array->front);
	}

	array->front = NULL;
	array->capacity = 0;
	array->length = 0;
}

Int64 LinearSearchUnique(Array* array, void* key, size_t size, int (*compare)(void*, void*))
{
	Int64 index = -1;
	Int64 i = 0;

	while ((i < array->length)
		&& compare((char*)(array->front) + (i * size), key) != 0) {
		i++;
	}

	if (i < array->length) {
		index = i;
	}

	return index;
}

int CompareIntegers(void* one, void* other)
{
	int ret;

	if (*((int*)one) > *((int*)other)) {
		ret = 1;
	}
	else if (*((int*)one) == *((int*)other)) {
		ret = 0;
	}
	else {
		ret = -1;
	}

	return ret;
}