/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:44:51 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:09:40 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d_i_also(t_lenmod *lenmod, intmax_t num, int j, int i)
{
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);
		j = i;
		while (i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (0);
}

int		print_d_i_four(t_lenmod *lenmod, t_varg *varg, intmax_t num)
{
	int pr2;

	pr2 = 0;
	if ((lenmod->blen > 0 || lenmod->alen > 0)
		&& !lenmod->minus && !lenmod->zero)
	{
		if (lenmod->space == 1)
			pr2 = cheese(varg, lenmod, (num * 10), NULL);
		else
			pr2 = cheese(varg, lenmod, num, NULL);
	}
	return (pr2);
}

int		print_d_i_space(t_lenmod *lenmod, int prec, intmax_t num)
{
	if (lenmod->space == 1)
	{
		if (num > 0 && lenmod->plus != 1 && lenmod->alen > ft_intlen(num))
		{
			ft_putchar(' ');
			prec = 1;
		}
	}
	return (prec);
}

int		print_d_i_pz(t_lenmod *lenmod, intmax_t num, int prec)
{
	if (lenmod->plus == 1)
		return (print_d_i_plus(num, lenmod));
	if (lenmod->zero == 1)
		return (print_d_i_minus(lenmod, prec, num));
	return (0);
}

int		print_d_i(t_varg *varg, t_lenmod *lenmod, va_list ap, int i)
{
	intmax_t	num;
	int			j;
	int			prec;
	int			pr2;

	num = print_d_i_too(lenmod, 0, ap);
	prec = print_d_i_space(lenmod, 0, num);
	pr2 = print_d_i_four(lenmod, varg, num);
	if (lenmod->plus == 1 || lenmod->zero == 1)
		return (print_d_i_pz(lenmod, num, prec));
	ft_lontint2(num);
	j = i;
	i = print_d_i_also(lenmod, num, j, i);
	if (lenmod->zero)
		return (i + ft_intlen(num));
	else if (lenmod->blen || lenmod->alen)
	{
		if (lenmod->space == 1)
			return (ft_intlen(num * 10) + pr2 + 1);
		return (ft_intlen(num) + pr2 + (lenmod->space ? 1 : 0));
	}
	return (prec + ft_intlen(num) + (i - j) + ((lenmod->blen > lenmod->alen)
					? lenmod->blen - lenmod->alen : 0) - pr2);
}
