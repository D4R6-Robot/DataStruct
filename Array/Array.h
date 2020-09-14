#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stddef.h>

// vcruntime.h
typedef signed __int64 Int64;

typedef struct _array {
	void(*front);
	Int64 capacity;
	Int64 length;
}Array;

void Create(Array* array, Int64 capacity, size_t size);
void Destory(Array* array);
Int64 Store(Array* array, Int64 index, void* object, size_t size);
Int64 GetAt(Array* array, Int64 index, size_t size);
void PrintAll(Array* array, size_t size);
Int64 Insert(Array* array, Int64 index, void* object, size_t size);
Int64 AppendFromFront(Array* array, void* object, size_t size);
Int64 AppendFromRear(Array* array, void* object, size_t size);
Int64 Delete(Array* array, Int64 index, size_t size);
Int64 DeleteFromFront(Array* array, size_t size);
Int64 DeleteFromRear(Array* array, size_t size);
Int64 Modify(Array* array, Int64 index, void* object, size_t size);
void Clear(Array* array);
Int64 LinearSearchUnique(Array* array, void* key, size_t size, int (*compare)(void*, void*));
int CompareIntegers(void* one, void* other);

#endif _ARRAY_H_