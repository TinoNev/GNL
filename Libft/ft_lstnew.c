/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:22:15 by lchaillo          #+#    #+#             */
/*   Updated: 2017/11/23 12:11:47 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*n_elem;

	if (!(n_elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		n_elem->content = NULL;
		n_elem->content_size = 0;
	}
	else
	{
		if (!(n_elem->content = malloc(sizeof(n_elem->content) * content_size)))
		{
			free(n_elem->content);
			return (NULL);
		}
		n_elem->content = ft_memcpy(n_elem->content, content, content_size);
		n_elem->content_size = content_size;
	}
	n_elem->next = NULL;
	return (n_elem);
}
