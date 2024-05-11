#ifndef SORT_H
#define SORT_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* function for testing */   /* print_array.c */
void print_array(const int *array, size_t size);


/* 0-merge_sort.c */
void PrintArray(int *array, int iBeg, int iEnd);
void CopyArray(int *source, int iBeg, int iEnd, int *dest);
void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest);
void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest);
void merge_sort(int *array, size_t size);


#endif /* SORT_H */
