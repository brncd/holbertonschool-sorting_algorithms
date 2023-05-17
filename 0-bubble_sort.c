#include "sort.h"

/**
 * custom_sort - Sorts an array of ints in ascending order using Bubble Sort
 * @array: Array
 * @size: Size
 */
void custom_sort(int *array, size_t size)
{
    unsigned int cycle = 0;
    int temp = 0, swapped = 0;

    if (size == 1)
        return;
    
    while (cycle != 1)
    {
        for (unsigned int i = 0; i < size - 1; i++)
        {
            if ((array[i] > array[i + 1]) && ((i + 1) < size))
            {
                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
                swapped = 1;
                print_array(array, size);
            }
        }

        if (swapped == 0)
            cycle = 1;
    }
}
