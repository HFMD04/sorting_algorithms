#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sorts array of integers in ascending order.
 * @array: Array of integers.
 * @size: Size of array.
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gaps, k, m;

	if (array == NULL || size < 2)
		return;

	for (gaps = 1; gaps < (size / 3);)
		gaps = gaps * 3 + 1;

	for (; gaps >= 1; gaps /= 3)
	{
		for (k = gaps; k < size; k++)
		{
			m = k;
			while (m >= gaps && array[m - gaps] > array[m])
			{
				swap_ints(array + m, array + (m - gaps));
				m -= gaps;
			}
		}
		print_array(array, size);
	}
}
