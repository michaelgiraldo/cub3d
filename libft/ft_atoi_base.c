/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiraldo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:15:06 by mgiraldo          #+#    #+#             */
/*   Updated: 2020/03/02 20:18:45 by mgiraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *s, int base)
{
	int			nflag;
	long int	nbr;

	nbr = 0;
	nflag = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
	{
		nflag = (*s == '-') ? -1 : 1;
		++s;
	}
	while (ft_isalnum_base(*s, base))
	{
		if (ft_isdigit(*s))
			nbr = nbr * base + *s - 48;
		else if (ft_isupper(*s))
			nbr = nbr * base + *s - 55;
		else if (ft_islower(*s))
			nbr = nbr * base + *s - 87;
		++s;
	}
	if (nbr < 0)
		nbr = (nflag == -1) ? 0 : -1;
	return (nbr * nflag);
}
