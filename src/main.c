/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <jkertgat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:38:23 by jkertgat          #+#    #+#             */
/*   Updated: 2019/09/10 19:42:08 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

char		*hashstring(uint8_t *hash, uint32_t len)
{
	char	*hash_string;
	char	*s;
	int		i;

	hash_string = (char*)ft_memalloc(len * 2 * sizeof(char));
	s = hash_string;
	i = 0;
	while (i < (int)len)
	{
		sprintf(s, "%2.2x", hash[i]);
		s += 2;
		i++;
	}
	return (hash_string);
}

void		print_stdout(char **argv, t_ssl *ssl)
{
	uint8_t	*h;

	h = (ssl->hash_function)((uint8_t*)argv[ssl->args.s + 1],
		strlen(argv[ssl->args.s + 1]));
	if (ssl->args.q == 0)
	{
		if (ssl->args.r != 0)
			printf("%s \"%s\"\n", hashstring(h, ssl->hash_len),
				argv[ssl->args.s + 1]);
		else
			printf("%s (\"%s\") = %s\n", ssl->command_cap,
				argv[ssl->args.s + 1], hashstring(h, ssl->hash_len));
	}
	else
		printf("%s\n", hashstring(h, ssl->hash_len));
}

int			main(int argc, char **argv)
{
	t_ssl ssl;

	if (argc < 2)
	{
		printf("usage: ft_ssl command [command opts] [command args]\n");
		return (0);
	}
	ft_bzero(&ssl, sizeof(t_ssl));
	ft_bzero(&ssl.args, sizeof(t_args));
	ssl.hash_function = NULL;
	if (!(get_args(argc, argv, &ssl)))
		return (0);
	read_stdin(&ssl);
	if (ssl.args.s != 0)
		print_stdout(argv, &ssl);
	if (ssl.args.file != 0)
		hash_file(argc, argv, &ssl);
}
