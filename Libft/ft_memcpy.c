/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:48:33 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/16 15:43:21 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*mem;
	const char	*tmp;

	mem = dest;
	tmp = src;
	i = 0;
	while (i < n)
	{
		mem[i] = tmp[i];
		++i;
	}
	return (mem);
}
