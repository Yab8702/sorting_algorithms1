#include "sort.h"

void swap_fun(int *, int *);
/**
 * bubble_sort - sort an array of integer in ascending order
 * @array: the array
 * @size: size of array
 */


void bubble_sort(int *array, size_t size)
{
	size_t i, swp_flag = 1, size_1 = size;

	if (array == NULL || size < 2)
		return;
	while (swp_flag)
	{
		swp_flag = 0;
		for (i = 0; i < size_1 - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_fun(&array[i], &array[i + 1]);
				print_array(array, size);
				swp_flag = 1;
			}
		}
		size_1--;
	}
}


/**
 * swap_fun - swap two integer in an array
 * @num1: the first number
 * @num2: the second number
 */

void swap_fun(int *num1, int *num2)
{
	int tmp = *num1;

	*num1 = *num2;
	*num2 = tmp;
}
