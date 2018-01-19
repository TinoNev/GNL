/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:06:27 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/24 13:53:05 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbword(char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (!(s))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				++i;
			++len;
		}
		++i;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dest;
	size_t	len;
	int		i;
	int		x;

	i = 0;
	len = ft_nbword(s, c);
	if (!(dest = (char **)malloc(sizeof(char *) * len + 1)) || !(s))
		return (NULL);
	len = 0;
	while (s[i] == c)
		++i;
	while (s[i] != '\0')
	{
		x = i;
		while (s[i] != c && s[i] != '\0')
			++i;
		dest[len] = ft_strsub(s, x, (i - x));
		++len;
		while (s[i] == c)
			++i;
	}
	dest[len] = NULL;
	return (dest);
}
