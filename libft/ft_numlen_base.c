/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:36:15 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/05/14 14:59:13 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen_base(long long n, size_t base)
{
	if (n < 0 && base == 10)
		return (ft_numlen_base_unsigned(n * -1, base) + 1);
	else if (n < 0)
		return (ft_numlen_base_unsigned(n * -1, base));
	return (ft_numlen_base_unsigned(n, base));
}
