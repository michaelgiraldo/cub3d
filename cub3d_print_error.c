/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_print_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:39:33 by mg                #+#    #+#             */
/*   Updated: 2020/10/07 23:03:43 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** stderr = standard error = 2
*/

void	c3d_print_error_sys(t_param *cub3d, char *msg)
{
	perror(msg);
	c3d_free_memory(cub3d);
}

void	c3d_print_error(t_param *cub3d, char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	c3d_free_memory(cub3d);
}
