#include "main.h"

/**
 * open_file_for_read - Opens a file in read-only mode.
 * @filename: The file to open.
 *
 * Return: File descriptor on success, -1 on failure.
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
 * @filename: The file to open.
 *
 * Return: File descriptor on success, -1 on failure.
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
 * close_file - Closes a file descriptor, prints error & exits if failure.
 * @fd: The file descriptor to close.
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
 * copy_content - Copies content from one file descriptor to another.
 * @file_from: Source file descriptor.
 * @file_to: Destination file descriptor.
 * @file_from_name: Source file name (for error messages).
 * @file_to_name: Destination file name (for error messages).
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
	/* After the loop, check if read failed (-1) */
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from_name);
		exit(98);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of command-line arguments.
 * @argv: Command-line argument strings.
 *
 * Return: 0 on success, or an exit code on error.
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
