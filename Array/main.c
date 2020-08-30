#include <stdio.h>
#include "Array.h"

int main(int argc, char* argv[])
{
	Array array;
	Int64 index;
	Int64 object;
	
	Create(&array, 2, sizeof(Int64));
	printf("array capacity [%lld]\n", array.capacity);

	object = 1;
	index = Store(&array, 0, &object, sizeof(Int64));
	printf("array[%lld] value [%lld]\n", index, GetAt(&array, 0, sizeof(Int64)));
	PrintAll(&array, sizeof(Int64));

	object = 2;
	index = Store(&array, 1, &object, sizeof(Int64));
	printf("array[%lld] value [%lld]\n", index, GetAt(&array, 1, sizeof(Int64)));
	PrintAll(&array, sizeof(Int64));

	object = 3;
	index = AppendFromFront(&array, &object, sizeof(Int64));
	printf("array capacity [%lld]\n", array.capacity);
	printf("array [%lld] value [%lld]\n", index, GetAt(&array, 0, sizeof(Int64)));
	PrintAll(&array, sizeof(Int64));

	object = 4;
	index = AppendFromRear(&array, &object, sizeof(Int64));
	printf("array capacity [%lld]\n", array.capacity);
	printf("array [%lld] value [%lld]\n", index, GetAt(&array, 3, sizeof(Int64)));
	PrintAll(&array, sizeof(Int64));

	object = 5;
	index = Insert(&array, 2, &object, sizeof(Int64));
	printf("array capacity [%lld]\n", array.capacity);
	printf("array [%lld] value [%lld]\n", index, GetAt(&array, 5, sizeof(Int64)));
	PrintAll(&array, sizeof(Int64));

	index = Delete(&array, 1, sizeof(Int64));
	printf("array capacity [%lld]\n", array.capacity);
	printf("array [%lld]\n", index);
	PrintAll(&array, sizeof(Int64));

	index = DeleteFromFront(&array, sizeof(Int64));
	printf("array capacity [%lld]\n", array.capacity);
	printf("array [%lld]\n", index);
	PrintAll(&array, sizeof(Int64));

	index = DeleteFromRear(&array, sizeof(Int64));
	printf("array capacity [%lld]\n", array.capacity);
	printf("array [%lld]\n", index);
	PrintAll(&array, sizeof(Int64));

	return 0;
}