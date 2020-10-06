/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 08:01:46 by mg                #+#    #+#             */
/*   Updated: 2020/06/14 18:32:37 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  ft_strappend_xo (x = reallocated  o = unchanged)
**	dst is reallocated to fit dst and s2 strings
**	s2 remains unchanged and not freed
**	The string appended in order of dst + s2
*/

char	*ft_strappend_xo(char **dst, char *s2)
{
	ft_strrealloc(dst, ft_strlen(s2));
	ft_strcpy(*dst + ft_strlen(*dst), s2);
	return (*dst);
}

/*
**  ft_strappend_xo_chr (x = reallocated  o = unchanged)
**	dst is reallocated to fit dst and c2 chr
**	c2 remains unchanged and not freed
**	The string appended in order of dst + c2
*/

char	*ft_strappend_xo_chr(char **dst, char c2)
{
	ft_strrealloc(dst, 1);
	dst[0][ft_strlen(*dst)] = c2;
	return (*dst);
}

/*
**  ft_strappend_xx (x = reallocated  x = freed)
**	dst is reallocated to fit dst and s2 strings
**	s2 is freed
**	The string is appended in order of dst + s2
*/

char	*ft_strappend_xx(char **dst, char **s2)
{
	ft_strrealloc(dst, ft_strlen(*s2));
	ft_strcpy(*dst + ft_strlen(*dst), *s2);
	ft_strdel(s2);
	return (*dst);
}

/*
**  ft_strappend_ox (o = unchanged  x = reallocated)
**	s2 remains unchanged and not freed
**	dst is reallocated to fit dst and s2 strings
**	The string is appended in order of s2 + dst
*/

char	*ft_strappend_ox(char *s2, char **dst)
{
	char *new;

	if (!*dst || !s2)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(*dst) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(new, s2);
	ft_strcat(new, *dst);
	ft_strdel(dst);
	*dst = new;
	return (*dst);
}

/*
**  ft_strappend_oo (o = unchanged  o = unchanged)
**	dst is unchanged and not freed
**	s2 is unchanged and not freed
**	The string is appended in order of dst + s2
** 	for this use case use ft_strjoin
*/
