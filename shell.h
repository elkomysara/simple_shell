#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

/**
* struct passinfo - contains pseudo-arguments to pass into a function,
* allowing uniform prototype for function pointer struct
* @argv: an array of strings generated from the input
* @readfd: the fd from which to read line input
* @status: the return status of the last exec'd command
*/
typedef struct passinfo
{
    char **argv;
    int readfd;
    int status;
} info_t;

/* Function prototypes */
int hsh(info_t *);

#endif /* _SHELL_H_ */
