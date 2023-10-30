#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  /* Include the <fcntl.h> header for file control options */

/* Function prototypes */
int create_file(const char *filename, char *text_content);
/* Function prototype for read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
