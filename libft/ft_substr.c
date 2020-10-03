/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:51:20 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/03/02 19:45:58 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s || (long int)len < 0)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(new, s + start, len));
}
