#include "sort.h"

void swap_fun(int *num1, int *num2);
int knuth_gap(int size);
void insert_shell_sort(int *arr, int size, int gap);
/**
 * shell_sort - sort array of integer
 * @array: array list
 * @size: the size of array
 */


void shell_sort(int *array, size_t size)
{
	int gap = knuth_gap((int)size);

	insert_shell_sort(array, (int)size, gap);
}


/**
 * knuth_gap - calculate the gap value using the Knuth sequence
 * @size: size of array
 * Return: the gap
 */


int knuth_gap(int size)
{
	int k = 1;

	while (k < (size / 3))
		k = 3 * k + 1;
	return (k);
}

/**
 * insert_shell_sort - insertion sort for a specfic gap
 * @arr: array of list
 * @size: size of array
 * @gap: the gap
 */

void insert_shell_sort(int *arr, int size, int gap)
{
	int i, j;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && arr[j - gap] > arr[j])
			{
				swap_fun(&arr[j], &arr[j - gap]);
				j -= gap;
			}
		}
		print_array(arr, size);
		gap /= 3;
	}
}

/**
 * swap_fun - swaping integer in array list
 * @num1: the first number
 * @num2: the second number
 */

void swap_fun(int *num1, int *num2)
{
	int tmp = *num1;

	*num1 = *num2;
	*num2 = tmp;
}
