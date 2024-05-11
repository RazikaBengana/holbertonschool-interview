#ifndef SORT_H
#define SORT_H


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/* function for testing */   /* print_array.c */
void print_array(const int *array, size_t size);


/* 0-radix_sort.c */
int sort_by_current_digit(int *array, ssize_t size, int *tmp, long exp);
void radix_sort(int *array, size_t size);



#endif /* SORT_H */