#include "sort.h"

/**
 * sort_by_current_digit - program that sorts an array's digits
 * based on the current digit represented by 'exp'
 *
 * this function uses a counting sort method to sort digits
 * from the least significant to the most significant
 *
 * @array: the array to be sorted
 * @size: the number of elements in the array
 * @tmp: temporary array used to store intermediate results during sorting
 * @exp: the exponent representing the current digit to sort by
 *
 * Return: 0 to indicate successful completion
 */

int sort_by_current_digit(int *array, ssize_t size, int *tmp, long exp)
{
	ssize_t i;

	int aux[10] = {0};

	for (i = 0; i < size; i++)
		aux[(array[i] / exp) % 10]++, tmp[i] = 0;
	for (i = 1; i < 10; i++)
		aux[i] += aux[i - 1];
	for (i = size - 1; i >= 0; i--)
		tmp[--aux[(array[i] / exp) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	return (0);
}



/**
 * radix_sort - program that performs radix sort on the given array
 *
 * Radix sort is a non-comparative integer sorting algorithm
 * that sorts data with integer keys by grouping the keys
 * by individual digits which share the same significant
 * position and value
 *
 * @array: the array to be sorted
 * @size: the number of elements in the array
 *
 * Return: nothing (void)
 */

void radix_sort(int *array, size_t size)
{
	size_t i;
	long exp = 1;
	int *tmp, max = INT_MIN;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);

	if (!tmp)
		return;

	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;

	while (max / exp > 0)
	{
		sort_by_current_digit(array, size, tmp, exp);
		print_array(array, size);
		exp *= 10;
	}
	free(tmp);
}
