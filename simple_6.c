#include <stdio.h>
#include <stdlib.h>
/**
 * custom_getline - check description
 * Description: own version of getline
 * @lineptr: pointer to the line
 * @n: number of characters
 * @stream: stream
 * Return: error or number of bytes read
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 0;
	ssize_t bytes_read = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	while (c == fgetc(stream) != EOF)
	{
		if (bufsize <= *n)
		{
			bufsize = (*n) + 1;
			char *new_lineptr = realloc(*lineptr, bufsize);

			if (new_lineptr == NULL)
				return (-1);
			*lineptr = new_lineptr;
			*n = bufsize;
		}
		(*lineptr)[bytes_read++] = (char)c;
		if (c == '\n')
			break;
	}
	if (bytes_read == 0)
		return (-1);
	(*lineptr)[bytes_read] = '\0';
	return (bytes_read);
}

/**
 * main - entry point
 * Description: getline function
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	FILE *stream = fopen("input.txt", "r");

	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while (nread = custom_getline(&line, &len, stream) != -1)
	{
		printf("Retrieved line of length %zu: \n", nread);
		printf("%s", line);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
	return (0);
}
