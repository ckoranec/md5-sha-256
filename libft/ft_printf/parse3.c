/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 01:31:47 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:08:56 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse5_2(t_lenmod *lenmod, int i, const char *s, int strpos)
{
	char	*str;
	int		j;

	str = ft_memalloc(40);
	lenmod->zero = 1;
	ft_bzero(&*str, ft_strlen(str));
	j = i + 1;
	while (ft_isdigit(s[j]))
	{
		str[strpos++] = s[j];
		j++;
	}
	lenmod->zeronumber = ft_atoi(str);
	free(str);
}

void	parse5(const char *s, t_lenmod *lenmod, int strpos, int i)
{
	int		j;
	char	*str;

	str = ft_memalloc(40);
	if (s[i] == '0')
	{
		parse5_2(lenmod, i, s, strpos);
	}
	else if (s[i] == '-')
	{
		lenmod->minus = 1;
		j = i + 1;
		while (ft_isdigit(s[j]))
		{
			str[strpos++] = s[j];
			j++;
		}
		lenmod->minusnumber = ft_atoi(str);
	}
	free(str);
}

void	parse6(t_lenmod *lenmod, t_varg *varg, const char *s, int i)
{
	if (s[i] == '+')
		lenmod->plus = 1;
	else if (s[i] == 'C')
	{
		varg->check = 0;
		varg->bigc = 1;
	}
	else if (s[i] == 'l' && s[i + 1] == 'l')
		lenmod->ll = 1;
	else if (s[i] == 'l')
		lenmod->l = 1;
	else if (s[i] == 'h' && s[i + 1] == 'h')
		lenmod->hh = 1;
	else if (s[i] == 'h')
		lenmod->h = 1;
	else if (s[i] == 'j')
		lenmod->j = 1;
	else if (s[i] == 'z')
		lenmod->z = 1;
	else if (s[i] == ' ' && lenmod->space != 1)
	{
		ft_putstr(" ");
		lenmod->space = 1;
	}
}

void	parse7(t_lenmod *lenmod, const char *s, int i, int strpos)
{
	char	*str;
	int		j;

	str = ft_memalloc(40);
	j = i;
	strpos = 0;
	while (ft_isdigit(s[j]))
	{
		str[strpos++] = s[j];
		j++;
	}
	lenmod->blen = ft_atoi(str);
	if (s[j] == '.')
	{
		strpos = 0;
		j++;
		while (ft_isdigit(s[j]))
		{
			str[strpos++] = s[j];
			j++;
		}
		lenmod->alen = ft_atoi(str);
		i = j - 1;
	}
	free(str);
}
