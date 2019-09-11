/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 22:36:19 by jkertgat          #+#    #+#             */
/*   Updated: 2018/03/15 15:49:05 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *tng;

	tng = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*tng == (unsigned char)c)
			return ((void *)tng);
		tng++;
	}
	return (NULL);
}
