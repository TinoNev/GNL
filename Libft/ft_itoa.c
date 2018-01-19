/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:56:57 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/21 12:03:08 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*ft_itoaneg(int n)
{
	char	*dest;
	size_t	len;
	int		nb;
	int		i;

	nb = n;
	len = 2;
	while (nb < -9)
	{
		nb = nb / 10;
		++len;
	}
	if (!(dest = ft_strnew(len)))
		return (NULL);
	i = len - 1;
	dest[i] = (n % 10 * -1) + '0';
	nb = n / 10 * -1;
	while (i > 0)
	{
		--i;
		dest[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	dest[0] = '-';
	return (dest);
}

char			*ft_itoa(int n)
{
	char	*dest;
	size_t	len;
	int		nb;
	int		i;

	len = 1;
	nb = n;
	if (n < 0)
		return (dest = ft_itoaneg(n));
	while (nb > 9)
	{
		nb = nb / 10;
		++len;
	}
	nb = n;
	i = len - 1;
	if (!(dest = ft_strnew(len)))
		return (NULL);
	while (i >= 0)
	{
		dest[i] = (nb % 10) + '0';
		--i;
		nb = nb / 10;
	}
	return (dest);
}
