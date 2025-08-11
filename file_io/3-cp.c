#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

static int xopen_read(const char *name)
{
	int fd = open(name, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", name);
		exit(98);
	}
	return (fd);
}

static int xopen_write_trunc(const char *name)
{
	int fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name);
		exit(99);
	}
	return (fd);
}

static void xclose(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

static void copy_stream(int fd_from, const char *from_name, const char *to_name)
{
	char buf[BUF_SIZE];
	ssize_t r, w, off;
	int fd_to;

	/* Probe read first so a read error exits 98 before touching destination */
	r = read(fd_from, buf, BUF_SIZE);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_name);
		exit(98);
	}

	fd_to = xopen_write_trunc(to_name);

	while (r > 0)
	{
		for (off = 0; off < r; off += w)
		{
			w = write(fd_to, buf + off, r - off);
			if (w == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to_name);
				xclose(fd_to);
				exit(99);
			}
		}
		r = read(fd_from, buf, BUF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_name);
			xclose(fd_to);
			exit(98);
		}
	}
	xclose(fd_to);
}

int main(int argc, char *argv[])
{
	int fd_from;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = xopen_read(argv[1]);
	copy_stream(fd_from, argv[1], argv[2]);
	xclose(fd_from);
	return (0);
}
