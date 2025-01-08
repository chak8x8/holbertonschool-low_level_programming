#include "main.h"

/**
 * open_file_for_read - Opens a file in read-only mode.
 * @filename: The name of the file to open.
 *
 * Description: If the file cannot be opened, prints an error message
 * and returns -1 (the caller decides what to do next).
 *
 * Return: File descriptor on success, or -1 on failure.
 */
int open_file_for_read(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			filename);
	return (fd);
}

/**
 * open_file_for_write - Opens a file for writing (create/truncate).
 * @filename: The name of the file to open.
 *
 * Description: Opens a file in write-only mode, creating it if needed,
 * and truncating existing content. If it fails, prints an error
 * and returns -1.
 *
 * Return: File descriptor on success, or -1 on failure.
 */
int open_file_for_write(const char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	return (fd);
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 *
 * Description: If closing fails, prints an error and exits with code 100.
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
 * @file_from: Source file descriptor.
 * @file_to: Destination file descriptor.
 * @file_from_name: Source file name (for error messages).
 * @file_to_name: Destination file name (for error messages).
 *
 * Description: Reads from file_from in chunks of 1024 bytes and writes
 * to file_to. If a read or write error happens, prints the corresponding
 * error and exits with code 98 or 99.
 */
void copy_content(int file_from, int file_to,
	const char *file_from_name, const char *file_to_name)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(file_from, buffer, 1024)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
				file_to_name);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from_name);
		exit(98);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the argument strings.
 *
 * Description: Usage: cp file_from file_to
 *    - Exits with code 97 if the argument count is incorrect.
 *    - Exits with 98 if file_from can't be read.
 *    - Exits with 99 if file_to can't be created or written.
 *    - Exits with 100 if a file descriptor can't be closed.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open_file_for_read(argv[1]);
	if (file_from == -1)
		exit(98);

	file_to = open_file_for_write(argv[2]);
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
