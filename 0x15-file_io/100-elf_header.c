#include "main.h"
#include <elf.h>

/**
 * main - Entry point for displaying ELF header information.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return (EXIT_FAILURE); // Returning 98 on failure
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE); // Returning 98 on failure
    }

    Elf64_Ehdr header;
    ssize_t n = read(fd, &header, sizeof(header));
    if (n == -1) {
        close(fd);
        fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
        return (EXIT_FAILURE); // Returning 98 on failure
    }

    if (n < sizeof(header)) {
        close(fd);
        fprintf(stderr, "Error: File format not recognized\n");
        return (EXIT_FAILURE); // Returning 98 on failure
    }

    close(fd);

    // Print ELF header information
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\nClass: %d-bit\n", (header.e_ident[EI_CLASS] == ELFCLASS32) ? 32 : 64);
    printf("Data: %s\n", (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little-endian" : "2's complement, big-endian");
    printf("Version: %d\n", header.e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", header.e_type);
    printf("Entry point address: %lx\n", (unsigned long)header.e_entry);

    return (EXIT_SUCCESS);
}
