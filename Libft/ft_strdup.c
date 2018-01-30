/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:35:02 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/30 14:16:22 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	else if (s == 0)
		return (NULL);
	else
	{
		while (s[i] != '\0')
		{
			dest[i] = s[i];
			++i;
		}
		dest[i] = '\0';
		return (dest);
	}
}
