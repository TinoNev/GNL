/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:08:18 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/24 13:17:13 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revercase(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = ft_strdup(s)))
		return (NULL);
	while (dest[i] != '\0')
	{
		if (ft_toupper(dest[i]) == s[i])
			dest[i] = ft_tolower(s[i]);
		else
			dest[i] = ft_toupper(s[i]);
		++i;
	}
	return (dest);
}
