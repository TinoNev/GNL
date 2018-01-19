/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:45:57 by lchaillo          #+#    #+#             */
/*   Updated: 2017/12/02 11:49:21 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_lst;
	t_list	*tmp;
	t_list	*n_elem;

	if (!(n_lst = (t_list *)malloc(sizeof(t_list))) || !(f) || !(lst))
		return (NULL);
	n_lst = f(lst);
	while (lst->next)
	{
		lst = lst->next;
		if (!(n_elem = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		n_elem = f(lst);
		tmp = n_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = n_elem;
		n_elem = n_elem->next;
//		free(n_elem);
	}
	return (n_lst);
}
