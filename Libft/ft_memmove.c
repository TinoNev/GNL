/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:12:40 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/22 15:05:38 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*mem;
	const char	*tmp;
	size_t		i;

	i = 0;
	mem = dest;
	tmp = src;
	if (tmp > mem)
	{
		while (i < n)
		{
			mem[i] = tmp[i];
			++i;
		}
	}
	else if (tmp < mem)
	{
		while (n-- > 0)
			mem[n] = tmp[n];
	}
	return (mem);
}
