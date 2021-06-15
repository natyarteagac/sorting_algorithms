#include "sort.h"
/**
 * quick_sort-function that sorts and array in ascending
 * order using the Quick sort akgorithm
 * @array: array of integers
 * @size: size of the array
 */


void quick_sort(int *array, size_t size)
{
	/*Function that takes firts and last index in the array*/
	quicksort(array, 0, size - 1, size);
}

/**
 * partition - parts the elements of the array
 * @array: array of integers
 * @low: first index in the array 
 * @high: last element in the array
 * Return: smallest index
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /*pivot*/
	int i = low - 1; // Index of smaller element and indicates the right position of pivot found so far
	int temp, j;

	/* traverse the elements of the given array */
	for (j = low; j <= high - 1; j++)
	{
		/* Compare each element with the pivot and
		swap them for sorting */
		if (array[j] < pivot)
		{
			i++; // increment index of smaller element
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (j != i)
				print_array(array, size);
		}
	}
	temp = array[i+1];
	array[i+1] = array[high];
	array[high] = temp;
	if (high != i+1)
		print_array(array, size);
	return (i+1);
}
/**
 * quicksort - sorts and array using recursion
 * @array: array of integers
 * @low: first index in the array 
 * @high: last element in the array
 * @size: size of the array
 * 
*/
void quicksort(int *array, int lower, int upper, size_t size)
{
	int pi;
	
	if (lower < upper) 
	 {
		/* pi that returnes the partitioned place 
		in the array */
		pi = partition(array, lower, upper, size);
		/*Recursion that sorts the elements on the
		left of the pivot*/
		quicksort(array, lower, pi - 1, size);
		/*Recursion that sorts the elements on the 
		right pivot*/
		quicksort(array, pi + 1, upper, size);
	}
}
