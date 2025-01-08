#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL-terminated string to add at the end of the file.
 *
 * Description: This function appends the string `text_content` to the
 *              end of the file specified by `filename`. If `text_content`
 *              is NULL, no data is appended. The file is not created if
 *              it does not exist. If the file exists, it appends the content
 *              without modifying the existing data.
 *
 * Return: 1 on success, -1 on failure (e.g., if the file does not exist,
 *         cannot be opened, or writing fails).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;

	/* Step 1: Validate input */
	if (filename == NULL)
		return (-1);

	/* Step 2: Open the file */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* Step 3: Write content to the file (if not NULL) */
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
	if (fd == -1)
		return (-1);


	return (1);

}
