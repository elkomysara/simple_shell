#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* External declaration of environ */
extern char **environ;

/* Function prototypes */
void display_prompt(void);
char *read_command(void);
void execute_command(char *cmd);

#endif /* SIMPLE_SHELL_H */
