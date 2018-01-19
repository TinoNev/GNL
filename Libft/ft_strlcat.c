/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:37:11 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/22 15:06:20 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	j = ft_strlen(dest);
	i = 0;
	if (j > size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && (i + j + 1) < size)
	{
		dest[j + i] = src[i];
		++i;
	}
	dest[j + i] = '\0';
	i = ft_strlen(src);
	return (j + i);
}
