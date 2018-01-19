/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:51:12 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/21 12:16:36 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_space(const char *nptr)
{
	int		i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
			|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		++i;
	return (i);
}

int				ft_atoi(const char *nptr)
{
	int		i;
	int		s;
	int		nb;

	i = ft_space(nptr);
	nb = 0;
	s = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		s = i;
		++i;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		++i;
	}
	if (nptr[s] == '-')
		return (nb * -1);
	else
		return (nb);
}
