#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - entry point
 * Descriptiom: Creates a simple shell
 *
 * Return: Error if not found
 */

#define MAX_COMMAND_LENGTH 100

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t childPid;
	int status;

	while (1)
	{
	printf("Shell> ");
	fgets(command, sizeof(command), stdin);

	command[strcspn(command, "\n")] = '\0';
	childPid = fork();

	if (childPid == 0)
	{
		if (execve(command, NULL, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
		else if (childPid > 0)
			wait(&status);
	else
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	}

	return (0);
}
