/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:41:16 by mg                #+#    #+#             */
/*   Updated: 2020/06/22 13:38:56 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://stackoverflow.com/questions/9138790/cant-use-modulus-on-doubles
** https://en.cppreference.com/w/cpp/numeric/math/fmod
*/

long double	ft_ldmod(long double x, long double y)
{
	x = x < 0 ? x * -1 : x;
	y = y < 0 ? y * -1 : y;
	return (x - (unsigned long long int)(x / y) * y);
}

int			ft_round_half_to_even(long double nbr, int precision)
{
	size_t is_even;
	size_t is_half;

	nbr = ft_ldmod(nbr * ft_pow(10, precision), 2);
	is_even = ((int)nbr == 0);
	if (is_even)
	{
		is_half = (nbr >= 0.49 && nbr <= 0.5);
		if (is_half)
			return (1);
	}
	return (0);
}

/*
** This function is written in support of ft_dtoa and
** performance the arthemic of adding 0.5 e.g. (1.6 + 0.5 = 2.1)
** returns 2.1 not the correctly round number 2.0
** ft_dtoa will take the step to turn 2.1 into 2.0
** further enchacements to this function are for a future project (June 2020)
**
** For future reference
** https://git.musl-libc.org/cgit/musl/tree/src/math/modf.c
*/

long double	ft_dtoa_round(long double nbr, int precision)
{
	size_t half_to_even;

	half_to_even = ft_round_half_to_even(nbr, precision);
	if (half_to_even)
		;
	else if (nbr > 0)
		nbr = nbr + (ft_pow(10, -precision - 1) * 5.0);
	else if (nbr < 0)
		nbr = nbr - (ft_pow(10, -precision - 1) * 5.0);
	return (nbr);
}

char		*ft_dtoa(long double d, size_t p, size_t base)
{
	long double				a;
	char					*ptr1;
	char					*ptr2;

	a = (d < 0) ? (ft_dtoa_round(d, p) * -1) : ft_dtoa_round(d, p);
	ptr1 = ft_itoa_base_unsigned((unsigned long long int)a, base);
	a = (a - (unsigned long long int)a) * ft_pow(base, p);
	ptr2 = ft_itoa_base_unsigned(a, base);
	if ((a = ft_strlen(ptr2)) != p)
		while (a++ < p)
			ft_strappend_ox("0", &ptr2);
	if (d < 0 && base == 10)
		ft_strappend_ox("-", &ptr1);
	if (p > 0 && base == 10)
	{
		ft_strappend_xo(&ptr1, ".");
		ft_strappend_xx(&ptr1, &ptr2);
	}
	else
		ft_strdel(&ptr2);
	return (ptr1);
}
