/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:19:53 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/03/05 14:55:11 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*bptr;
	char			*nptr;
	unsigned int	nlen;

	nlen = ft_strlen(needle);
	bptr = (char *)haystack + len;
	if (!(needle && *needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (!(nptr = ft_strchr(haystack, *(needle + nlen - 1))) || nptr >= bptr)
			return (NULL);
		haystack = nptr - nlen + 1;
		if (*haystack == *needle)
			if (!ft_strncmp(haystack, needle, nlen - 1))
				return ((char *)haystack);
		haystack = nptr + 1;
	}
	return (NULL);
}
