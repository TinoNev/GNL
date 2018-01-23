/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:06:37 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/23 19:03:43 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_save(const int fd)
{
	int		i;
	int		ret;
	char	*tmp;
	char	buf[BUF_SIZE + 1];

	i = 0;
	tmp = ft_strnew(1);
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

int		ft_strnlen(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_linecopy(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strnew(ft_strnlen(tmp, '\n'));
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	return (line);
}

char	*ft_savecpy(char *save, char *tmp)
{
	int	i;
	int y;

	i = ft_strnlen(tmp, '\n') + 1;
	y = 0;
	save = ft_strnew(ft_strlen(tmp) - i);
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

	tmp = ft_read_and_save(fd);
	*line = ft_linecopy(tmp);
	save = ft_savecpy(save, tmp);
	return (1);
}

int		main(int argc, char **argv)
{
	char *str = NULL;
	int fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &str);
	/*while (get_next_line(fd, &str) == 1)
		ft_putstr(str);*/
	ft_putstr(str);
	close(fd);
	return (0);
}
