#include <unistd.h>

/**
 * _putchar - Write a character to standard output
 * @c: The character to write
 * Return: On success, the number of characters written. On error, -1 is returned.
 */
int _putchar(char c) {
    return write(1, &c, 1);
}
