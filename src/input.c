/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <jkertgat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:48:43 by jkertgat          #+#    #+#             */
/*   Updated: 2019/09/10 19:55:07 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	open_file(FILE *fp, int fi, char **argv, t_ssl *ssl)
{
	uint32_t	length;
	char		*buffer;
	uint8_t		*h;

	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buffer = malloc(length);
	if (buffer)
		fread(buffer, 1, length, fp);
	h = (ssl->hash_function)((uint8_t*)buffer, strlen(buffer));
	if (ssl->args.q == 0)
	{
		if (ssl->args.r != 0)
			ft_printf("%s %s\n", hashstring(h, ssl->hash_len), argv[fi]);
		else
			ft_printf("%s (%s) = %s\n", ssl->command_cap, argv[fi],
				hashstring(h, ssl->hash_len));
	}
	else
		ft_printf("%s\n", hashstring(h, ssl->hash_len));
	fclose(fp);
}

void	hash_file(int argc, char **argv, t_ssl *ssl)
{
	int		fi;
	FILE	*fp;

	fi = ssl->args.file;
	while (fi < argc)
	{
		fp = fopen(argv[fi], "r");
		if (fp)
			open_file(fp, fi, argv, ssl);
		else
			ft_printf("ft_ssl: %s: %s: No such file or directory\n",
				ssl->command, argv[fi]);
		fi++;
	}
}

void	read_stdin(t_ssl *ssl)
{
	fd_set			readfds;
	struct timeval	timeout;
	uint8_t			*h;
	char			buf[BUFSIZ];

	FD_ZERO(&readfds);
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	FD_SET(STDIN_FILENO, &readfds);
	if (select(1, &readfds, NULL, NULL, &timeout) &&
		(ssl->args.p != 0 || ssl->args.file == 0))
	{
		fgets(buf, BUFSIZ, stdin);
		h = (ssl->hash_function)((uint8_t*)buf, strlen(buf));
		if (ssl->args.p != 0)
			ft_printf("%s", buf);
		ft_printf("%s\n", hashstring(h, ssl->hash_len));
	}
}
