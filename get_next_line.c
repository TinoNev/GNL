/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:06:37 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/24 12:30:52 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_and_save(const int fd, char *tmp)
{
	int		i;
	int		ret;
	char	buf[BUF_SIZE + 1];

	i = 0;
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	while (buf[i] != '\n' && ret != 0)
	{
		if (buf[i] == '\0')
		{
			tmp != 0 ? tmp = ft_strjoin(tmp, buf) : 0;
			tmp == 0 ? tmp = ft_strdup(buf) : 0;
			ret = read(fd, buf, BUF_SIZE);
			buf[ret] = '\0';
			i = -1;
		}
		i++;
	}
	tmp != 0 ? tmp = ft_strjoin(tmp, buf) : 0;
	tmp == 0 ? tmp = ft_strdup(buf) : 0;
	return (tmp);
}

static char	*ft_linecopy(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	line = ft_strnew(i);
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	return (line);
}

static char	*ft_savecpy(char *save, char *tmp)
{
	int	i;
	int y;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	y = 0;
	save = ft_strnew(ft_strlen(tmp) - i);
	i++;
	while (tmp[i] != '\0')
	{
		save[y] = tmp[i];
		y++;
		i++;
	}
	return (save);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	char		*tmp;
	static char	*save = NULL;

	if (fd < 0)
		return (-1);
	i = 0;
	if (!(save))
	{
		tmp = ft_strnew(1);
		tmp = ft_read_and_save(fd, tmp);
		*line = ft_linecopy(tmp);
		save = ft_savecpy(save, tmp);
		ft_strdel(&tmp);
		if (save == NULL)
			return (0);
		return (1);
	}
	tmp = ft_strdup(save);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
	{
		*line = ft_linecopy(tmp);
		save = ft_savecpy(save, tmp);
		ft_strdel(&tmp);
		return (1);
	}
	if (tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		ft_strdel(&save);
		return (0);
	}
	tmp = ft_read_and_save(fd, tmp);
	*line = ft_linecopy(tmp);
	save = ft_savecpy(save, tmp);
	ft_strdel(&tmp);
	return (1);
}

/*int		main(int argc, char **argv)
{
	char *str = NULL;
	int fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	//get_next_line(fd, &str);
	while (get_next_line(fd, &str) == 1)
		ft_putendl(str);
	//ft_putstr(str);
	close(fd);
	return (0);
}*/
