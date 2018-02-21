/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:14:32 by lchaillo          #+#    #+#             */
/*   Updated: 2018/02/21 10:23:55 by lchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	char			*save;
	struct s_gnl	*next;
	int				fd;
}				t_gnl;

#endif
