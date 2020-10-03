/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcountx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:29:48 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/02/28 17:10:59 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if ft_checkx can replaced with ft_strstr function
*/

static int	ft_checkx(char s, char *c)
{
	while (*c)
	{
		if (s == *c)
			return (1);
		++c;
	}
	return (0);
}

int			ft_wordcountx(char const *s, char *c)
{
	int		count;

	if (!s || !*c)
		return (0);
	count = 0;
	while (*s)
	{
		while (ft_checkx(*s, c) && *s)
			++s;
		if (*s)
			++count;
		while (!ft_checkx(*s, c) && *s)
			++s;
	}
	return (count);
}
