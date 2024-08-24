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
if (isatty(STDIN_FILENO)) /* Display prompt only in interactive mode */
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
* @argv0: The name of the shell program (argv[0])
* @line_number: The current line number for the command
*/
void execute_command(char *cmd, char *argv0, int line_number)
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
fprintf(stderr, "%s: %d: %s: not found\n", argv0, line_number, cmd);
}
}

/**
* main - Entry point for the simple shell
*
* @argc: Argument count
* @argv: Argument vector
*
* Return: Always 0 (Success)
*/
int main(int argc, char **argv)
{
char *cmd;
int line_number;

(void)argc; /* Suppress unused parameter warning */

line_number = 0;

while (1)
{
line_number++;
display_prompt();
cmd = read_command();
if (cmd)
{
execute_command(cmd, argv[0], line_number);
free(cmd);
}
}

return (0);
}
