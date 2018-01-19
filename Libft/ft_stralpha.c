/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:00:09 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/24 12:59:04 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_stralpha(const char *s)
{
	size_t		i;

	if (!(s))
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}
