/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 20:20:12 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/23 22:13:14 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*supper(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

void	ft_lontint2(long long n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_lontint2(-n);
	}
	else if (n > 9)
	{
		ft_lontint2(n / 10);
		ft_lontint2(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int		putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

char	*ft_ultoa_base(unsigned long long nbr, unsigned int base)
{
	int					length;
	unsigned long long	sign;
	char				*str;
	char				*ptr;

	ptr = "0123456789abcdef";
	sign = (unsigned long long)nbr;
	str = ft_strnew(60);
	if (!str)
		return (NULL);
	length = 0;
	str[length++] = ptr[sign % base];
	while (sign /= base)
		str[length++] = ptr[sign % base];
	str[length] = '\0';
	ft_strrev(str);
	return (str);
}
