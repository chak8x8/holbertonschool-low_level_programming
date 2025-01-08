#include "main.h"

/**
 * open_file - Opens a file and handles errors.
 * @filename: The name of the file to open.
 * @flags: The flags to use when opening the file.
 * @mode: The file mode (used when creating a new file).
 *
 * Return: The file descriptor on success.
 *         Exits with code 98 if the file cannot be opened.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
	}
	return (fd);
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 *
 * Description: If closing the file descriptor fails, the program
 *              exits with code 100.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - Copies content from one file to another.
 * @file_from: The file descriptor of the source file.
 * @file_to: The file descriptor of the destination file.
 * @file_from_name: The name of the source file (for error messages).
 * @file_to_name: The name of the destination file (for error messages).
 *
 * Description: Reads content from `file_from` in chunks of 1,024 bytes
 *              and writes it to `file_to`. Handles read and write errors.
 *              Exits with code 98 if reading fails, or 99 if writing fails.
 */
void copy_content(int file_from, int file_to,
		const char *file_from_name, const char *file_to_name)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(file_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to_name);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from_name);
		exit(98);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Description: This program copies content from `file_from` to `file_to`.
 *              It handles errors such as incorrect arguments, inability
 *              to read or write files, and issues with file descriptors.
 *
 * Return: 0 on success.
 *
 * Exit codes:
 *  97: Incorrect number of arguments.
 *  98: `file_from` cannot be read or does not exist.
 *  99: `file_to` cannot be created or written to.
 * 100: A file descriptor cannot be closed.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open_file(argv[1], O_RDONLY, 0);
	if (file_from == -1)
		exit(98);

	file_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close_file(file_from);
		exit(99);
	}

	copy_content(file_from, file_to, argv[1], argv[2]);

	close_file(file_from);
	close_file(file_to);

	return (0);
}
