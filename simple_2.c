#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * main - Entry point
 * Description: Handle argmuments
 * Return: 0 if not found
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];
	char *token;

	while (1)
	{
		printf("Shell > ");
		fgets(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

		token = strtok(command, " ");
		int i = 0;

		while (token != NULL && i < MAX_ARGUMENTS - 1)
		{
			arguments[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		arguments[i] = NULL;
		pid_t pid = fork();

		if (pid < 0)
		{
			fprintf(stderr, "Fork failed.\n");
			return (1);
		}
		else if (pid == 0)
		{
			execvp(arguments[0], arguments);
			fprintf(stderr, "Failed to execute command.\n");
			return (1);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
