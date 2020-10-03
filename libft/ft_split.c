/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:33:51 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/06/17 12:32:04 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c)
{
	char		**new;
	ssize_t		i;
	char		*end;

	if (!s ||
	(!(new = (char **)ft_memalloc(sizeof(char *) * (ft_wordcount(s, c) + 1)))))
		return (NULL);
	i = -1;
	while (*s)
	{
		while ((*s == c) && *s)
			++s;
		if (*s)
		{
			if (!(end = ft_strchr(s, c)))
				new[++i] = ft_substr(s, 0, ft_strlen(s));
			else
				new[++i] = ft_substr(s, 0, end - s);
		}
		while ((*s != c) && *s)
			++s;
	}
	new[++i] = NULL;
	return (new);
}
