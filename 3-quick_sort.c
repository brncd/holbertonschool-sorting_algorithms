#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
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

    i = low - 1;
    pivot = array[high];
    

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

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
        int pivot = partition(array, low, high);

        quicksort_recursive(array, low, pivot - 1);
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