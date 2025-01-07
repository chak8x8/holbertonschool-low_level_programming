#include "main.h"

/**
 * create_file - Creates a file with specified content and permissions.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Description: If the file already exists, it is truncated. If
 *              text_content is NULL, an empty file is created.
 *              The file is created with permissions rw------- (0600).
 *
 * Return: 1 on success, -1 on failure (e.g., if filename is NULL,
 *         the file cannot be created, or write fails).
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;

	/* Step 1: Validate input */
	if (filename == NULL)
		return (0);

	/* Step 2: Open the file */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (0);

	/* Step 3: Write content to the file (if any) */
	if (text_content != NULL)
	{
		bytes_written = write(fd, text_content, strlen(text_content));
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	/* Step 4: Close the file */
	close(fd);
	return (1);
}
