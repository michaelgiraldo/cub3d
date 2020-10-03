/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:35:53 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/03/01 15:29:07 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t size;

	if (!dst && !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	size = ft_strlen(src);
	if (size < dstsize)
		ft_strcpy(dst, src);
	else
		ft_strncpy(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (size);
}
