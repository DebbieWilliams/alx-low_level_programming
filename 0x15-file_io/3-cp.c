#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * exec_errors - Handles the occurrence of an execution error
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 * @file_to: Destination file
 */
void exec_errors(int fd_from, int fd_to, char *file_to)
{
	dprintf(2, "Error: Can't write to %s\n", file_to);
	close(fd_from);
	close(fd_to);
	exit(99);
}

/**
 * check_errors - Checks for read or write errors
 * @bytes: The number of bytes
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 * @file: File
 */
void check_errors(ssize_t bytes, int fd_from, int fd_to, char *file)
{
	if (bytes == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", file);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
* main - Copies content of a file to another file
* @arg_c: Count of command line arguments
* @arg_v: Array of command line argument strings
* Return: Always 0
*/
int main(int arg_c, char *arg_v[])
{

	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

if (arg_c != 3)
	{
dprintf(2, "Usage: %s file_from file_to\n", arg_v[0]);
		exit(97);
	}

	fd_from = open(arg_v[1], O_RDONLY);
				fd_to = open(arg_v[2], O_WRONLY | O_CREAT | 
	O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);

	if (fd_from == -1 || fd_to == -1)
		exec_errors(fd_from, fd_to, arg_v[2]);

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
	bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1)
			exec_errors(fd_from, fd_to, arg_v[2]);
	}

	check_errors(bytes_read, fd_from, fd_to, arg_v[1]);

		if ((close(fd_from) == -1) || (close(fd_to) == -1))
	{
				dprintf(2, "Error: Can't close fd %d\n", 
				(close(fd_from) == -1) ? fd_from : fd_to);
		exit(100);
	}

	return (0);
}
