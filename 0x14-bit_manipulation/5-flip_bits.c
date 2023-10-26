#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip from one number to another
 * @n: The first number
 * @m: The second number
 * Return: The number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned int count = 0;
    unsigned long int diff = n ^ m;  /* XOR to find the differing bits */

    while (diff != 0)
    {
        count += diff & 1;
        diff >>= 1;  /* Right shift to check the next bit */
    }

    return count;
}
