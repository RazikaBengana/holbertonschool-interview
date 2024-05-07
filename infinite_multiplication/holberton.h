#ifndef HOLBERTON_H
#define HOLBERTON_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* _putchar function (if needed) */
int _putchar(char c);


/* 0-mul.c */
unsigned int *createZeroArray(size_t size);
void multiplyStrings(unsigned int *product, char *num1, char *num2,
		     size_t len1, size_t len2);
int isPositiveInteger(char *str);
void displayError(int code);



#endif /* HOLBERTON_H */
