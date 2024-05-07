#include "holberton.h"

/**
 * createZeroArray - program that initializes an array of unsigned integers
 * with all elements set to zero
 *
 * @size: the number of elements in the array
 *
 * Return: a pointer to the array, or NULL if memory allocation fails
 */

unsigned int *createZeroArray(size_t size)
{
	size_t i;

	unsigned int *array = malloc(sizeof(unsigned int) * size);

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = 0;

	return (array);
}



/**
 * multiplyStrings - program that multiplies two strings representing
 * large integers and stores the result in an array
 *
 * @product: the array to store the result of the multiplication
 * @num1: a string representing the first large integer
 * @num2: a string representing the second large integer
 * @len1: the length of the first integer string
 * @len2: the length of the second integer string
 *
 * Return: nothing (void)
 */

void multiplyStrings(unsigned int *product, char *num1, char *num2,
		     size_t len1, size_t len2)
{
	int i, j;
	int carry;
	int digit1, digit2;

	if (!product || !num1 || !num2)
		return;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2[j] - '0';
			carry += product[i + j + 1] + (digit1 * digit2);
			product[i + j + 1] = carry % 10;
			carry /= 10;
		}

		if (carry > 0)
			product[i + j + 1] += carry;
	}
}



/**
 * isPositiveInteger - program that checks if a string represents
 * a positive integer
 *
 * @str: the string to be checked
 *
 * Return: 1 if the string is a positive integer, 0 otherwise
 */

int isPositiveInteger(char *str)
{
	size_t i;

	for (i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);

	return (1);
}



/**
 * displayError - program that prints an error message and exits the program
 *
 * @code: Exit status code
 *
 * Return: nothing (void)
 */

void displayError(int code)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');

	exit(code);
}



/**
 * main - the entry point
 *
 * this program multiplies two large numbers provided
 * as command-line arguments
 *
 * @argc: the number of command-line arguments
 * @argv: the array of command-line arguments
 *
 * Return: 0 (successful execution)
 */

int main(int argc, char **argv)
{
	size_t len1, len2;
	size_t prodLen;
	size_t i;
	unsigned int *product;

	if (argc != 3 || !isPositiveInteger(argv[1]) || !isPositiveInteger(argv[2]))
	{
		displayError(98);
	}
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	prodLen = len1 + len2;
	product = createZeroArray(prodLen);

	if (!product)
	{
		displayError(98);
	}
	multiplyStrings(product, argv[1], argv[2], len1, len2);

	/* Printing the result skipping leading zeros */
	i = 0;

	while (i < prodLen && product[i] == 0)
	{
		i++;
	}

	if (i == prodLen)
		printf("0");

	for (; i < prodLen; i++)
	{
		printf("%d", product[i]);
	}
	printf("\n");
	free(product);

	return (0);
}

