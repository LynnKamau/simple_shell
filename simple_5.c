#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_LENGTH 100

/**
 * main - entry point
 * Description: Prints current environ
 * @ac: argc
 * @av: argv
 * @env: current environment
 * Return: 0;
 */

int main(int ac, char **av, char **env)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("Shell > ");
		fgets(input, MAX_INPUT_LENGTH, stdin);
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "env") == 0)
		{
			unsigned int i = 0;

			while (env[i] != NULL)
			{
				printf("%s\n", env[i]);
				i++;
			}
		}
	}
	return (0);
}
