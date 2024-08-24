#include "shell.h"

/**
* main - entry point for simple_shell
* @ac: arg count
* @av: arg vector
*
* Return: 0 on success, 1 on error
*/
int main(int ac, char **av)
{
info_t info = {0};

if (ac == 2)
{
int fd = open(av[1], O_RDONLY);
if (fd == -1)
{
perror(av[0]);
exit(127);
}
info.readfd = fd;
}

hsh(&info);
return (EXIT_SUCCESS);
}
