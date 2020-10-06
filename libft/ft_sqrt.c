/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 10:19:23 by mg                #+#    #+#             */
/*   Updated: 2020/06/14 18:32:37 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** source
** https://github.com/PraveenVignesh/sqrt/blob/master/sqrt_newton_raphson.c
** https://mathworld.wolfram.com/ExponentLaws.html
*/

static long double	ft_sqroot(long double x, long double n)
{
	long double t;
	long double c;

	t = ((x * x) + n) / (2 * x);
	c = ((t * t) + n) / (2 * t);
	if (t == x || c == x)
		return (t);
	else
		return (ft_sqroot(t, n));
}

long double			ft_sqrt(long double n)
{
	return (ft_sqroot(n / 2, n));
}
