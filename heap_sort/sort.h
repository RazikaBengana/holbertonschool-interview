#ifndef SORT_H
#define SORT_H


#include <stdio.h>


/* function for testing */   /* print_array.c */
void print_array(const int *array, size_t size);


/* 0-heap_sort.c */
int getParentIndex(int index);
int getLeftChildIndex(int index);
void heapify(int *array, size_t size);
void siftDown(int *array, size_t size, int start, int end);
void heap_sort(int *array, size_t size);



#endif /* SORT_H */
