#ifndef SSL_H
# define SSL_H

# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
typedef struct s_ssl    t_ssl;
typedef struct s_args   t_args;

struct s_args
{
    int p;
    int q;
    int r;
    int s;
    int file;
};

struct s_ssl
{
    t_args      args;
    uint8_t     *(*hash_function)(uint8_t*, size_t);
    char        *command;
    char        *command_cap;
    uint32_t    hash_len;
};

int     get_args(int argc, char **argv, t_ssl *ssl);
void    hash_file(int argc, char **argv, t_ssl *ssl);
void	read_stdin(t_ssl *ssl);
char    *hashstring(uint8_t* hash, uint32_t len);

uint8_t *md5(uint8_t *msg, size_t len);
uint8_t *sha256(uint8_t *msg, size_t len);

#endif