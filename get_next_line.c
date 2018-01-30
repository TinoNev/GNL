/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:07:36 by lchaillo          #+#    #+#             */
/*   Updated: 2018/01/30 19:24:06 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_linecopy(char *save)
{
	int		i;
	char	*line;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	line = ft_strsub(save, 0, i);
	return (line);
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
	if (tmp[i] != '\0')
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
	char	buf[BUFF_SIZE + 1];
	char	*ptr;

	save == NULL ? ret = read(fd, buf, BUFF_SIZE) : 0;
	save == NULL ? buf[ret] = '\0' : 0;
	save == NULL ? save = ft_strdup(buf) : 0;
	i = 0;
	while (save[i] != '\n' && ret != 0)
	{
		if (save[i] == '\0')
		{
			ret = read(fd, buf, BUFF_SIZE);
			buf[ret] = '\0';
			ptr = save;
			save = ft_strjoin(save, buf);
			ft_strdel(&ptr);
			i = -1;
		}
		i++;
	}
	return (save);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*save =  NULL;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	save = ft_read_save(save, fd);
	//return (0);
	if (save[0] == '\0')
	{
		ft_strdel(&save);
		return (0);
	}
	*line = ft_linecopy(save);
	save = ft_savesplit(save);
	return (1);
}

/*int main(int argc, char **argv)
{
	char *line;
	int fd;
	char *temp;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			temp = line;
			ft_putendl(line);
			ft_strdel(&temp);
		}
		ft_strdel(&line);
		close(fd);
		fd2 = open(argv[2], O_RDONLY);
		while (get_next_line(fd2, &line) == 1)
		{
			temp = line;
			ft_putendl(line);
			ft_strdel(&temp);
		}
		//ft_strdel(&line);
		close(fd2);
	}
	//while (1);
	return (0);
}*/
