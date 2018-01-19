/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:36:59 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/22 11:30:16 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dest);
	if (src[0] == '\0')
		return (ft_strcat(dest, src));
	while (i < n && src[i] != '\0')
	{
		dest[j] = src[i];
		++j;
		++i;
	}
	dest[j] = '\0';
	return (dest);
}
