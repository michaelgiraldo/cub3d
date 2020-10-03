/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:54:27 by mg                #+#    #+#             */
/*   Updated: 2020/06/17 18:05:06 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The pow() function returns the value of x raised to the power of y
** https://linux.die.net/man/3/pow
*/

long double	ft_pow(long double n, int pow)
{
	if (pow < 0)
		return (1 / ft_pow(n, ft_abs(pow)));
	else
		return (pow ? n * ft_pow(n, pow - 1) : 1);
}
