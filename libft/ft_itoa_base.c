/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:24:16 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/05/14 13:57:07 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long int n, int b)
{
	char	*new;
	int		len;
	int		nflag;
	int		digit;

	len = ft_numlen_base(n, b);
	nflag = 0;
	if (n < 0 && b == 10)
		nflag = 1;
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		if (nflag && len == 0 && b == 10)
			new[len] = '-';
		else
		{
			digit = ft_abs(n % b);
			new[len] = (digit < 10) ? digit + 48 : digit + 55;
		}
		n /= b;
	}
	return (new);
}
