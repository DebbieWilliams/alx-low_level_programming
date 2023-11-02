#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * main - Reads info from an ELF file and prints
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	int fd;
	unsigned char e_ident[16];
	unsigned char buffer[24];

	fd = open(argv[1], O_RDONLY); /*Read ELF file*/
	
	if (read(fd, e_ident, 16) != 16)
	{
		perror("Failed to read ELF file");
		exit(98);
	}
	if (e_ident[0] != 0x7f || e_ident[1] != 'E'
		|| e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		perror("File is not an ELF file\n");
		exit(98);
	}
	printf("Magic: %02x %02x %02x %02x\n",
		e_ident[0], e_ident[1], e_ident[2], e_ident[3]);
	printf("Class: %02x\n", e_ident[4]);
	printf("Data: %02x\n", e_ident[5]);
	printf("Version: %02x\n", e_ident[6]);
	printf("OS/ABI: %02x\n", e_ident[7]);
	printf("ABI Version: %02x\n", e_ident[8]);

	lseek(fd, 36, SEEK_SET);
	if (read(fd, buffer, 24) != 24)
	{
		perror("Failed to read ELF file");
		exit(98);
	}
	printf("Type: %02x %02x\n", buffer[0], buffer[1]);
	printf("Entry point address: %02x %02x %02x %02x\n",
		buffer[16], buffer[17], buffer[18], buffer[19]);

	close(fd);
	return (0);
}
