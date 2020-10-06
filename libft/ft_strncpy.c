/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:44:33 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/03/01 13:57:55 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t src_len;

	src_len = ft_strnlen(src, len);
	if (src_len != len)
		ft_bzero(dst + src_len, len - src_len);
	ft_memmove(dst, src, src_len);
	return (dst);
}
