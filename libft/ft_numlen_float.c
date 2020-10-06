/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 10:19:16 by mg                #+#    #+#             */
/*   Updated: 2020/06/22 13:40:25 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_numlen_float_(long double n)
{
	if (n >= 10)
		return (ft_numlen_float_(n / 10) + 1);
	return (1);
}

/*
** ft_numlen_float returns the length of the interger prortion of a float
*/

int			ft_numlen_float(long double n)
{
	n = (n < 0) ? n * -1 : n;
	return (ft_numlen_float_(n));
}
