/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:32:17 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:07:55 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_call(t_lenmod *lenmod, const char *s, int strpos, int i)
{
	parse4(lenmod, s, strpos, i);
	if (s[i] == '#')
		lenmod->pound = 1;
	else if (s[i] == ' ')
		lenmod->space = 1;
	parse5(s, lenmod, strpos, i);
	if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.')
		parse7(lenmod, s, i, strpos);
	return (lenmod->len);
}

int		parse_check(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	if (varg->check == 0)
	{
		lenmod->len += doer(varg, lenmod, ap);
		varg->check = 3;
		initialize(lenmod, varg);
	}
	return (lenmod->len);
}

int		parse8(t_varg *varg, t_lenmod *lenmod, const char *s, int i)
{
	if (varg->check == 3)
	{
		lenmod->len++;
		ft_putchar(s[i]);
	}
	return (lenmod->len);
}

void	parse_call_2(t_lenmod *lenmod, t_varg *varg, const char *s, int i)
{
	parse6(lenmod, varg, s, i);
	parse3(s, varg, i);
	parse2(s, lenmod, varg, i);
}

int		parse(va_list ap, t_varg *varg, t_lenmod *lenmod, const char *s)
{
	int		i;
	int		j;
	int		strpos;

	i = 0;
	while (s[i])
	{
		strpos = 0;
		j = 0;
		if (varg->check == 1)
		{
			parse_call_2(lenmod, varg, s, i);
			parse_call(lenmod, s, strpos, i);
		}
		else if (s[i] == '%')
			varg->check = 1;
		else if (varg->check == 3)
		{
			lenmod->len++;
			ft_putchar(s[i]);
		}
		parse_check(varg, lenmod, ap);
		i++;
	}
	return (lenmod->len);
}
