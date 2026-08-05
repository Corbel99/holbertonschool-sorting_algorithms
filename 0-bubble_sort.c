#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble Sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	swapped = 1;

	while (swapped == 1)
	{
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
