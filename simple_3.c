#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - entry point
 * Description: Handle path, fork must not be called if
 * command does not exist
 * Return: 0;
 */

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *dir;
	char *full_path = malloc(MAX_COMMAND_LENGTH * sizeof(char));

	if (!path)
		return (NULL);

	dir = strtok(path, ":");
	while (dir)
	{
		snprintf(full_path, MAX_COMMAND_LENGTH, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		dir = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}
int main(void)
{	char command[MAX_COMMAND_LENGTH];
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
		char *command_path = find_command(arguments[0]);

		if (command_path == NULL)
		{
			fprintf(stderr, "Command not found.\n");
			continue;
		}
		pid_t pid = fork();

		if (pid < 0)
		{
			fprintf(stderr, "Fork failed.\n");
			return (1);
		}
		else if (pid == 0)
		{
			execv(command_path, arguments);
			fprintf(stderr, "Failed to execute command.\n");
			return (1);
		}
		else
			wait(NULL);
		free(command_path);
	}
	return (0);
}
