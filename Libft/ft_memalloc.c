/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:16:25 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/13 16:21:10 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	else
	{
		ft_bzero(dest, size);
		return (dest);
	}
}
