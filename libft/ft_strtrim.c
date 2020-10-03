/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:59:29 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/04/15 17:17:50 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_totrim(char c, char const *set)
{
	char const	*ptr;

	ptr = set;
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	ptr = set;
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	char		*ptr;
	const char	*end;

	if (!s1)
		return (NULL);
	while (*s1 && ft_totrim(*s1, set))
		++s1;
	if (!*s1)
		return (ft_strnew(0));
	end = s1 + ft_strlen(s1) - 1;
	while (ft_totrim(*end, set))
		--end;
	new = ft_strnew(1 + (end - s1));
	if (!new)
		return (NULL);
	ptr = new;
	while (s1 <= end)
		*new++ = (char)*s1++;
	return (ptr);
}
