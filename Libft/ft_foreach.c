/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:21:12 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/24 13:22:22 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int		i;

	i = 0;
	while (i < lenght)
	{
		f(tab[i]);
		++i;
	}
}
