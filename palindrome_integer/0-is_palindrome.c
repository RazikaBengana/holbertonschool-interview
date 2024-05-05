#include "palindrome.h"

/**
 * is_palindrome - function that checks whether a given
 * unsigned integer is a palindrome
 *
 * a palindrome number reads the same backward as forward
 *
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long original = n;

	while (n != 0)
	{
		unsigned long digit = n % 10;

		reversed = reversed * 10 + digit;
		n /= 10;
	}

	return ((reversed == original) ? 1 : 0);
}
