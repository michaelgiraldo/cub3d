/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:08:15 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/05/24 15:44:37 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char			*nptr;
	unsigned int	nlen;

	nlen = ft_strlen(needle);
	if (!(needle && *needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (!(nptr = ft_strchr(haystack, *(needle + nlen - 1))))
			return (NULL);
		haystack = nptr - nlen + 1;
		if (*haystack == *needle)
			if (!ft_strncmp(haystack, needle, nlen - 1))
				return ((char *)haystack);
		haystack = nptr + 1;
	}
	return (NULL);
}
