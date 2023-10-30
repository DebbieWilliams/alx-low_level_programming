#include "main.h"

/**
 * read_textfile - Reads and prints a text file to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_chars, write_chars;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	read_chars = read(fd, buf, letters);
	if (read_chars == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	write_chars = write(STDOUT_FILENO, buf, read_chars);

	close(fd);
	free(buf);

	if (write_chars == -1 || write_chars != read_chars)
		return (0);

	return (write_chars);
}
