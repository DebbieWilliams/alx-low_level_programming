#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip
 *            to get from one number to another
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m; /* XOR to find the differing bits */
	unsigned int count = 0;

	while (diff > 0)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}
