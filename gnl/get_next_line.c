/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:47:21 by mg                #+#    #+#             */
/*   Updated: 2020/10/06 01:08:51 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	return (get_next_line_internal(fd, line));
}

int	get_next_line_internal(const int fd, char **line)
{
	ssize_t		r;
	char		buf[BUFFER_SIZE + (r = 1)];
	static char	*x[FD_SIZE];
	char		*tmp;

	if (!x[fd] && !(x[fd] = ft_strnew(0)))
		return (-1 * gnl_free(&x[fd]));
	while (!ft_strchr(x[fd], '\n') && (r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		x[fd] = ft_strappend_xo(&x[fd], buf);
	}
	if (r == -1)
		return (-1 * gnl_free(&x[fd]));
	if (r > 0 && (tmp = x[fd]))
	{
		*line = ft_substr(x[fd], 0, (ft_strchr(x[fd], '\n') - x[fd]));
		x[fd] = ft_strdup(ft_strchr(x[fd], '\n') + 1);
		return (1 * gnl_free(&tmp));
	}
	*line = ft_strdup(x[fd]);
	if (!(*x[fd]))
		return (0 * gnl_free(&x[fd]));
	else
		return (1 * gnl_free(&x[fd]));
}

int	gnl_free(char **as)
{
	void **ap;

	ap = (void **)as;
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
		return (1);
	}
	return (0);
}
