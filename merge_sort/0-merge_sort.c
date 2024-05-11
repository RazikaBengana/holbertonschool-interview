#include "sort.h"

/**
 * PrintArray - program that prints the elements of an array
 * from iBeg to iEnd-1
 *
 * @array: the array to be printed
 * @iBeg: the starting index of the subarray
 * @iEnd: the ending index of the subarray (exclusive)
 *
 * Return: nothing (void)
 */

void PrintArray(int *array, int iBeg, int iEnd)
{
	int i;

	if (!array)
		return;

	for (i = iBeg; i < iEnd; i++)
		if (i < iEnd - 1)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
}



/**
 * CopyArray - program that copies elements from source array
 * to dest array from iBeg to iEnd-1
 *
 * @source: the source array
 * @iBeg: the starting index of the subarray
 * @iEnd: the ending index of the subarray (exclusive)
 * @dest: the destination array
 *
 * Return: nothing (void)
 */

void CopyArray(int *source, int iBeg, int iEnd, int *dest)
{
	int i;

	if (!source || !dest)
		return;

	for (i = iBeg; i < iEnd; i++)
		dest[i] = source[i];
}



/**
 * TopDownMerge - program that merges two sorted subarrays
 * into a single sorted subarray
 *
 * @source: the source array containing two sorted subarrays
 * @iBeg: the starting index of the first subarray
 * @iMid: the ending index of the first subarray
 *        and the starting index of the second subarray
 * @iEnd: the ending index of the second subarray
 * @dest: the destination array to store the merged subarrays
 *
 * Return: nothing (void)
 */

void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest)
{
	int i, j, k;

	if (!source || !dest)
		return;

	i = iBeg, j = iMid;

	printf("Merging...\n");
	printf("[left]: ");
	PrintArray(source, iBeg, iMid);
	printf("[right]: ");
	PrintArray(source, iMid, iEnd);

	for (k = iBeg; k < iEnd; k++)
	{
		if (i < iMid && (j >= iEnd || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	PrintArray(dest, iBeg, iEnd);
}



/**
 * TopDownSplitMerge - program that recursively splits the array
 * into subarrays and merges them
 *
 * @source: the source array to be split and merged
 * @iBeg: the starting index of the subarray
 * @iEnd: the ending index of the subarray (exclusive)
 * @dest: the destination array to store the sorted elements
 *
 * Return: nothing (void)
 */

void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest)
{
	int iMid;

	if (!source || !dest)
		return;

	if (iEnd - iBeg < 2)
		return;

	iMid = (iEnd + iBeg) / 2;

	TopDownSplitMerge(dest, iBeg, iMid, source);
	TopDownSplitMerge(dest, iMid, iEnd, source);
	TopDownMerge(source, iBeg, iMid, iEnd, dest);
}



/**
 * merge_sort - program that sorts an array in non-decreasing order
 * using the merge sort algorithm
 *
 * @array: the array to be sorted
 * @size: the number of elements in the array
 *
 * Return: nothing (void)
 */

void merge_sort(int *array, size_t size)
{
	int *work_copy;

	if (!array || size < 2)
		return;

	work_copy = malloc(sizeof(int) * size);

	if (!work_copy)
		return;

	CopyArray(array, 0, size, work_copy);
	TopDownSplitMerge(work_copy, 0, size, array);

	free(work_copy);
}
