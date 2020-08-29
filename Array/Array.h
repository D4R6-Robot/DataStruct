#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stddef.h>

typedef unsigned long int Long;

typedef struct _array {
	void(*front);
	Long capacity;
	Long length;
}Array;

void Create(Array* array, Long capacity, size_t size);
void Destory(Array* array);
Long Store(Array* array, Long index, void* object, size_t size);
Long GetAt(Array* array, Long index, size_t size);
Long Insert(Array* array, Long index, void* object, size_t size);
#endif _ARRAY_H_