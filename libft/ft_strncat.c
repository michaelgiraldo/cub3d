/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:03:51 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/02/27 12:19:22 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	size_t	len;

	ptr = s1;
	s1 += ft_strlen(s1);
	len = ft_strnlen(s2, n);
	s1[len] = '\0';
	ft_memmove(s1, s2, len);
	return (ptr);
}
