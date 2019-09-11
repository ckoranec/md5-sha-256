/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 01:33:04 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:10:30 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d_i_minus_too(int i, int prec, t_lenmod *lenmod, intmax_t num)
{
	prec = 0;
	while (prec < (lenmod->alen - ft_intlen(num)))
	{
		ft_putnbr(0);
		prec++;
		i++;
	}
	return (i);
}

int		print_d_i_minus(t_lenmod *lenmod, int prec, intmax_t num)
{
	int i;

	i = 0;
	if (lenmod->alen)
	{
		if (lenmod->blen > lenmod->alen)
		{
			prec = lenmod->alen;
			while (prec < lenmod->blen)
			{
				ft_putchar(' ');
				prec++;
				i++;
			}
		}
		i = print_d_i_minus_too(i, prec, lenmod, num);
	}
	else
	{
		while (i++ < (lenmod->blen - ft_intlen(num)))
			ft_putchar('0');
	}
	ft_lontint2(num);
	return (i + ft_intlen(num));
}
