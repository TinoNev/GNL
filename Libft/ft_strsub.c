/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:09:15 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/22 15:20:43 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	int				i;
	unsigned int	x;

	i = 0;
	x = start + len;
	if (!(dest = ft_strnew(len)) || !(s))
		return (NULL);
	while (start < x && s[start] != '\0')
	{
		dest[i] = s[start];
		++i;
		++start;
	}
	dest[i] = '\0';
	return (dest);
}
