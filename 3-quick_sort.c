#include "sort.h"

void swap_fun(int *, int *);
int partition(int *, int, int, size_t);
void splitter(int *, int, int, size_t);
/**
 * quick_sort - sort an array of integer in ascending order
 * @array: the array list
 * @size: the size of array
 */


void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;
	splitter(array, 0, (int)size - 1, size);
}

/**
 * partition - partition an array list
 * @low: the smaller index
 * @high: the higher index
 * @arr: the array of list
 * @size: the size of array
 * Return: the pivot index (@current)
 */

int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], current = low, i;

	for (i = low; i < high; i++)
	{
		if (arr[i] <= pivot)
		{
			if (current < i)
			{
				swap_fun(&arr[i], &arr[current]);
				print_array(arr, size);
			}
			current++;
		}
	}
	if (arr[current] > pivot)
	{
		swap_fun(&arr[high], &arr[current]);
		print_array(arr, size);
	}
	return (current);
}


/**
 * splitter - split quick_sort argument
 * @arr: array of list
 * @size: the size of array
 * @low: the smallest index
 * @high: the largest index
 */

void splitter(int *arr, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high, size);
		splitter(arr, low, pivot_index - 1, size);
		splitter(arr, pivot_index + 1, high, size);
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
