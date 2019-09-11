/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 01:32:22 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:09:58 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_o_x(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	int			base;
	int			i;
	long long	num;

	num = 0;
	i = 0;
	if (varg->o == 1 || varg->bigo == 1)
		base = 8;
	else if (varg->x == 1 || varg->bigx == 1)
		base = 16;
	if (lenmod->h == 1)
		num = (char)va_arg(ap, int);
	else
		num = va_arg(ap, unsigned long long);
	if (lenmod->blen < 0 || lenmod->alen < 0)
		cheese(varg, lenmod, 0, ft_itoa_base(num, base));
	if (lenmod->plus == 1)
		return (print_o_x3(lenmod, num, base));
	print_o_x4(lenmod, varg, num, i);
	if (varg->bigo == 1 || varg->bigx == 1)
		ft_putstr(supper(ft_itoa_base(num, base)));
	else
		ft_putstr(ft_itoa_base(num, base));
	print_o_x5(lenmod, num, i);
	return (ft_strlen(ft_itoa_base(num, base)) + lenmod->len);
}

int		print_c_too(t_lenmod *lenmod, char c)
{
	int i;

	i = 1;
	if (lenmod->minusnumber <= 1)
	{
		ft_putchar(c);
		return (1);
	}
	else if (lenmod->minusnumber >= 1)
	{
		ft_putchar(c);
		while (i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
		return (i + 1);
	}
	return (0);
}

int		print_c(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	wchar_t	fatc;
	char	c;

	if (varg->bigc == 1)
	{
		fatc = va_arg(ap, wchar_t);
		ft_putchar(fatc);
		return (1);
	}
	c = va_arg(ap, int);
	if (c == '\0')
	{
		ft_putchar('\0');
		return (1);
	}
	if (lenmod->blen > 0 || lenmod->alen > 0)
		cheese(varg, lenmod, 0, NULL);
	if (lenmod->minus == 1)
		return (print_c_too(lenmod, c));
	else
		ft_putchar(c);
	return (1);
}

int		print_p(va_list ap)
{
	unsigned long long bacon;

	bacon = va_arg(ap, long long);
	ft_putchar('0');
	ft_putchar('x');
	if (bacon == 0)
	{
		ft_putchar('0');
		return (3);
	}
	else
		ft_putstr(ft_itoa_base(bacon, 16));
	return (ft_strlen(ft_itoa_base(bacon, 16)) + 2);
}

int		print_bigd(va_list ap)
{
	long long	num;
	char		*str;
	int			ret;

	num = va_arg(ap, long long);
	ft_longint(num);
	str = ft_itoa_base(num, 10);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
