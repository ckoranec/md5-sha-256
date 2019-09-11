/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:01:22 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:11:24 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		get_len(long long n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 3;
	else
		i = 2;
	while ((n = n / base))
		i++;
	i--;
	return (i);
}

static char		*get_str(long long n, int base)
{
	int		k;
	char	*str;
	char	checkbase[16];
	int		check;

	check = 1;
	ft_strcpy(checkbase, "0123456789abcdef");
	k = get_len(n, base);
	str = (char*)malloc(200);
	if (n < 0)
		check = -1;
	str[k--] = '\0';
	while (n)
	{
		str[k--] = checkbase[check * (n % base)];
		n = n / base;
	}
	if (check == -1)
		str[k--] = '-';
	free(str);
	return (str);
}

char			*ft_itoa_base(long long nbr, unsigned int base)
{
	char	*str;

	if (nbr == 0)
		return ("0");
	str = get_str(nbr, base);
	return (str);
}
