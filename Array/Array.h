#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stddef.h>

typedef signed long int Long;
typedef struct _array {
	void(*front);
	Long capacity;
	Long length;
}Array;

#endif _ARRAY_H_