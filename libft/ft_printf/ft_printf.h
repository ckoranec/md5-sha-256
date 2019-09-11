/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 22:00:42 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/24 03:07:17 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft.h"

typedef struct	s_varg
{
	int			percent;
	int			check;
	int			c;
	int			d;
	int			s;
	int			i;
	int			o;
	int			p;
	int			u;
	int			x;
	int			bigx;
	int			bigc;
	int			bigs;
	int			bigd;
	int			bigo;
}				t_varg;

typedef	struct	s_lenmod
{
	int			alen;
	int			blen;
	int			minusnumber;
	int			zeronumber;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			pound;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			len;
}				t_lenmod;

void			intialize2(t_lenmod *lenmod, t_varg *varg);
void			initialize(t_lenmod *lenmod, t_varg *varg);
int				doer(t_varg *varg, t_lenmod *lenmod, va_list ap);
int				ft_conv_check(char *s, char c);
int				ft_printf(const char *str, ...);
int				print_d_i_also(t_lenmod *lenmod, intmax_t num, int j, int i);
int				print_d_i_four(t_lenmod *lenmod, t_varg *varg, intmax_t num);
int				print_d_i_space(t_lenmod *lenmod, int prec, intmax_t num);
int				print_d_i_pz(t_lenmod *lenmod, intmax_t num, int prec);
int				print_d_i(t_varg *varg, t_lenmod *lenmod, va_list ap, int i);
int				print_s_too(t_lenmod *lenmod, int prec, char *str, int i);
int				print_s(t_varg *varg, t_lenmod *lenmod, va_list ap);
int				print_o_x3(t_lenmod *lenmod, intmax_t num, int base);
int				print_o_x4(t_lenmod *lenmod, t_varg *varg, intmax_t num, int i);
void			print_o_x5(t_lenmod *lenmod, intmax_t num, int i);
int				print_o_x(t_varg *varg, t_lenmod *lenmod, va_list ap);
int				print_c_too(t_lenmod *lenmod, char c);
int				print_c(t_varg *varg, t_lenmod *lenmod, va_list ap);
int				print_p(va_list ap);
int				print_bigd(va_list ap);
int				print_u_too(t_lenmod *lenmod, intmax_t num);
int				print_u(t_varg *varg, t_lenmod *lenmod, va_list ap);
int				print_bigs(va_list ap);
int				print_d_i_too(t_lenmod *lenmod, intmax_t num, va_list ap);
int				print_d_i_plus(intmax_t num, t_lenmod *lenmod);
char			*supper(char *s);
void			ft_lontint2(long long n);
int				putwstr(wchar_t *str);
char			*ft_ultoa_base(unsigned long long nbr, unsigned int base);
int				print_d_i_minus_too(int i, int prec, t_lenmod *lenmod,
													intmax_t num);
int				print_d_i_minus(t_lenmod *lenmod, int prec, intmax_t num);
int				lenget(t_varg *varg, intmax_t num, char *str);
int				cheese(t_varg *varg, t_lenmod *lenmod, intmax_t num, char *str);
void			parse5_2(t_lenmod *lenmod, int i, const char *s, int strpos);
void			parse5(const char *s, t_lenmod *lenmod, int strpos, int i);
void			parse6(t_lenmod *lenmod, t_varg *varg, const char *s, int i);
void			parse7(t_lenmod *lenmod, const char *s, int i, int strpos);
int				parse2(const char *s, t_lenmod *lenmod, t_varg *varg, int i);
void			parse3b(const char *s, t_varg *varg, int i);
void			parse3(const char *s, t_varg *varg, int i);
void			parse4(t_lenmod *lenmod, const char *s, int strpos, int i);
int				parse_call(t_lenmod *lenmod, const char *s, int strpos, int i);
int				parse_check(t_varg *varg, t_lenmod *lenmod, va_list ap);
int				parse8(t_varg *varg, t_lenmod *lenmod, const char *s, int i);
void			parse_call_2(t_lenmod *lenmod, t_varg *varg, const char *s,
													int i);
int				parse(va_list ap, t_varg *varg, t_lenmod *lenmod,
													const char *s);
#endif
