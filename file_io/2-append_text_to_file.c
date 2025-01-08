#include "main.h"

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
