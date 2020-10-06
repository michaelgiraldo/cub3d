/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_blank.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:59:29 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/02/28 14:10:47 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_blank(char const *s)
{
	char		*new;
	char		*ptr;
	const char	*end;

	if (!s)
		return (NULL);
	while (*s && (ft_isblank(*s) || *s == 10))
		++s;
	if (!*s)
		return (ft_strnew(0));
	end = s + ft_strlen(s) - 1;
	while (ft_isblank(*end) || *end == 10)
		--end;
	new = ft_strnew(1 + end - s);
	if (!new)
		return (NULL);
	ptr = new;
	while (s <= end)
		*new++ = (char)*s++;
	return (ptr);
}
