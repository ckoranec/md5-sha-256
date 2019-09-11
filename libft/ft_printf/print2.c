/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 01:32:10 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:10:22 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s_too(t_lenmod *lenmod, int prec, char *str, int i)
{
	if (lenmod->minusnumber <= i)
	{
		ft_putstr(str);
		return (i);
	}
	else if (lenmod->minusnumber >= i)
	{
		if (i > lenmod->alen)
		{
			write(1, str, lenmod->alen);
			prec = lenmod->alen;
		}
		else
		{
			ft_putstr(str);
			prec = i;
		}
		while (prec < lenmod->minusnumber)
		{
			ft_putchar(' ');
			prec++;
		}
		return ((lenmod->blen));
	}
	return (0);
}

int		print_s(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	char	*str;
	int		i;
	wchar_t	*ptr;
	int		prec;

	prec = 0;
	str = va_arg(ap, char *);
	if (str == NULL || ft_strcmp(str, "") == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = ft_strlen(str);
	(lenmod->blen || lenmod->alen) ? prec = cheese(varg, lenmod, 0, str) : 0;
	if (lenmod->minus == 1)
		return (print_s_too(lenmod, prec, str, i));
	else if (lenmod->l == 1)
	{
		ptr = va_arg(ap, wchar_t *);
		return (putwstr(ptr));
	}
	else
		ft_putstr(str);
	return (ft_strlen(str) + prec);
}

int		print_o_x3(t_lenmod *lenmod, intmax_t num, int base)
{
	if (lenmod->plus == 1)
	{
		if (num > 0)
		{
			ft_putchar('+');
			return (ft_strlen(ft_itoa_base(num + 1, base)));
		}
	}
	return (0);
}

int		print_o_x4(t_lenmod *lenmod, t_varg *varg, intmax_t num, int i)
{
	if (lenmod->zero == 1)
	{
		i = ft_intlen(num);
		while (i++ < lenmod->zeronumber)
			ft_putnbr(0);
	}
	if (lenmod->pound == 1)
	{
		if (varg->x || varg->bigx)
		{
			ft_putstr("0X");
			lenmod->len = 2;
		}
		else
		{
			if (num != 0)
			{
				ft_putchar('0');
				lenmod->len = 1;
			}
		}
	}
	return (lenmod->len);
}

void	print_o_x5(t_lenmod *lenmod, intmax_t num, int i)
{
	i = 0;
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);
		while (i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
}
