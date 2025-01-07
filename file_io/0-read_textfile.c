#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters it should read and print
 *
 * Return: The actual number of letters it could read and print,
 *         or 0 if the file cannot be opened, read, or if write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = -1;
	char *buffer;
	ssize_t bytes_read;
	ssize_t bytes_written;

	/* Step 1: Validate input */
	if (filename == NULL)
	{
		return (0);
	}

	/* Step 2: Open the file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}

	/* Step 3: Allocate memory for the buffer */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	/* Step 4: Read file content into buffer */
	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* Step 5: Write buffer content to stdout */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* Step 6: Clean up and return */
	free(buffer);
	close(fd);
	return (bytes_written);
}
