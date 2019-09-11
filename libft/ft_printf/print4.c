/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 01:32:43 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:10:16 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_u_too(t_lenmod *lenmod, intmax_t num)
{
	int		i;
	char	*str;

	if (lenmod->zero == 1)
	{
		i = ft_intlen(num);
		while (i < lenmod->zeronumber)
		{
			ft_putnbr(0);
			i++;
		}
	}
	ft_putstr(str = ft_ultoa_base(num, 10));
	free(str);
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);
		while (i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (0);
}

int		print_u(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	intmax_t	num;
	int			ret;
	char		*str;

	if (lenmod->l == 1 || lenmod->ll == 1)
		num = (lenmod->l == 1) ? (unsigned long)va_arg(ap, intmax_t)
			: (unsigned long long)va_arg(ap, intmax_t);
	else if (lenmod->h == 1)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if (lenmod->z == 1)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (unsigned int)va_arg(ap, int);
	str = ft_ultoa_base(num, 10);
	ret = ft_strlen(str);
	if (lenmod->blen < 0 || lenmod->alen < 0)
		cheese(varg, lenmod, num, NULL);
	if (lenmod->plus == 1 && num > 0)
		ft_putchar('+');
	else
		print_u_too(lenmod, num);
	free(str);
	return (((lenmod->plus == 1 && num > 0) ? 1 : 0) + ret);
}

int		print_bigs(va_list ap)
{
	int		i;
	wchar_t	*s;

	i = 0;
	s = va_arg(ap, wchar_t *);
	putwstr(s);
	while (s[i])
		i++;
	return (i);
}

int		print_d_i_too(t_lenmod *lenmod, intmax_t num, va_list ap)
{
	if (lenmod->l == 1 || lenmod->ll == 1)
	{
		if (lenmod->l == 1)
			num = (long)va_arg(ap, intmax_t);
		else
			num = (long long)va_arg(ap, intmax_t);
	}
	else if (lenmod->h == 1)
		num = (char)va_arg(ap, int);
	else if (lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if (lenmod->z == 1)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (int)va_arg(ap, int);
	return (num);
}

int		print_d_i_plus(intmax_t num, t_lenmod *lenmod)
{
	int		i;
	char	*str;

	i = 0;
	if (num > 0)
		ft_putchar('+');
	else
		ft_putchar('-');
	if (lenmod->zero == 1)
	{
		i = 0;
		while (i < lenmod->blen - ft_intlen(num) - 1)
		{
			ft_putchar('0');
			i++;
		}
	}
	str = ft_itoa_base((num > 0) ? num : -num, 10);
	ft_putstr(str);
	free(str);
	return (ft_intlen((num > 0) ? num : -num) + 1 + i);
}
