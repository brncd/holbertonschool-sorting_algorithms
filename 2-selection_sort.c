#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j, min_idx, tmp;

	while (i < (size - 1))
	{
		min_idx = i;
		j = i + 1;

		while (j < size)
		{
			if (array[min_idx] > array[j])
				min_idx = j;
			j++;
		}

		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}

		i++;
	}
}
