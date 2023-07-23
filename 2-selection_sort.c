#include "sort.h"

void swap_fun(int *, int *);
/**
 * selection_sort - sort an array of innteger in ascending order
 * @array: array list
 * @size: sizeof array
 */


void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_index;

	if (array == NULL || size < 2)
		return;
	while (i < size - 1)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
			min_index = (array[j] < array[min_index]) ? j : min_index;
		if (min_index != i)
		{
			swap_fun(&array[min_index], &array[i]);
			print_array(array, size);
		}
		i++;
	}

}

/**
 * swap_fun - swap two integer in array
 * @num1: the first number
 * @num2: the second number
 */

void swap_fun(int *num1, int *num2)
{
	int tmp = *num1;

	*num1 = *num2;
	*num2 = tmp;
}
