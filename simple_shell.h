#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
extern char **environ;

#endif
