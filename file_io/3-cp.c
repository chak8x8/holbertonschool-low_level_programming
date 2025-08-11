#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * open_file_for_read - Opens a file in read-only mode.
 * @filename: The name of the file to open.
 *
 * Return: File descriptor on success, exits with 98 on failure.
 */
int open_file_for_read(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_file_for_write - Opens a file for writing, creating or truncating it.
 * @filename: The name of the file to open.
 *
 * Return: File descriptor on success, exits with 99 on failure.
 */
int open_file_for_write(const char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to close.
 *
 * Return: None, exits with 100 on failure.
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
 * copy_file_content - Copies content from one file descriptor to another.
 * @fd_from: Source file descriptor.
 * @from_name: Source file name for error messages.
 * @to_name: Destination file name for error messages.
 *
 * Return: None, exits on error (98 for read, 99 for write).
 */
void copy_file_content(int fd_from, const char *from_name, const char *to_name)
{
	char buf[BUF_SIZE];
	ssize_t r, w, off;
	int fd_to;

	r = read(fd_from, buf, BUF_SIZE);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_name);
		exit(98);
	}

	fd_to = open_file_for_write(to_name);

	while (r > 0)
	{
		for (off = 0; off < r; off += w)
		{
			w = write(fd_to, buf + off, r - off);
			if (w == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to_name);
				close_file(fd_to);
				exit(99);
			}
		}
		r = read(fd_from, buf, BUF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_name);
			close_file(fd_to);
			exit(98);
		}
	}
	close_file(fd_to);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, exits with an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_for_read(argv[1]);
	copy_file_content(fd_from, argv[1], argv[2]);
	close_file(fd_from);
	return (0);
}
