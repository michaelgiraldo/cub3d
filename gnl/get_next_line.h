/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:11:03 by jeslee            #+#    #+#             */
/*   Updated: 2020/10/06 01:06:39 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define FD_SIZE 256

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int	get_next_line(const int fd, char **line);
int	get_next_line_internal(const int fd, char **line);
int	gnl_free(char **as);

#endif
