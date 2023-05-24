#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{
	int temp;
    
    temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme
 *
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high)
{
	int pivot, i, j;

    pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}

/**
 * quicksort - Recursive function to sort an array using quicksort
 *
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quicksort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot;
        
        pivot = partition(array, low, high);

		quicksort_recursive(array, low, pivot);
		quicksort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1);
}
