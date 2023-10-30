#include "main.h"

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 on success, 97 on usage error, 98 on file open error, 99 on file close error.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	if (copy_file(argv[1], argv[2]) == -1)
	{
		return (98);
	}

	return (0);
}

/**
 * copy_file - Copies the content of one file to another.
 * @src: The source file name
 * @dest: The destination file name
 *
 * Return: 0 on success, -1 on failure
 */
int copy_file(const char *src, const char *dest)
{
	int fd_src, fd_dest;
	ssize_t r_bytes, w_bytes;
	char buffer[1024];

	fd_src = open(src, O_RDONLY);
	if (fd_src == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		return (-1);
	}

	fd_dest = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		return (-1);
	}

	while ((r_bytes = read(fd_src, buffer, sizeof(buffer)) > 0)
	{
		w_bytes = write(fd_dest, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			return (-1);
		}
	}

	if (r_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		return (-1);
	}

	if (close(fd_src) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_src);
		return (-1);
	}

	if (close(fd_dest) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_dest);
		return (-1);
	}

	return (0);
}
