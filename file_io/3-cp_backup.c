#include "main.h"

int main(int argc, char *argv[])
{
	int file_from, file_to;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	/* Step 1: Validate number of arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Step 2: Open file_from for reading */
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file NAME_OF_THE_FILE\n");
                exit(98);
	}

	/* Step 3: Open file_to for writing */
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(file_from);
		exit(99);
	}

	/* Step 4: Copy content from file_from to file_to */
	while ((bytes_read = read(file_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(file_from);
			close(file_to);
			exit(99);
		}
	}

	/* Step 5: Handle read errors */
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(file_from);
		close(file_to);
		exit(98);
	}

	/* Step 6: Close file descriptors */
	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}


        if (close(file_to) == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
                exit(100);
        }

	return (0);
}
