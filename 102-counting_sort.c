#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm.
 *
 * @array: array of integers.
 * @size: size of array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, index;
	size_t i, max;

	if (array == NULL || size <= 1)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max)
		{
			max = array[i];
	       	}
	}
	counting_array = (int *)malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max; i++)
	{
		counting_array[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		counting_array[array[i]]++;
	}

	for (i = 1; i <= max; i++)
	{
		counting_array[i] += counting_array[i - 1];
	}
	print_array(counting_array, max + 1);

	index = 0;
	for (i = 0; i <= max; i++)
	{
		 while (counting_array[i] > 0)
		 {
			 array[index++] = i;
			 counting_array[i]--;
		 }
	}
	free(counting_array);
}
