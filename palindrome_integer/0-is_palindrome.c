#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned long integer is a palindrome.
 *
 * @n: the number to check.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long tmp = 0;
	unsigned long reverse_n = 0;

	tmp = n;

	while (tmp != 0)
	{
		reverse_n = reverse_n * 10;
		reverse_n = reverse_n + tmp % 10;
		tmp = tmp / 10;
	}

	if (n == reverse_n)
	{
		return (1);
	}

	return (0);
}
