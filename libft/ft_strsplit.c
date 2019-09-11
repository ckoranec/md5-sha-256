/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 00:08:13 by jkertgat          #+#    #+#             */
/*   Updated: 2018/07/31 04:17:37 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		h;
	int		i;
	int		j;
	char	**p;

	h = 0;
	i = -1;
	if (!s)
		return (NULL);
	if (!(p = (char **)ft_memalloc(sizeof(char *) * (ft_wordcnt(s, c)) + 1)))
		return (NULL);
	while (!(p[h] = NULL) && (++i) < (int)ft_strlen(s))
	{
		while ((s[i] == c && s[i]))
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (j < i)
		{
			p[h] = ft_strnew(i - j + 1);
			ft_strncpy(p[h++], (char *)s + j, (i - j));
		}
	}
	return (p);
}
