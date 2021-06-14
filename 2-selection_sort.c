#include "sort.h"

/**
 * selection_sort - sort an array with the Selection sort.
 * @array: Array to sort.
 * @size: Size of the array.
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j, min_indx;
	int tmp;

	if (array == 0 || size == 0)
		return;

	/* Go through the array one by one*/
	for (i = 0; i < size - 1; i++)
	{
		/* Finding the minimun element in a unsorted array*/
		min_indx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_indx])
				min_indx = j;
		}
		/* Swap the minimun element with the first element*/
		if (array[min_indx] < array[i])
		{
			tmp = array[min_indx];
			array[min_indx] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
