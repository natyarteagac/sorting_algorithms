#include "sort.h"
/**
 * quick_sort - function that sorts and array in ascending
 * order using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == 0 || size == 0)
		return;
	/*Function that takes firts and last index in the array*/
	quicksort(array, 0, size - 1, size);
}

/**
 * partition - parts the elements of the array
 * @array: array of integers
 * @low: first index in the array
 * @high: last element in the array
 * @size: Size of the array.
 * Return: smallest index
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /*pivot*/
	int i = low - 1;		 /* Position -1 of array to start */
	int temp, j;

	/* traverse the elements of the given array */
	for (j = low; j <= high - 1; j++)
	{
		/*Compare the elements*/
		if (array[j] < pivot)
		{
			i++;
			/*Swapping*/
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (j != i)
				print_array(array, size);
		}
	}
	/*Swapping second time*/
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (high != i + 1)
		print_array(array, size);
	return (i + 1);
}
/**
 * quicksort - sorts and array using recursion
 * @array: array of integers
 * @lower: first index in the array
 * @upper: last element in the array
 * @size: size of the array
 * Return: void
*/
void quicksort(int *array, int lower, int upper, size_t size)
{
	int pi;

	if (lower < upper)
	{
		/*pi returns the partitioned array*/
		pi = partition(array, lower, upper, size);
		/*Sorts the left elements of the array*/
		quicksort(array, lower, pi - 1, size);
		/*Sorts the right elements of the array*/
		quicksort(array, pi + 1, upper, size);
	}
}
