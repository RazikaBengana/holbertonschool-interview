#include "sort.h"

/**
 * getParentIndex - program that gets the index of the parent node
 * in a binary heap
 *
 * @index: the index of the current node
 *
 * Return: the index of the parent node
 */

int getParentIndex(int index)
{
	return ((index - 1) / 2);
}



/**
 * getLeftChildIndex - program that gets the index of the left
 * child node in a binary heap
 *
 * @index: the index of the current node
 *
 * Return: the index of the left child node
 */

int getLeftChildIndex(int index)
{
	return ((2 * index) + 1);
}



/**
 * heapify - program that rearranges the elements in the array
 * to form a valid max heap
 *
 * @array: the array to be converted to a max heap
 * @size: the size of the array
 *
 * Return: nothing (void)
 */

void heapify(int *array, size_t size)
{
	int start;

	start = getParentIndex(size - 1);

	while (start >= 0)
	{
		siftDown(array, size, start, size - 1);
		start--;
	}
}



/**
 * siftDown - program that performs the sift-down operation
 * to maintain the max heap property
 *
 * @array: the array representing the binary heap
 * @size: the size of the array
 * @start: the index from which to start sift-down
 * @end: the index where to stop sift-down
 *
 * Return: nothing (void)
 */

void siftDown(int *array, size_t size, int start, int end)
{
	int root, swap, temp, child;

	root = start;

	while (getLeftChildIndex(root) <= end)
	{
		child = getLeftChildIndex(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}



/**
 * heap_sort - program that sorts an array of integers
 * in ascending order using Heap Sort
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing (void)
 */

void heap_sort(int *array, size_t size)
{
	int iEnd, temp;

	if (!array || size < 2)
		return;

	heapify(array, size);

	iEnd = (int)size - 1;

	while (iEnd > 0)
	{
		temp = array[iEnd];
		array[iEnd] = array[0];
		array[0] = temp;
		print_array(array, size);
		iEnd--;
		siftDown(array, size, 0, iEnd);
	}
}
