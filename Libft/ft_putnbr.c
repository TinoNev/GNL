/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:48:59 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/21 13:59:39 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < -9)
	{
		ft_putchar('-');
		ft_putnbr(n / 10 * -1);
		ft_putnbr(n % 10 * -1);
	}
	else if (n > -10 && n < 0)
	{
		ft_putchar('-');
		ft_putchar(n * -1 + '0');
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
