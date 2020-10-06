/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:49:53 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/02/20 21:21:46 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*char_ptr;
	char		r;

	char_ptr = (const char *)s + ft_strlen(s) - 1;
	r = (char)c;
	if (r == '\0')
		return ((void*)char_ptr + 1);
	while (*char_ptr != r && char_ptr - s > 0)
		--char_ptr;
	if (*char_ptr == r)
		return ((void *)char_ptr);
	return (NULL);
}
