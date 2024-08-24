
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* External declaration of environ */
extern char **environ;

/**
* main - Entry point for the simple shell
*
* Return: Always 0 (Success)
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
char *argv[2];

while (1)
{
/* Display the prompt */
printf("#cisfun$ ");

/* Read the input line */
nread = getline(&line, &len, stdin);
if (nread == -1)
{
if (feof(stdin))
{
/* Handle EOF (Ctrl+D) */
printf("\n");
break;
}
perror("getline");
continue;
}

/* Remove the newline character from the input */
line[strcspn(line, "\n")] = '\0';

/* Skip empty input */
if (line[0] == '\0')
{
continue;
}

/* Prepare the arguments for execve */
argv[0] = line;
argv[1] = NULL;

/* Execute the command */
if (execve(argv[0], argv, environ) == -1)
{
perror(argv[0]);  /* Display the command as part of the error */
}
}

/* Free the allocated memory */
free(line);
return (0);
}
