/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <jkertgat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:55:35 by jkertgat          #+#    #+#             */
/*   Updated: 2019/09/10 20:32:48 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

#define RT(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

const uint32_t	g_r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
	12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
	15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

const uint32_t	g_k[] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af,
	0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453,
	0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681,
	0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5,
	0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0,
	0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

void		inner_loop(uint32_t **abcd, uint32_t *w)
{
	uint32_t	i;
	uint32_t	fg[2];
	uint32_t	temp;

	i = 0;
	while (i < 64)
	{
		if (i < 16)
		{
			fg[0] = ((*abcd)[1] & (*abcd)[2]) | ((~(*abcd)[1]) & (*abcd)[3]);
			fg[1] = i;
		}
		else if (i < 32)
		{
			fg[0] = ((*abcd)[3] & (*abcd)[1]) | ((~(*abcd)[3]) & (*abcd)[2]);
			fg[1] = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			fg[0] = (*abcd)[1] ^ (*abcd)[2] ^ (*abcd)[3];
			fg[1] = (3 * i + 5) % 16;
		}
		else
		{
			fg[0] = (*abcd)[2] ^ ((*abcd)[1] | (~(*abcd)[3]));
			fg[1] = (7 * i) % 16;
		}
		temp = (*abcd)[3];
		(*abcd)[3] = (*abcd)[2];
		(*abcd)[2] = (*abcd)[1];
		(*abcd)[1] = (*abcd)[1] + RT(((*abcd)[0] + fg[0] +
			g_k[i] + w[fg[1]]), g_r[i]);
		(*abcd)[0] = temp;
		i++;
	}
}

void		outer_loop(uint8_t *data, uint32_t *h, int new_len)
{
	int			j;
	uint32_t	*w;
	uint32_t	abcd[4];
	uint32_t	*abcd_ptr;

	abcd_ptr = abcd;
	j = 0;
	while (j < new_len)
	{
		w = (uint32_t*)(data + j);
		abcd[0] = h[0];
		abcd[1] = h[1];
		abcd[2] = h[2];
		abcd[3] = h[3];
		inner_loop(&abcd_ptr, w);
		h[0] += abcd[0];
		h[1] += abcd[1];
		h[2] += abcd[2];
		h[3] += abcd[3];
		j += (512 / 8);
	}
}

uint8_t		*md5(uint8_t *msg, size_t len)
{
	uint32_t	*h;
	int			new_len;
	uint8_t		*data;
	uint32_t	bits_len;

	h = (uint32_t*)malloc(4 * sizeof(uint32_t));
	h[0] = 0x67452301;
	h[1] = 0xefcdab89;
	h[2] = 0x98badcfe;
	h[3] = 0x10325476;
	new_len = ((((len + 8) / 64) + 1) * 64) - 8;
	data = (uint8_t*)calloc(new_len + 64, 1);
	ft_memcpy(data, msg, len);
	data[len] = 128;
	bits_len = 8 * len;
	ft_memcpy(data + new_len, &bits_len, 4);
	outer_loop(data, h, new_len);
	free(data);
	return (uint8_t*)h;
}
