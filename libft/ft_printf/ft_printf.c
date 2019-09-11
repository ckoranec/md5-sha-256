/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:47:27 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/22 18:04:07 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	intialize2(t_lenmod *lenmod, t_varg *varg)
{
	lenmod->alen = 0;
	lenmod->blen = 0;
	varg->percent = 0;
	varg->check = 3;
	varg->c = 0;
	varg->s = 0;
	varg->d = 0;
	varg->bigs = 0;
	varg->bigd = 0;
	varg->i = 0;
	varg->o = 0;
}

void	initialize(t_lenmod *lenmod, t_varg *varg)
{
	varg->bigo = 0;
	varg->u = 0;
	varg->x = 0;
	varg->bigx = 0;
	varg->bigc = 0;
	lenmod->h = 0;
	lenmod->hh = 0;
	lenmod->l = 0;
	lenmod->ll = 0;
	lenmod->j = 0;
	lenmod->z = 0;
	lenmod->pound = 0;
	lenmod->zero = 0;
	lenmod->minus = 0;
	lenmod->plus = 0;
	lenmod->zeronumber = 0;
	lenmod->space = 0;
	lenmod->len = 0;
	intialize2(lenmod, varg);
}

int		doer(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	if (varg->s == 1 && lenmod->l == 0)
		return (print_s(varg, lenmod, ap));
	else if (varg->d == 1 || varg->i == 1)
		return (print_d_i(varg, lenmod, ap, 0));
	else if (varg->c == 1 || varg->bigc == 1)
		return (print_c(varg, lenmod, ap));
	else if (varg->o == 1 || varg->x == 1 || varg->bigx == 1 || varg->bigo == 1)
		return (print_o_x(varg, lenmod, ap));
	else if (varg->u == 1)
		return (print_u(varg, lenmod, ap));
	else if (varg->bigs == 1 || (varg->s && lenmod->l == 1))
		return (print_bigs(ap));
	else if (varg->bigd == 1)
		return (print_bigd(ap));
	else if (varg->p == 1)
		return (print_p(ap));
	else
		return (1);
}

int		ft_conv_check(char *s, char c)
{
	int i;

	i = -1;
	while (s[++i])
		if (c == s[i])
			return (1);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_varg		varg;
	t_lenmod	lenmod;

	va_start(ap, str);
	initialize(&lenmod, &varg);
	return (parse(ap, &varg, &lenmod, str));
}
