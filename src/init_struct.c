/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <jkertgat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:42:37 by jkertgat          #+#    #+#             */
/*   Updated: 2019/09/10 19:46:22 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static int	init_ssl_struct(char **argv, t_ssl *ssl)
{
	if (ft_strcmp(argv[1], "md5") == 0)
	{
		ssl->hash_function = md5;
		ssl->command = "md5";
		ssl->command_cap = "MD5";
		ssl->hash_len = 16;
	}
	else if (ft_strcmp(argv[1], "sha256") == 0)
	{
		ssl->hash_function = sha256;
		ssl->command = "sha256";
		ssl->command_cap = "SHA256";
		ssl->hash_len = 32;
	}
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.", argv[1]);
		ft_printf("Standard commands:\n\n"
		"Message Digest commands:\n"
		"md5\n"
		"sha256\n\n"
		"Cipher commands:");
		return (0);
	}
	return (1);
}

int			get_args(int argc, char **argv, t_ssl *ssl)
{
	int		j;

	j = 2;
	while (j < argc)
	{
		if (ft_strcmp(argv[j], "-p") == 0)
			ssl->args.p = j;
		else if (ft_strcmp(argv[j], "-q") == 0)
			ssl->args.q = j;
		else if (ft_strcmp(argv[j], "-r") == 0)
			ssl->args.r = j;
		else if (ft_strcmp(argv[j], "-s") == 0)
		{
			ssl->args.s = j;
			j++;
		}
		else
			ssl->args.file = j;
		j++;
	}
	return (init_ssl_struct(argv, ssl));
}
