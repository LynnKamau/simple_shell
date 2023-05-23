#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
/**
 * main - entry point
 * Description: Handle exit
 * Return: 0;
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("Shell > ");
		fgets(input, MAX_INPUT_LENGTH, stdin);
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
			exit(0);
	}
	return (0);
}
