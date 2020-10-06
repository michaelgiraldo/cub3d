/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:24:16 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/06/05 12:15:04 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_unsigned(unsigned long long int n, int b)
{
	char	*new;
	int		len;
	int		digit;

	len = ft_numlen_base_unsigned(n, b);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		digit = ft_abs(n % b);
		new[len] = (digit < 10) ? digit + 48 : digit + 55;
		n /= b;
	}
	return (new);
}
