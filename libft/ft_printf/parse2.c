/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 01:31:32 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:08:27 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse2(const char *s, t_lenmod *lenmod, t_varg *varg, int i)
{
	if (s[i] == '#')
		lenmod->pound = 1;
	else if (s[i] == '%')
	{
		lenmod->len++;
		varg->percent = 1;
		varg->check = 3;
		ft_putchar('%');
	}
	else if (s[i] == 's')
	{
		varg->check = 0;
		varg->s = 1;
	}
	else if (s[i] == 'p')
	{
		varg->check = 0;
		varg->p = 1;
	}
	else if (s[i] == 'd')
	{
		varg->check = 0;
		varg->d = 1;
	}
	return (lenmod->len);
}

void	parse3b(const char *s, t_varg *varg, int i)
{
	if (s[i] == 'O')
	{
		varg->check = 0;
		varg->bigo = 1;
	}
	else if (s[i] == 'c')
	{
		varg->check = 0;
		varg->c = 1;
	}
	else if (s[i] == 'u')
	{
		varg->check = 0;
		varg->u = 1;
	}
	else if (s[i] == 'x')
	{
		varg->check = 0;
		varg->x = 1;
	}
}

void	parse3(const char *s, t_varg *varg, int i)
{
	if (s[i] == 'i')
	{
		varg->check = 0;
		varg->i = 1;
	}
	else if (s[i] == 'D')
	{
		varg->check = 0;
		varg->bigd = 1;
	}
	else if (s[i] == 'o')
	{
		varg->check = 0;
		varg->o = 1;
	}
	else if (s[i] == 'X')
	{
		varg->check = 0;
		varg->bigx = 1;
	}
	parse3b(s, varg, i);
}

void	parse4(t_lenmod *lenmod, const char *s, int strpos, int i)
{
	char	*str;
	int		j;

	str = ft_memalloc(40);
	if (s[i] == '#')
		lenmod->pound = 1;
	else if (s[i] == ' ')
	{
		lenmod->space = 1;
	}
	else if (s[i] == '0')
	{
		lenmod->zero = 1;
		ft_bzero(&*str, ft_strlen(str));
		j = i + 1;
		while (ft_isdigit(s[j]))
		{
			str[strpos++] = s[j];
			j++;
		}
		lenmod->zeronumber = ft_atoi(str);
	}
	free(str);
}
