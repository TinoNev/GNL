/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:42:26 by lchaillo          #+#    #+#             */
/*   Updated: 2018/02/15 15:31:09 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_linecopy(char *save, char **line)
{
	int		i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	*line = ft_strsub(save, 0, i);
}

static char	*ft_savesplit(char *save)
{
	char	*tmp;
	int		len;
	int		i;
	char	*ptr;

	tmp = NULL;
	tmp = ft_strdup(save);
	len = ft_strlen(tmp);
	i = 0;
	ptr = save;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	save = ft_strsub(tmp, i, len - i);
	ft_strdel(&tmp);
	ft_strdel(&ptr);
	return (save);
}

static char	*ft_read_save(char *save, const int fd)
{
	int		i;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*ptr;

	save == NULL ? ret = read(fd, buff, BUFF_SIZE) : 0;
	save == NULL ? buff[ret] = '\0' : 0;
	save == NULL ? save = ft_strdup(buff) : 0;
	i = 0;
	while (save[i] != '\n' && ret != 0)
	{
		if (save[i] == '\0')
		{
			ret = read(fd, buff, BUFF_SIZE);
			buff[ret] = '\0';
			ptr = save;
			save = ft_strjoin(save, buff);
			ft_strdel(&ptr);
			i = -1;
		}
		i++;
	}
	return (save);
}

int		get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	static t_list	*list = NULL;
	t_list			*n_elem;
	t_gnl			*gnl;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	list = ft_lstnew(gnl, sizeof(t_gnl));
	n_elem = list;
	((t_gnl *)n_elem->content)->fd = fd;
	((t_gnl *)n_elem->content)->save = ft_read_save(
		((t_gnl *)n_elem ->content)->save, fd);
	ft_lstadd(&list, n_elem);
	if (((t_gnl *)list->content)->save[0] == '\0')
		return (0);
	ft_linecopy(((t_gnl *)list->content)->save, line);
	((t_gnl *)list->content)->save = ft_savesplit((
			(t_gnl *)list->content)->save);
	return (1);
}
