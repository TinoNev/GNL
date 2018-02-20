/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:07:36 by lchaillo          #+#    #+#             */
/*   Updated: 2018/02/15 16:20:54 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_checkfd(t_gnl **lst, int fd)
{
	t_gnl	*tmp;

	tmp = NULL;
	while (*lst  && (*lst)->fd != fd)
	{
		tmp = *lst;
		*lst = (*lst)->next;
	}
	if (!(*lst))
	{
		if (!(*lst = (t_gnl *)malloc(sizeof(t_gnl))))
			return (0);
		(*lst)->save = ft_strdup("\0");
		(*lst)->next = NULL;
		(*lst)->fd = fd;
		if (tmp)
			tmp->next = *lst;;
	}
	return (1);
}

static int	ft_checkline(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

static int	ft_save(t_gnl **lst, char *buf)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	len = ((*lst)->save ? ft_strlen((*lst)->save) : 0);
	if (!(tmp = (char *)malloc(sizeof(char) * len + ft_strlen(buf) + 1)))
		return (0);
	i = 0;
	while ((*lst)->save && (*lst)->save[i])
	{
		tmp[i] = (*lst)->save[i];
		i++;
	}
	j = 0;
	while (buf[j])
		tmp[i++] = buf[j++];
	tmp[i] = '\0';
	free((*lst)->save);
	(*lst)->save = tmp;
	return (1);
}

static void	ft_copy_and_save(t_gnl **lst, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*lst)->save[i] && (*lst)->save[i] != '\n')
		i++;
	*line = ft_strsub((*lst)->save, 0, i);
	i += ((*lst)->save[i] && (*lst)->save[i] == '\n' ? 1 : 0);
	if ((*lst)->save[i])
		tmp = ft_strsub((*lst)->save, i, ft_strlen((*lst)->save));
	else
		tmp = ft_strdup("\0");
	free((*lst)->save);
	(*lst)->save = tmp;
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*lst = NULL;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	t_gnl			*slst;

	slst = lst;
	ret = 0;
	if (fd < 0 || !(line) || read(fd, buf, 0) < 0)
		return (-1);
	ft_checkfd(&lst, fd);
	while (ft_checkline(lst->save)== 0 && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_save(&lst, buf);
	}
	if (lst->save[0])
	{
		ft_copy_and_save(&lst, line);
		lst = slst ? slst : lst;
		return (1);
	}
	lst = slst ? slst : lst;
	return (ret ? 1 : 0);
}
