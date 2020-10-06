/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:12:36 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/02/28 17:11:53 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordcount(char const *s, char c)
{
	int		count;

	if (!*s || !c)
		return (0);
	count = 0;
	while (*s)
	{
		while ((*s == c) && *s)
			++s;
		if (*s)
			++count;
		while ((*s != c) && *s)
			++s;
	}
	return (count);
}
