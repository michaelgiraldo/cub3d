/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:27:09 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/06/14 18:32:37 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Do you remember why you used memove verse strcpy
** ft_strcpy(newptr, *ptr);
** ft_memmove(newptr, *ptr, len);
*/

char	*ft_strrealloc(char **ptr, size_t size)
{
	char	*newptr;
	size_t	len;

	len = ft_strlen(*ptr);
	if (!size)
		size = 120;
	if (!(newptr = ft_strnew((len + size) * sizeof(char))))
		return (NULL);
	ft_strcpy(newptr, *ptr);
	free(*ptr);
	*ptr = newptr;
	return (newptr);
}
