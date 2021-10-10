#include "stdlib.h"
#include "limits.h"
#include "stdio.h"

int main()
{
	int *array;
	int i = 5;

	array = malloc(4 * i);
	while (--i >= 0)
	{
		array[i] = i;
	}
	i = 0;
	while (i < 10)
	{
		printf("array[%d] = %d\n", i, *array++);
		i++;
	}
}
