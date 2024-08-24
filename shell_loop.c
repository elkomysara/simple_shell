#include "shell.h"

/**
* hsh - main shell loop
* @info: the parameter struct
*
* Return: 0 on success, 1 on error, or error code
*/
int hsh(info_t *info)
{
ssize_t r = 0;
char *line = NULL;
size_t len = 0;

while (1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);

r = getline(&line, &len, stdin);
if (r == -1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
break;
}

line[r - 1] = '\0'; /* Remove newline character */
info->argv = malloc(2 * sizeof(char *));
info->argv[0] = line;
info->argv[1] = NULL;

if (fork() == 0)
{
execve(info->argv[0], info->argv, environ);
perror(info->argv[0]);
exit(1);
}
else
{
wait(&(info->status));
}
free(info->argv);
}
free(line);
return (0);
}
