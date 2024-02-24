#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Orders a subset of an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - Implement quick sort algorithm through recursion.
 * @array: array of integer to sort
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 * Description: Uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partit;

	if (right - left > 0)
	{
		partit = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partit - 1);
		lomuto_sort(array, size, partit + 1, right);
	}
}

/**
 * quick_sort - Sorts array of integers i ascending order.
 * @array: array of integers.
 * @size: size of the array.
 * Description: Uses Lomuto partition scheme to print array after swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
