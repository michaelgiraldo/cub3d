/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:17:31 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/03/02 12:37:11 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	void *char_ptr;

	if (!dst && !src)
		return (NULL);
	char_ptr = ft_memchr(src, c, n);
	if (char_ptr != NULL)
		return (ft_mempcpy(dst, src, char_ptr - src + 1));
	ft_memmove(dst, src, n);
	return (NULL);
}
