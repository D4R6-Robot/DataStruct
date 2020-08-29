#include <stdio.h>
#include "Array.h"

int main(int argc, char* argv[])
{
	Array array;
	Long index;
	Long object;
	
	Create(&array, 10, sizeof(int));
	printf("%d\n", array.capacity);

	object = 2;
	index = Store(&array, 0, &object, sizeof(int));

	object = 3;
	index = Store(&array, 1, &object, sizeof(int));

	printf("%d\n", GetAt(&array, 0, sizeof(Long)));
	printf("%d\n", GetAt(&array, 1, sizeof(Long)));

	return 0;
}