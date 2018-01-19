/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:48:47 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/22 18:56:18 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t						i;
	unsigned char				*mem;
	const unsigned char			*tmp;

	tmp = (unsigned char *)src;
	mem = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
		{
			mem[i] = tmp[i];
			i++;
			return (mem + i);
		}
		mem[i] = tmp[i];
		i++;
	}
	return (NULL);
}
