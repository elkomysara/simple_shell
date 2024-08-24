#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "simple_shell.h"

/**
* display_prompt - Display the shell prompt
*/
void display_prompt(void)
{
printf("#cisfun$ ");
}

/**
* read_command - Read the command from standard input
*
* Return: The command line
*/
char *read_command(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

nread = getline(&line, &len, stdin);
if (nread == -1)
{
if (feof(stdin))
{
printf("\n");
free(line);
exit(0); /* Handle EOF (Ctrl+D) */
}
perror("getline");
free(line);
return (NULL);
}

/* Remove the newline character from the input */
line[strcspn(line, "\n")] = '\0';

return (line);
}

/**
* execute_command - Execute the command using execve
* @cmd: The command to execute
*/
void execute_command(char *cmd)
{
char *argv[2];

/* Skip empty input */
if (cmd[0] == '\0')
{
return;
}

argv[0] = cmd;
argv[1] = NULL;

/* Execute the command */
if (execve(argv[0], argv, environ) == -1)
{
perror(cmd);
}
}

/**
* main - Entry point for the simple shell
*
* Return: Always 0 (Success)
*/
int main(void)
{
char *cmd;

while (1)
{
display_prompt();
cmd = read_command();
if (cmd)
{
execute_command(cmd);
free(cmd);
}
}

return (0);
}
