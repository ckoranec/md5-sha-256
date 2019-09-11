/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:29:52 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/21 21:06:11 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenget(t_varg *varg, intmax_t num, char *str)
{
	if (varg->d == 1 || varg->i == 1 || varg->u == 1)
		return (ft_intlen(num));
	else if (varg->c == 1)
		return (1);
	else if (varg->p == 1)
		return ((num == 0) ? 3 : ft_strlen(str + 2));
	else
		return (ft_strlen(str));
}

int	cheese(t_varg *varg, t_lenmod *lenmod, intmax_t num, char *str)
{
	int counter;
	int munster;

	counter = 0;
	lenmod->len = lenget(varg, num, str);
	munster = (lenmod->alen < 0) ? 0 : lenmod->alen;
	while (lenmod->len < (lenmod->blen - munster))
	{
		ft_putchar(' ');
		lenmod->len++;
	}
	num = (lenmod->space == 1) ? (num / 10) : num;
	while (counter < (lenmod->alen - ft_intlen(num)) && !varg->s)
	{
		ft_putchar('0');
		counter++;
		lenmod->len++;
	}
	return ((lenmod->space == 1) ? --counter : counter);
}
